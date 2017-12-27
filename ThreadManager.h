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
    void loadGlobalStart();
    void loadGlobalJoin();
    std::atomic<bool> loadGlobalJoinable{false};

    //unloadGlobal
    void unloadGlobalStart();
    void unloadGlobalJoin();
    std::atomic<bool> unloadGlobalJoinable{false};
    
    //loadButtonTesting
    void loadButtonTestingStart();
    void loadButtonTestingJoin();
    std::atomic<bool> loadButtonTestingJoinable{false};
    
    //unloadButtonTesting
    void unloadButtonTestingStart();
    void unloadButtonTestingJoin();
    std::atomic<bool> unloadButtonTestingJoinable{false};
    
    //loadShapeFun
    void loadShapeFunStart();
    void loadShapeFunJoin();
    std::atomic<bool> loadShapeFunJoinable{false};
    
    //unloadoadShapeFun
    void unloadShapeFunStart();
    void unloadShapeFunJoin();
    std::atomic<bool> unloadShapeFunJoinable{false};

private:
    Storage* storage;
    Frame* frame;
    InputController* inputController;
    DecimatedProcessHandler* decimatedProcessHandler;
    
    //loadGlobal
    void loadGlobal();
    std::thread* loadGlobalThread;

    //unloadGlobal
    void unloadGlobal();
    std::thread* unloadGlobalThread;
    
    //loadButtonTesting
    void loadButtonTesting();
    std::thread* loadButtonTestingThread;
    
    //unloadButtonTesting
    void unloadButtonTesting();
    std::thread* unloadButtonTestingThread;
    
    //loadShapeFun
    void loadShapeFun();
    std::thread* loadShapeFunThread;
    
    //unloadShapeFun
    void unloadShapeFun();
    std::thread* unloadShapeFunThread;

};