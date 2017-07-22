#include "Debug.h"
#include <iostream>
#include "Settings.h"
#include "FileManager.h"
#include <time.h>
#include "MasterController.h"
#include <chrono>

//Defaults
int Debug::loopNumber = 0;
MasterController* Debug::masterController = nullptr;
std::string Debug::logPath = "blank";

int Debug::constructionAmount[AMOUNT_OF_CLASSES] = {0};
int Debug::destructionAmount[AMOUNT_OF_CLASSES] = {0};
int Debug::copyAmount[AMOUNT_OF_CLASSES] = {0};

void Debug::write(const int& input)
{
    std::cout << input;
}

void Debug::write(const std::string& input)
{
    std::cout << input;
}

void Debug::writeLoopNumber()
{
    std::cout << loopNumber;
}

void Debug::log(const int& input)
{
    FileManager::writeToFile(logPath, input);
}

void Debug::log(const std::string& input)
{
    FileManager::writeToFile(logPath, input);
}

void Debug::logLoopNumber()
{
    FileManager::writeToFile(logPath, loopNumber);
}

void Debug::newLog()
{
    FileManager::clearFile(logPath);
}

void Debug::logTimeStamp()
{
    time_t now = time(0);
    std::string timeStamp = "";
    timeStamp = ctime(&now);
    timeStamp.pop_back();
    FileManager::writeToFile(logPath, timeStamp);
}

void Debug::incrementLoopNumber()
{
    loopNumber++;
}

void Debug::setMasterController(MasterController* input)
{
    masterController = input;
}

void Debug::logStatusStrings()
{
    FileManager::writeToFile(logPath, masterController->getStatusString());
}

void Debug::setFilePath(std::string inputPath)
{
    logPath = inputPath + "DebugLog.txt";
}

void Debug::notifyOfConstruction(const int& classId)
{
    constructionAmount[classId]++;
}

void Debug::notifyOfDestruction(const int& classId)
{
    destructionAmount[classId]++;
}

void Debug::notifyOfCopy(const int& classId)
{
    copyAmount[classId]++;
}

void Debug::crash(const int& crashId, const std::string& callFrom)
{
    write("[CRASH] Program crashed. Crash ID " + std::to_string(crashId) + ".\n");
    write("[CRASH] Crash called from " + callFrom + "\n");
    write("[CRASH] Crashed on loop " + std::to_string(loopNumber));
    log("[CRASH] Program crashed. Crash ID " + std::to_string(crashId) + ".\n");
    log("[CRASH] Crash called from " + callFrom + "\n");
    log("[CRASH] Crashed on loop " + std::to_string(loopNumber) + "\n");
    exit(EXIT_FAILURE);

    /*
     * CrashID summary
     * 103: Frame.addToFrame()
     * 104: Settings.getIntFromSettings()
     * 105: Settings.getStringFromSettings()
     * 106: Settings.getBoolFromSettings() 
     */

}

void Debug::logClassAmountInfo()
{
    log("[INFO] Logging class amount info\n");

    log("[INFO] ClassID 0, our benevolent overlord is exempt from this blasphemous scrutiny.\n");

    for (int i = 1; i < AMOUNT_OF_CLASSES; i++)
    {
	log("[INFO] ");
	if (constructionAmount[i] + copyAmount[i] != destructionAmount[i])
	{
	    log("MEMORY LEAK, ");
	}
	log("ClassID " + std::to_string(i) + ", constructed " + std::to_string(constructionAmount[i]) + ", copied " + std::to_string(copyAmount[i]) + ", destructed " + std::to_string(destructionAmount[i]) + ".\n");
    }

    log("[INFO] End of class amount info\n");
}

void Debug::logMemoryLeakInfo()
{
    int totalConstructionAmount = 0;
    for (const int& amount : constructionAmount)
    {
	totalConstructionAmount += amount;
    }

    int totalDestructionAmount = 0;
    for (const int& amount : destructionAmount)
    {
	totalDestructionAmount += amount;
    }

    int totalCopyAmount = 0;
    for (const int& amount : copyAmount)
    {
	totalCopyAmount += amount;
    }

    if (totalConstructionAmount + totalCopyAmount == totalDestructionAmount)
    {
	log("[INFO] No memory leaks detected\n");
    } else
    {
	log("[WARNING] Memory leak detected.\n");
	logClassAmountInfo();
	log("[WARNING] End of memory leak information.\n");
    }
}