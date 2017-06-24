#pragma once
#include <string>
#include "MasterController.h"

#define AMOUNT_OF_CLASSES 20

/*
Debug is a Static Helper

Debug is used for:
1. Writing to console
2. Logging to log file
3. Dumping status strings to log on program crash
4. Memory leak monitoring
*/
class Debug
{
public:
    static void notifyOfConstruction(const int& classId);//for memory leak monitoring
    static void notifyOfDestruction(const int& classId);//for memory leak monitoring
    static void notifyOfCopy(const int& classId);//for memory leak monitoring
    static void write(const int& input); //Writes to the console. You need to provide your own "\n".
    static void write(const std::string& input); //Writes to the console. You need to provide your own "\n".
    static void writeLoopNumber(); //Writes to the loop number to the console. You need to provide your own "\n".
    static void newLog(); //Clears the log file
    static void log(const int& input); //Adds the input to the toLog variable. Once you're happy with the line, you need to use Debug::commitLogLine() to log it.
    static void log(const std::string& input); //Adds the input to the toLog variable. Once you're happy with the line, you need to use Debug::commitLogLine() to log it.
    static void logTimeStamp(); //Adds the time stamp to the toLog variable. Once you're happy with the line, you need to use Debug::commitLogLine() to log it.
    static void logLoopNumber(); //Adds the loop to the toLog variable. Once you're happy with the line, you need to use Debug::commitLogLine() to log it.
    static void logMemoryLeakInfo();
    static void logClassAmountInfo();
    static void crash(const int& crashId, const std::string& callFrom);
    /*
    Calls every object's getStatusString() method, and logs them immediately to the log file.
    This should be used for serious debugging issues.
    This should also be called on any program crashes.
    It makes use of the masterController pointer defined below.
    */
    static void logStatusStrings();
    static void commitLogLine(); //Adds the toLog variable to the log file. Look at the log() methods to see how to add to the toLog variable.
    static void incrementLoopNumber(); //Increments the loop number. Used for logging and writing loop numbers from anwywhere in the program.
    static void setMasterController(MasterController* input); //Used to received a pointer tot he MasterController. This pointer will then be used to logStatusStrings(), when requested.
    static void setFilePath(std::string inputPath); //used to receive the file path from the Settings class.
private:
    static std::string toLog; //String that is about to be written to the log file. All the caller needs to do is call commitLogLine()
    static int loopNumber; //Used for logging and writing loop numbers from anwywhere in the program.
    /*
    A pointer the the MasterController.
    The reason this exists, is because the master controller contains all the controllers below it, and those controllers contain all the objects below them.
    So having a pointer to the top of the heirachy, is essential in debugging EVERY objects status.
    This pointer is used by Debug::logStatusStrings()
    */
    static MasterController* masterController;
    static int constructionAmount[AMOUNT_OF_CLASSES];
    static int destructionAmount[AMOUNT_OF_CLASSES];
    static int copyAmount[AMOUNT_OF_CLASSES];
    static std::string logPath; //The filepath of the DebugLog.txt file.
};