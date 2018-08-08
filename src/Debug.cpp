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
	time_t now;
	time(&now);
	char buf[sizeof "2011-10-08 07:07:09"];
	strftime(buf, sizeof buf, "%F %T", localtime(&now));
	FileManager::writeToFile(logPath, buf);
}

void Debug::incrementLoopNumber()
{
	loopNumber++;
}

void Debug::IPOCLoad(MasterController* input)
{
	masterController = input;
}

void Debug::logStatusStrings()
{
	FileManager::writeToFile(logPath, masterController->getStatusString());
}

void Debug::setFilePath(std::string inputPath)
{
	logPath = inputPath + "/generated/DebugLog.log";
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

void Debug::crash(const unsigned int& crashId,
				  const std::string& callFrom)
{
	writeLine("[CRASH] Program crashed. Crash ID " + std::to_string(crashId));
	writeLine("[CRASH] Crash called from " + callFrom);
	writeLine("[CRASH] Crashed on loop " + std::to_string(loopNumber));
	logLine("[CRASH] Program crashed. Crash ID " + std::to_string(crashId));
	logLine("[CRASH] Crash called from " + callFrom);
	logLine("[CRASH] Crashed on loop " + std::to_string(loopNumber));
	exit(EXIT_FAILURE);
}

void Debug::logClassAmountInfo()
{
	logLine("[INFO] Logging class amount info");

	for (int i = 0; i < AMOUNT_OF_TRACKED_CLASSES; i++)
	{
		log("[INFO] ");
		if (constructionAmount[i] + copyAmount[i] != destructionAmount[i])
		{
			log("MEMORY LEAK, ");
		}
		logLine("Class " + TrackedClasses::classNames[i] + ", constructed " + std::to_string(constructionAmount[i]) +
				", copied " + std::to_string(copyAmount[i]) + ", destructed " + std::to_string(destructionAmount[i]) +
				".");
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