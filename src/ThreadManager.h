#pragma once

#include <string>
#include <thread>
#include <atomic>
#include "Storage.h"
#include "Frame.h"
#include "InputController.h"
#include "DecimatedProcessHandler.h"

class ThreadManager {
public:
    ThreadManager();
    ~ThreadManager();
    void IPOCLoad(Storage* inputStorage, Frame* inputFrame, InputController* inputInputController, DecimatedProcessHandler* inputDecimatedProcessHandler);
    std::string getStatusString() const;

    //loadGlobal
    //void loadGlobalStart();
    //void loadGlobalJoin();
    //std::atomic<bool> loadGlobalJoinable{false};

private:
    Storage* storage;
    Frame* frame;
    InputController* inputController;
    DecimatedProcessHandler* decimatedProcessHandler;

    //loadGlobal
    //void loadGlobal();
    //std::thread* loadGlobalThread;

};