#pragma once

#include <string>
#include <thread>
#include <atomic>
#include "Storage.h"
#include "Frame.h"
#include "OnscreenButtonManager.h"

class ThreadManager {
public:
    ThreadManager();
    ~ThreadManager();
    void IPOCLoad(Storage* inputStorage, Frame* inputFrame, OnscreenButtonManager* inputOnscreenButtonManager);
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
    OnscreenButtonManager* onscreenButtonManager;

    //loadMainMenu
    void loadMainMenu();
    std::thread* loadMainMenuThread;

    //exitCleanUp
    void exitCleanUp();
    std::thread* exitCleanUpThread;

};