#pragma once
#include <string>
#include "InputController.h"
#include "ProcessController.h"
#include "OutputController.h"
#include "Frame.h"
#include "DecimatedProcessHandler.h"
#include <thread>
#include <atomic>

class MasterController {
public:
    MasterController();
    std::string getStatusString();
    void IPOCLoad();
    void start();
private:
    InputController* inputController;
    ProcessController* processController;
    OutputController* outputController;
    Frame* frame;
    DecimatedProcessHandler* decimatedProcessHandler;

    std::thread inputThread;
    std::thread processThread;
    std::atomic<bool> inputThreadJoinable;
    std::atomic<bool> processThreadJoinable;

    std::atomic<bool> threadsLoaded;
    void inputLoop(); //Called by the inputThread. The inputLoop continuously checks user input
    void processLoop(); //Called by the outputThread. The outputLoop continuously renders/draws to the screen
    void onscreenButtonLoop(); //Called by the onscreenButtonsThread. The onscreenButtonLoop continuously checks if the onscreen buttons are triggered
    /*
    Method that is called on program exit. 
    It is assumed at this point, that the ProgramSpecific saving/closing has been done, and that IPOC is allowed to close input and output threads, and the graphics window.
     */
    void exit();
};