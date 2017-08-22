#pragma once
#include <string>
#include "InputController.h"
#include "OutputController.h"
#include "Storage.h"
#include "Frame.h"
#include "ThreadManager.h"

class ProcessController {
public:
    ProcessController();
    ~ProcessController();
    void IPOCLoad(InputController* inputControllerPtr, Frame* inputFrame, OutputController* outputControllerPtr);
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
    Storage storage;
    ThreadManager tm;
};