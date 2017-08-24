#pragma once

#include <string>
#include <thread>
#include <atomic>
#include "Storage.h"
#include "Frame.h"
#include "InputController.h"

class ThreadManager {
public:
    ThreadManager();
    ~ThreadManager();
    void IPOCLoad(Storage* inputStorage, Frame* inputFrame, InputController* inputController);
    std::string getStatusString();

    //loadMainMenu
    void loadMainMenuStart();
    void loadMainMenuJoin();
    std::atomic<bool> loadMainMenuJoinable;

    //exitCleanUp
    void exitCleanUpStart();
    void exitCleanUpJoin();
    std::atomic<bool> exitCleanUpJoinable;

private:
    Storage* storage;
    Frame* frame;
    InputController* inputController;
    
    //loadMainMenu
    void loadMainMenu();
    std::thread* loadMainMenuThread;

    //exitCleanUp
    void exitCleanUp();
    std::thread* exitCleanUpThread;

};