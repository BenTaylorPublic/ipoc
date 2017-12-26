#pragma once
#include <string>
#include "InputController.h"
#include "OutputController.h"
#include "Storage.h"
#include "Frame.h"
#include "ThreadManager.h"
#include "DecimatedProcessHandler.h"

class ProcessController {
public:
    ProcessController();
    ~ProcessController();
    void IPOCLoad(InputController* inputControllerPtr, Frame* inputFrame, OutputController* outputControllerPtr, DecimatedProcessHandler* decimatedProcessHandler, Storage* storagePtr);
    void load(); //Program specific, called just before the start of the loop. Load textures and such in here
    void process();
    bool checkForExitProgram();
    void incrementLoopNumber();
    std::string getStatusString();
    //Program specific methods below
    void global();
    void exiting();
    void buttonTestingSafe();
    void shapeFunSafe();
private:
    Frame* frame;
    bool exitProgram;
    unsigned int loopNumber;
    InputController* inputController;
    OutputController* outputController;
    DecimatedProcessHandler* decimatedProcessHandler;
    Storage* storage;
    ThreadManager threadManager;
};