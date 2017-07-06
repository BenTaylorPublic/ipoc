#pragma once

#include <string>
#include <thread>
#include "Storage.h"
#include "Frame.h"
#include "OnscreenButtonManager.h"

class ThreadManager
{
public:
    ThreadManager();
    ~ThreadManager();
    void IPOCLoad(Storage* inputStorage, Frame* inputFrame, OnscreenButtonManager* inputOnscreenButtonManager);
    std::string getStatusString();
    
    //loadMainMenu
    void loadMainMenuStart();
    void loadMainMenuJoin();
    bool loadMainMenuJoinable();
    
    //exitCleanUp
    void exitCleanUpStart(const ProgramState& inputExitingFrom);
    void exitCleanUpJoin();
    bool exitCleanUpJoinable();    
    
private:
    Storage* storage;
    Frame* frame;
    OnscreenButtonManager* onscreenButtonManager;
    
    //loadMainMenu
    void loadMainMenuThread();
    std::thread* loadMainMenu;
    
    //exitCleanUp
    void exitCleanUpThread(const ProgramState& exitingFrom);
    std::thread* exitCleanUp;
    
};