#pragma once

#include <string>
#include <fstream>
#include <vector>

/**
 * Used to read and write to text files \n
 * When it's needed, it should be converted to read and write xml and csv
 */
class FileManager
{
public:
	/**
	 * Clears all text from a file. \n
	 * Used on launch to clear the DebugLog, for example
	 * @param filePath The full path to the text file (not relative)
	 */
	static void clearFile(const std::string& filePath);
	/**
	 * Returns a string indicating this object's current status, and all objects it manages. \n
	 * Should only be used for debugging, but not strictly.
	 * @return status string
	 */
	static std::string getStatusString();
	/**
	 * Reads the specified text file into a vector of strings (one per line)
	 * @param filePath The full path to the text file (not relative)
	 * @return A vector of strings, one element being a single line of the text file
	 */
	static std::vector<std::string> readFile(const std::string& filePath);
	/**
	 * Writes the data to the provided text file
	 * @param filePath The full path to the text file (not relative)
	 * @param input The text to input into the file
	 */
	static void writeToFile(const std::string& filePath,
							const std::string& input);
	/**
	 * Writes the data to the provided text file
	 * @param filePath The full path to the text file (not relative)
	 * @param input The text to input into the file
	 */
	static void writeToFile(const std::string& filePath,
							const char& input);
private:
};