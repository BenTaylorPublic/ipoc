#pragma once

#include <string>
#include "MasterController.h"
#include "TrackedClasses.h"

/**
 * Debug is a Static Helper \n
 * Debug is used for \n
 * 1. Writing to console \n
 * 2. Logging to log file \n
 * 3. Dumping status strings to log on program crash \n
 * 4. Memory leak monitoring
 */
class Debug
{
public:
	/**
	 * Crashes the program to desktop \n
	 * Should only be used in a scenario when the program will throw an exception if it continues
	 * @param crashId The crash id. Add them to CrashIDs.txt when made
	 * @param callFrom A string of the location of the call. Example "Settings.getBoolFromSettings()"
	 */
	static void crash(const unsigned int& crashId,
					  const std::string& callFrom);
	/**
	 * Increments the loopNumber \n
	 */
	static void incrementLoopNumber();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Called when the engine is starting
	 * @param inputMasterController A point to the MasterController, which will be used to logStatusStrings() when requested
	 */
	static void IPOCLoad(MasterController* inputMasterController);
	/**
	 * Logs the input to the debug log
	 * This differs from logUnsigned() because unsigned ints must be treated differently when being output
	 * @param input input to output to the debug log
	 */
	static void log(const int& input);
	/**
	 * Logs the input to the debug log
	 * @param input input to output to the debug log
	 */
	static void log(const std::string& input);
	/**
	 * <b> IPOC ONLY </b> \n
	 * Logs to the debug log, the amount of each of the TrackedClasses
	 */
	static void logClassAmountInfo();
	/**
	 * Same as log() but appends a new line character to the end
	 * @param input
	 */
	static void logLine(const int& input);
	/**
	 * Same as log() but appends a new line character to the end
	 * @param input
	 */
	static void logLine(const std::string& input);
	/**
	 * Same as logUnsigned() but appends a new line character to the end
	 * @param input
	 */
	static void logLineUnsigned(const unsigned int& input);
	/**
	 * Outputs the current loop number to the debug log
	 */
	static void logLoopNumber();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Logs to the debug log, memory leak information of the TrackedClasses
	 */
	static void logMemoryLeakInfo();
	/**
	 * Calls every object's getStatusString() method, and logs them immediately to the log file. \n
	 * This should be used for serious debugging issues. \n
	 * This should also be called on any program crashes. \n
	 * It makes use of the masterController pointer defined below.
	 */
	static void logStatusStrings();
	/**
	 * Outputs the current time stamp to the debug log
	 */
	static void logTimeStamp();
	/**
	 * Logs the input to the debug log
	 * This differs from log(const int& input) because unsigned ints must be treated differently when being output
	 * @param input input to output to the debug log
	 */
	static void logUnsigned(const unsigned int& input);
	/**
	 * <b> IPOC ONLY </b> \n
	 * Creates a new log file \n
	 * If a log file exists, it'll reset it to an empty file
	 */
	static void newLog();
	/**
	 * This function is used to keep track of the TrackedClasses, which are monitored for memory leaks \n
	 * Specifically this function keeps track of the construction of a TrackedClass
	 * @param classId class ID of the class being constructed. See TrackedClasses for IDs.
	 */
	static void notifyOfConstruction(const int& classId);
	/**
	 * This function is used to keep track of the TrackedClasses, which are monitored for memory leaks \n
	 * Specifically this function keeps track of the copying of a TrackedClass
	 * @param classId class ID of the class being copied. See TrackesClasses for IDs.
	 */
	static void notifyOfCopy(const int& classId);
	/**
	 * This function is used to keep track of the TrackedClasses, which are monitored for memory leaks \n
	 * Specifically this function keeps track of the destruction of a TrackedClass
	 * @param classId class ID of the class being destructed. See TrackedClasses for IDs.
	 */
	static void notifyOfDestruction(const int& classId);
	/**
	 * <b> IPOC ONLY </b> \n
	 * Called when the engine is starting \n
	 * Called from settings to receive the file path for the debug log
	 * @param inputPath
	 */
	static void setFilePath(std::string inputPath);
	/**
	 * Writes to the console, used for debug only \n
	 * This differs from writeUnsigned() because unsigned ints must be treated differently when being output
	 * @param input int input
	 */
	static void write(const int& input);
	/**
	 * Writes to the console, used for debug only
	 * @param input string input
	 */
	static void write(const std::string& input);
	/**
	 * Same as write() but appends a new line character to the end
	 * @param input
	 */
	static void writeLine(const int& input);
	/**
	 * Same as write() but appends a new line character to the end
	 * @param input
	 */
	static void writeLine(const std::string& input);
	/**
	 * Same as writeUnsigned() but appends a new line character to the end
	 * @param input
	 */
	static void writeLineUnsigned(const unsigned int& input);
	/**
	 * Writes the current loop number to the console
	 */
	static void writeLoopNumber();
	/**
	 * Writes to the console, used for debug only \n
	 * This differs from write(const int& input) because unsigned ints must be treated differently when being output
	 * @param input unsigned int input
	 */
	static void writeUnsigned(const unsigned int& input);

private:
	/**
	 * A count of the how many constructors have been called for each individual tracked class
	 */
	static unsigned int constructionAmount[AMOUNT_OF_TRACKED_CLASSES];
	/**
	 * A count of the how many copy constructors have been called for each individual tracked class
	 */
	static unsigned int copyAmount[AMOUNT_OF_TRACKED_CLASSES];
	/**
	 * A count of the how many destructors have been called for each individual tracked class
	 */
	static unsigned int destructionAmount[AMOUNT_OF_TRACKED_CLASSES];
	/**
	 * The file path of the DebugLog.txt file
	 */
	static std::string logPath;
	/**
	 * Used for logging and writing loop numbers from anywhere in the program.
	 */
	static unsigned int loopNumber;
	/**
	 * A pointer the the MasterController \n
	 * The reason this exists, is because the master controller contains all the controllers below it, and those controllers contain all the objects below them \n
	 * So having a pointer to the top of the hierarchy, is essential in debugging EVERY objects status \n
	 * This pointer is used by Debug::logStatusStrings()
	 */
	static MasterController* masterController;
};