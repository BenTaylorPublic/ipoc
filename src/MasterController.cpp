#include "MasterController.h"
#include "IPOCSettings.h"
#include "Settings.h"
#include "Debug.h"
#include "FileManager.h"
#include "Conversions.h"
#include <chrono>
#include "TrackedClasses.h"

MasterController::MasterController()
{
}

std::string MasterController::getStatusString() const
{
	//Calling all objects it has a pointer too
	std::string result = "Master Controller:\n";
	result += inputController->getStatusString();
	result += processController->getStatusString();
	result += outputController->getStatusString();
	result += Settings::getStatusString();
	result += FileManager::getStatusString();

	return result;
}

void MasterController::IPOCLoad()
{
	//To seed random numbers across the whole application
	srand(time(NULL));

	inputController = new InputController();
	processController = new ProcessController();
	outputController = new OutputController();
	frame = new Frame();
	decimatedProcessHandler = new DecimatedProcessHandler();
	storage = new Storage();

	threadsLoaded = false;
	inputThreadJoinable = false;
	processThreadJoinable = false;

	Settings::loadSettings();
	Debug::logLine("[INFO] Launching IPOC V" + std::string(IPOC_VERSION));
	Debug::logLine("[INFO] File path: " + Settings::filePath);
	Debug::logLine("[INFO] Loaded settings");

	Debug::IPOCLoad(this);

	inputController->IPOCLoad();
	processController->IPOCLoad(inputController, frame, outputController, decimatedProcessHandler, storage);
	outputController->IPOCLoad(frame);
	frame->IPOCLoad();
	decimatedProcessHandler->IPOCLoad();
	TrackedClasses::loadClassNames();

	Debug::logLine("[INFO] Loaded controllers");

	inputThread = std::thread(&MasterController::inputLoop, this);

	Debug::log("[INFO] -------------------------------------------------------START OF PS LOAD: ");
	Debug::logTimeStamp();
	Debug::log("\n");

	processController->load();

	Debug::log("[INFO] -------------------------------------------------------END OF PS LOAD: ");
	Debug::logTimeStamp();
	Debug::log("\n");
}

void MasterController::start()
{

	processThread = std::thread(&MasterController::processLoop, this);

	//Open graphics window
	outputController->createGraphicsWindow(inputController);

	//That's all the loading required, setting the bool so the program can start
	threadsLoaded = true;
	while (!processController->checkForExitProgram())
	{
		outputController->output();
	}

	exit();
}

void MasterController::inputLoop()
{

	//Input thread requires no loading
	//Wait until output thread is loaded
	while (!threadsLoaded);

	while (!processController->checkForExitProgram())
	{
		if (Settings::inputStatus == Active)
		{
			inputController->input();
		} else
		{
			if (Settings::inputStatus == PauseRequested)
			{
				Settings::inputStatus = Paused;
			}
			//If it's paused, do nothing
		}
	}

	inputThreadJoinable = true;

}

void MasterController::processLoop()
{
	unsigned int loopNumber = 0;
	//Calculating loop time
	std::chrono::nanoseconds nanosecondsPerLoop(LOOP_TIME_IN_NANOSECONDS);
	std::chrono::high_resolution_clock::time_point startOfLoopTime;

	//Initial writing to console
	Debug::log("[INFO] -------------------------------------------------------START OF LOOP: ");
	Debug::logTimeStamp();
	Debug::log("\n");

	startOfLoopTime = std::chrono::high_resolution_clock::now() - nanosecondsPerLoop; //Current time
	while (!processController->checkForExitProgram())
	{
		startOfLoopTime += nanosecondsPerLoop; //Current time

		//Increment both loop numbers (stored in 2 locations, for debugging)
		//I don't know if that's smart or really dumb
		//But alteast the Debug class knows the loop number without having to point to the ProcessController
		Debug::incrementLoopNumber();
		processController->incrementLoopNumber();
		loopNumber++;

		decimatedProcessHandler->markStartOfLoop();

		inputController->markStartOfLoop();

		processController->process(); //Executes all program specific code

		inputController->markEndOfLoop();

		decimatedProcessHandler->markEndOfLoop();

		frame->markAsDrawable();

		//Checks if the loop went overtime
		if (std::chrono::high_resolution_clock::now() >= (startOfLoopTime + nanosecondsPerLoop))
		{

			//If it did, log and write a warning
			Debug::writeLine("[WARN] Loop went over time frame " + std::to_string(loopNumber));
			Debug::log("[WARN] Overtime in loop ");
			Debug::logLoopNumber();
			Debug::log("\n");
		} else
		{
			//Otherwise sleep until the next loop is required
			std::this_thread::sleep_until(startOfLoopTime + nanosecondsPerLoop);
		}
	}

	//End of program statements
	Debug::log("[INFO] -------------------------------------------------------END OF LOOP: ");
	Debug::logTimeStamp();
	Debug::log("\n");

	processThreadJoinable = true;
}

void MasterController::exit()
{
	while (!processThreadJoinable);
	processThread.join();
	Debug::logLine("[INFO] Ended process thread");

	while (!inputThreadJoinable);
	inputThread.join();
	Debug::logLine("[INFO] Ended input thread");

	//Program specific saving should be done by now, and the input + output should have ended
	//Just need to close the window, and join the threads
	outputController->closeGraphicsWindow();

	delete inputController;
	delete processController;
	delete outputController;
	delete frame;
	delete storage;

	if (LOG_CLASS_AMOUNT_INFO)
		Debug::logClassAmountInfo(); //Log all info
	else
		Debug::logMemoryLeakInfo(); //Only log if there was a leak

	Debug::logLine("[INFO] Program ended successfully.");

}