#pragma once
#include <string>
#include "InputController.h"
#include "Storage.h"
#include "Frame.h"
#include "ThreadManager.h"
#include "OnscreenButtonManager.h"

class ProcessController
{
public:
    ProcessController();
    ~ProcessController();
    void IPOCLoad(InputController* inputControllerPtr, OnscreenButtonManager* inputOnscreenButtonManager, Frame* inputFrame);
    void load();//Program specific, called just before the start of the loop. Load textures and such in here
    void process();
    bool checkForExitProgram();
    void incrementLoopNumber();
    std::string getStatusString();
private:
    Frame* frame;
    bool exitProgram;
    int loopNumber;
    InputController* inputController;
    OnscreenButtonManager* onscreenButtonManager;
    Storage storage;
    ThreadManager threadManager;
};