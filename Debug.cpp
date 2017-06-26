#include "Debug.h"
#include <iostream>
#include "Settings.h"
#include "FileManager.h"
#include <time.h>
#include "MasterController.h"
#include <chrono>

//Defaults
std::string Debug::toLog = "";
int Debug::loopNumber = 0;
MasterController *Debug::masterController = nullptr;
std::string Debug::logPath = "blank";

int Debug::constructionAmount[AMOUNT_OF_CLASSES] = {0};
int Debug::destructionAmount[AMOUNT_OF_CLASSES] = {0};
int Debug::copyAmount[AMOUNT_OF_CLASSES] = {0};

void Debug::write(const int& input)
{
	cout << input;
}

void Debug::write(const std::string& input)
{
	cout << input;
}

void Debug::writeLoopNumber()
{
	cout << loopNumber;
}

void Debug::log(const int& input)
{
	toLog += to_string(input);
}

void Debug::log(const std::string& input)
{
	toLog += input;
}

void Debug::logLoopNumber()
{
	toLog += to_string(loopNumber);
}

void Debug::commitLogLine()
{
	toLog += "\n";
	FileManager::writeToFile(logPath, toLog);
	toLog = "";
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
	toLog += timeStamp;
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
	std::string temp = masterController->getStatusString();
	log(temp);
	commitLogLine();
}

void Debug::setFilePath(std::string inputPath)
{
	logPath = inputPath + "DebugLog.txt";
}

void Debug::notifyOfConstruction(const int& classId)
{
	constructionAmount[classId]++;
	/*if (classId == 14)
	{
		write("Constructed\n");		
	}*/
}

void Debug::notifyOfDestruction(const int& classId)
{
	destructionAmount[classId]++;	
	/*if (classId == 14)
	{
		write("Destructed\n");
	}*/
}

void Debug::notifyOfCopy(const int& classId)
{
	copyAmount[classId]++;	
}

void Debug::crash(const int& crashId, const std::string& callFrom)
{
	write("[CRASH] Program crashed. Crash ID " + to_string(crashId) + ".\n");
	write("[CRASH] Crash called from " + callFrom + "\n");
	write("[CRASH] Crashed on loop " + to_string(loopNumber));
	log("[CRASH] Program crashed. Crash ID " + to_string(crashId) + ".");
	commitLogLine();
	log("[CRASH] Crash called from " + callFrom);
	commitLogLine();
	log("[CRASH] Crashed on loop " + to_string(loopNumber));
	commitLogLine();
    exit (EXIT_FAILURE);
	
	/*
	 * CrashID summary
	 * 103: IPOCFrame.addToFrame()
	 * 104: IPOCSettings.getIntFromSettings()
	 * 105: IPOCSettings.getStringFromSettings()
	 * 106: IPOCSettings.getBoolFromSettings() 
	 */
	
}

void Debug::logClassAmountInfo()
{
	log("[INFO] Logging class amount info");
	commitLogLine();
	
	log("[INFO] ClassID 0, our benevolent overlord is exempt from this blasphemous scrutiny.");
	commitLogLine();

	for (int i = 1; i < AMOUNT_OF_CLASSES; i++)
	{
		log("[INFO] ");
		if (constructionAmount[i] + copyAmount[i] != destructionAmount[i])
		{
			log("MEMORY LEAK, ");
		}
		log("ClassID " + to_string(i) + ", constructed " + to_string(constructionAmount[i]) + ", copied " + to_string(copyAmount[i]) + ", destructed " +  to_string(destructionAmount[i]) + ".");
		commitLogLine();
	}
	
	log("[INFO] End of class amount info");
	commitLogLine();
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
		log("[INFO] No memory leaks detected");
		commitLogLine();
	}
	else
	{
		log("[WARNING] Memory leak detected.");
		commitLogLine();
		logClassAmountInfo();
		log("[WARNING] End of memory leak information.");
		commitLogLine();
	}
}