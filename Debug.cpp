#include "Debug.h"
#include <iostream>
#include "Settings.h"
#include "FileManager.h"
#include <time.h>
#include "MasterController.h"
#include <chrono>

//Defaults
unsigned int Debug::loopNumber = 0;
MasterController* Debug::masterController = nullptr;
std::string Debug::logPath = "blank";
double Debug::processThreadUsagePercent = 0;
unsigned int Debug::processThreadUsage[PROCESS_THREAD_USAGE_DURATIONS_STORED] = {0};
unsigned int Debug::processThreadUsageIndex = 0;

unsigned int Debug::constructionAmount[AMOUNT_OF_TRACKED_CLASSES] = {0};
unsigned int Debug::destructionAmount[AMOUNT_OF_TRACKED_CLASSES] = {0};
unsigned int Debug::copyAmount[AMOUNT_OF_TRACKED_CLASSES] = {0};

void Debug::write(const int& input)
{
    std::cout << std::to_string(input);
}

void Debug::writeUnsigned(const unsigned int& input)
{
    std::cout << std::to_string(input);
}

void Debug::write(const std::string& input)
{
    std::cout << input;
}

void Debug::writeLine(const int& input)
{
    std::cout << std::to_string(input) + "\n";
}

void Debug::writeLineUnsigned(const unsigned int& input)
{
    std::cout << std::to_string(input) + "\n";
}

void Debug::writeLine(const std::string& input)
{
    std::cout << input + "\n";
}

void Debug::writeLoopNumber()
{
    std::cout << loopNumber;
}

void Debug::log(const int& input)
{
    FileManager::writeToFile(logPath, std::to_string(input));
}

void Debug::log(const std::string& input)
{
    FileManager::writeToFile(logPath, input);
}

void Debug::logUnsigned(const unsigned int& input)
{
    FileManager::writeToFile(logPath, std::to_string(input));
}

void Debug::logLine(const int& input)
{
    FileManager::writeToFile(logPath, std::to_string(input) + "\n");
}

void Debug::logLine(const std::string& input)
{
    FileManager::writeToFile(logPath, input + "\n");
}

void Debug::logLineUnsigned(const unsigned int& input)
{
    FileManager::writeToFile(logPath, std::to_string(input) + "\n");
}

void Debug::logLoopNumber()
{
    FileManager::writeToFile(logPath, std::to_string(loopNumber));
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

void Debug::IPOCLoad(MasterController* input)
{
    for (int i = 0; i < PROCESS_THREAD_USAGE_DURATIONS_STORED; i++)
    {
	processThreadUsage[0] = 0;
    }
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

void Debug::noteLoopTime(const unsigned int& loopDuration)
{
    processThreadUsageIndex++;
    if (processThreadUsageIndex == PROCESS_THREAD_USAGE_DURATIONS_STORED)
	processThreadUsageIndex = 0;
    processThreadUsage[processThreadUsageIndex] = loopDuration;



    //Average the array
    double sum = 0;

    for (int i = 0; i < PROCESS_THREAD_USAGE_DURATIONS_STORED; i++)
    {
	sum += processThreadUsage[i];
    }

    processThreadUsagePercent = (sum * 100) / (PROCESS_THREAD_USAGE_DURATIONS_STORED * Settings::loopTimeInNanoseconds);

}

void Debug::crash(const unsigned int& crashId, const std::string& callFrom)
{
    writeLine("[CRASH] Program crashed. Crash ID " + std::to_string(crashId));
    writeLine("[CRASH] Crash called from " + callFrom);
    writeLine("[CRASH] Crashed on loop " + std::to_string(loopNumber));
    logLine("[CRASH] Program crashed. Crash ID " + std::to_string(crashId));
    logLine("[CRASH] Crash called from " + callFrom);
    logLine("[CRASH] Crashed on loop " + std::to_string(loopNumber));
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
    logLine("[INFO] Logging class amount info");

    logLine("[INFO] Class MasterController, our benevolent overlord is exempt from this blasphemous scrutiny.");

    for (int i = 1; i < AMOUNT_OF_TRACKED_CLASSES; i++)
    {
	log("[INFO] ");
	if (constructionAmount[i] + copyAmount[i] != destructionAmount[i])
	{
	    log("MEMORY LEAK, ");
	}
	logLine("Class " + TrackedClasses::classNames[i] + ", constructed " + std::to_string(constructionAmount[i]) + ", copied " + std::to_string(copyAmount[i]) + ", destructed " + std::to_string(destructionAmount[i]) + ".");
    }

    logLine("[INFO] End of class amount info");
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
	logLine("[INFO] No memory leaks detected");
    } else
    {
	logLine("[WARNING] Memory leak detected.");
	logClassAmountInfo();
	logLine("[WARNING] End of memory leak information.");
    }
}