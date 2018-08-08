#include "ThreadManager.h"
#include "Debug.h"
#include "Settings.h"
#include "Color.h"

ThreadManager::ThreadManager()
{
}

ThreadManager::~ThreadManager()
{
}

void ThreadManager::IPOCLoad(Storage* inputStorage,
							 Frame* inputFrame,
							 InputController* inputInputController,
							 DecimatedProcessHandler* inputDecimatedProcessHandler)
{
	storage = inputStorage;
	frame = inputFrame;
	inputController = inputInputController;
	decimatedProcessHandler = inputDecimatedProcessHandler;
}

std::string ThreadManager::getStatusString() const
{
	return "N/A";
}

/*
 * ========================================================
 * BEGIN PROGRAM SPECIFC THREADS
 * ========================================================
 */