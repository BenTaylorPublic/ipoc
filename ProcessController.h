#pragma once
#include <string>
#include "InputController.h"
#include "OutputController.h"
#include "Storage.h"
#include "Frame.h"
#include "ThreadManager.h"
#include "OnscreenButtonManager.h"

class ProcessController {
public:
    ProcessController();
    ~ProcessController();
    void IPOCLoad(InputController* inputControllerPtr, OnscreenButtonManager* inputOnscreenButtonManager, Frame* inputFrame, OutputController* outputControllerPtr);
    void load(); //Program specific, called just before the start of the loop. Load textures and such in here
    void process();
    bool checkForExitProgram();
    void incrementLoopNumber();
    std::string getStatusString();
private:
    Frame* frame;
    bool exitProgram;
    unsigned int loopNumber;
    InputController* ic;
    OutputController* oc;
    OnscreenButtonManager* obm;
    Storage storage;
    ThreadManager tm;
};