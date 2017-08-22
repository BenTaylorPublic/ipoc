#pragma once
#include <string>
#include "MasterController.h"

#define AMOUNT_OF_CLASSES 20
#define PROCESS_THREAD_USAGE_DURATIONS_STORED 8

/*
Debug is a Static Helper

Debug is used for:
1. Writing to console
2. Logging to log file
3. Dumping status strings to log on program crash
4. Memory leak monitoring
 */
class Debug {
public:
    static void notifyOfConstruction(const int& classId); //for memory leak monitoring
    static void notifyOfDestruction(const int& classId); //for memory leak monitoring
    static void notifyOfCopy(const int& classId); //for memory leak monitoring
    static void write(const int& input);
    static void write(const std::string& input);
    static void writeUnsigned(const unsigned int& input);
    static void writeLine(const int& input);
    static void writeLine(const std::string& input);
    static void writeLineUnsigned(const unsigned int& input);
    static void writeLoopNumber();
    static void newLog(); //Clears the log file
    static void log(const int& input);
    static void log(const std::string& input);
    static void logUnsigned(const unsigned int& input);
    static void logLine(const int& input);
    static void logLine(const std::string& input);
    static void logLineUnsigned(const unsigned int& input);
    static void logTimeStamp();
    static void logLoopNumber(); 
    static void logMemoryLeakInfo();
    static void logClassAmountInfo();
    static void noteLoopTime(const unsigned int& loopDuration);
    static void crash(const unsigned int& crashId, const std::string& callFrom);
    /*
    Calls every object's getStatusString() method, and logs them immediately to the log file.
    This should be used for serious debugging issues.
    This should also be called on any program crashes.
    It makes use of the masterController pointer defined below.
     */
    static void logStatusStrings();
    static void incrementLoopNumber(); //Increments the loop number. Used for logging and writing loop numbers from anwywhere in the program.
    static void IPOCLoad(MasterController* input); //Used to received a pointer tot he MasterController. This pointer will then be used to logStatusStrings(), when requested.
    static void setFilePath(std::string inputPath); //used to receive the file path from the Settings class.
    static double processThreadUsagePercent;
private:
    static unsigned int loopNumber; //Used for logging and writing loop numbers from anwywhere in the program.
    static unsigned int processThreadUsage[PROCESS_THREAD_USAGE_DURATIONS_STORED];
    static unsigned int processThreadUsageIndex;

    /*
    A pointer the the MasterController.
    The reason this exists, is because the master controller contains all the controllers below it, and those controllers contain all the objects below them.
    So having a pointer to the top of the heirachy, is essential in debugging EVERY objects status.
    This pointer is used by Debug::logStatusStrings()
     */
    static MasterController* masterController;
    static unsigned int constructionAmount[AMOUNT_OF_CLASSES];
    static unsigned int destructionAmount[AMOUNT_OF_CLASSES];
    static unsigned int copyAmount[AMOUNT_OF_CLASSES];
    static std::string logPath; //The filepath of the DebugLog.txt file.
};