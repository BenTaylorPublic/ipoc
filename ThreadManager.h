#pragma once

#include <string>
#include <thread>
#include "Storage.h"
#include "IPOCFrame.h"
#include "OnscreenButtonManager.h"

class ThreadManager
{
public:
    ThreadManager();
    ~ThreadManager();
    void IPOCLoad(Storage* inputStorage, IPOCFrame* inputFrame, OnscreenButtonManager* inputOnscreenButtonManager);
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
    IPOCFrame* frame;
    OnscreenButtonManager* onscreenButtonManager;
    
    //loadMainMenu
    void loadMainMenuThread();
    thread* loadMainMenu;
    
    //exitCleanUp
    void exitCleanUpThread(const ProgramState& exitingFrom);
    thread* exitCleanUp;
    
};