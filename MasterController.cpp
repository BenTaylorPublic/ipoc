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
    Settings::loadSettings();
    Debug::newLog();
    Debug::log("[INFO] Launching IPOC V");
    Debug::log(Settings::ipocVersion);
    Debug::commitLogLine();
    Debug::log("[INFO] File path: ");
    Debug::log(Settings::filePath);
    Debug::commitLogLine();
    Debug::log("[INFO] Loaded settings");
    Debug::commitLogLine();

    Debug::setMasterController(this);

    inputController->IPOCLoad();
    processController->IPOCLoad(inputController, onscreenButtonManager, frame);
    outputController->IPOCLoad(frame);
    onscreenButtonManager->IPOCLoad(inputController);
    frame->IPOCLoad();

    Debug::log("[INFO] Loaded controllers");
    Debug::commitLogLine();

    inputThread = thread(&MasterController::inputLoop, this);

    //while (!threadsLoaded); //Wait until both threads are loaded
    Debug::log("[INFO] Loaded I/O threads");
    Debug::commitLogLine();
    Debug::log("[INFO] -------------------------------------------------------START OF PS LOAD: ");
    Debug::logTimeStamp();
    Debug::commitLogLine();
    processController->load();
    Debug::log("[INFO] -------------------------------------------------------END OF PS LOAD: ");
    Debug::logTimeStamp();
    Debug::commitLogLine();
}

void MasterController::start() 
{
    processThread = thread(&MasterController::processLoop, this);
    
    //Open graphics window
    outputController->createGraphicsWindow(inputController);

    //That's all the loading required, setting the bool so the program can start
    threadsLoaded = true;
    while (!processController->checkForExitProgram()) 
    {
        outputController->output();
    }
}

void MasterController::inputLoop() 
{
    //Input thread requires no loading
    //Wait until output thread is loaded
    while (!threadsLoaded);

    while (!processController->checkForExitProgram()) 
    {
        inputController->input();
    }
}

void MasterController::processLoop() 
{
    //Initial writing to console
    Debug::log("[INFO] -------------------------------------------------------START OF LOOP: ");
    Debug::logTimeStamp();
    Debug::commitLogLine();

    //Calculating loop time
    chrono::nanoseconds nanosecondsPerLoop(1000000000 / Settings::loopsPerSecond);
    chrono::system_clock::time_point startOfLoopTime;

    startOfLoopTime = chrono::system_clock::now(); //Current time
    while (!processController->checkForExitProgram()) 
    {
#ifdef WINDOWS
        startOfLoopTime += nanosecondsPerLoop; //Current time
#else
        startOfLoopTime = chrono::system_clock::now();
#endif

        //Increment both loop numbers (stored in 2 locations, for debugging)
        //I don't know if that's smart or really dumb
        //But alteast the Debug class knows the loop number without having to point to the ProcessController
        Debug::incrementLoopNumber();
        processController->incrementLoopNumber();

        inputController->markStartOfLoop();
        onscreenButtonManager->markStartOfLoop();
        processController->process(); //Executes all program specific code
        onscreenButtonManager->markEndOfLoop();
        frame->markAsDrawable();
        inputController->markEndOfLoop();

        //Checks if the loop went overtime
        if (chrono::system_clock::now() >= (startOfLoopTime + nanosecondsPerLoop)) 
        {
            //If it did, log and write a warning
            Debug::write("[WARN] Loop went over time frame\n");
            Debug::log("[WARN] Overtime in loop ");
            Debug::logLoopNumber();
            Debug::commitLogLine();
        } else 
        {
            //Otherwise sleep until the next loop is required
            this_thread::sleep_until(startOfLoopTime + nanosecondsPerLoop);
        }
    }

    //End of program statements
    Debug::log("[INFO] -------------------------------------------------------END OF LOOP: ");
    Debug::logTimeStamp();
    Debug::commitLogLine();

    exit();
}

void MasterController::exit() 
{
    //Program specific saving should be done by now, and the input + output should have ended
    //Just need to close the window, and join the threads
    outputController->closeGraphicsWindow();
    inputThread.join();
    processThread.join();
    //Finally log that everything went well
    Debug::log("[INFO] Successfully ended threads");
    Debug::commitLogLine();
    delete inputController;
    delete processController;
    delete outputController;
    delete onscreenButtonManager;
    delete frame;

    if (Settings::logClassAmountInfo)
        Debug::logClassAmountInfo(); //Log all info
    else
        Debug::logMemoryLeakInfo(); //Only log if there was a leak

    Debug::log("[INFO] Program ended successfully.");
    Debug::commitLogLine();
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