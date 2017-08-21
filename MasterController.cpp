#include "MasterController.h"
#include "Settings.h"
#include "Debug.h"
#include "FileManager.h"
#include "Conversions.h"
#include <chrono>

MasterController::MasterController()
{
}

void MasterController::IPOCLoad()
{
    inputController = new InputController();
    processController = new ProcessController();
    outputController = new OutputController();
    onscreenButtonManager = new OnscreenButtonManager();
    frame = new Frame();


    threadsLoaded = false;
    inputThreadJoinable = false;
    processThreadJoinable = false;

    Settings::loadSettings();
    Debug::newLog();
    Debug::log("[INFO] Launching IPOC V");
    Debug::log(Settings::ipocVersion + "\n");
    Debug::log("[INFO] File path: ");
    Debug::log(Settings::filePath + "\n");
    Debug::log("[INFO] Loaded settings\n");

    Debug::IPOCLoad(this);

    inputController->IPOCLoad();
    processController->IPOCLoad(inputController, onscreenButtonManager, frame, outputController);
    outputController->IPOCLoad(frame);
    onscreenButtonManager->IPOCLoad(inputController);
    frame->IPOCLoad();

    Debug::log("[INFO] Loaded controllers\n");

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
    std::chrono::nanoseconds nanosecondsPerLoop(1000000000 / Settings::loopsPerSecond);
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

	inputController->markStartOfLoop();
	onscreenButtonManager->markStartOfLoop();
	
	processController->process(); //Executes all program specific code
	
	onscreenButtonManager->markEndOfLoop();
	frame->markAsDrawable();
	inputController->markEndOfLoop();

	if (Settings::debugMode)
	{
	    Debug::noteLoopTime((std::chrono::high_resolution_clock::now() - startOfLoopTime).count());
	}

	//Checks if the loop went overtime
	if (std::chrono::high_resolution_clock::now() >= (startOfLoopTime + nanosecondsPerLoop))
	{

	    //If it did, log and write a warning
	    Debug::write("[WARN] Loop went over time frame " +std::to_string(loopNumber) + "\n");
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
    Debug::log("[INFO] Ended process thread\n");

    while (!inputThreadJoinable);
    inputThread.join();
    Debug::log("[INFO] Ended input thread\n");

    //Program specific saving should be done by now, and the input + output should have ended
    //Just need to close the window, and join the threads
    outputController->closeGraphicsWindow();

    delete inputController;
    delete processController;
    delete outputController;
    delete onscreenButtonManager;
    delete frame;

    if (Settings::logClassAmountInfo)
	Debug::logClassAmountInfo(); //Log all info
    else
	Debug::logMemoryLeakInfo(); //Only log if there was a leak

    Debug::log("[INFO] Program ended successfully.\n");

}

std::string MasterController::getStatusString()
{
    //Calling all objects it has a pointer too
    std::string result = "Master Controller:\n";
    result += inputController->getStatusString();
    result += processController->getStatusString();
    result += outputController->getStatusString();
    result += Settings::getStatusString();
    result += FileManager::getStatusString();
    result += Conversions::getStatusString();

    return result;
}