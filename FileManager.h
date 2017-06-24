#pragma once
#include <string>
#include <fstream>
#include <vector>

//Used to read and write to text files
class FileManager
{
public:
    static void writeToFile(const std::string& filePath, const std::string& input);
    static void writeToFile(const std::string& filePath, const char& input);
    static void clearFile(const std::string& filePath); //Clears all text from a file. Used on launch to clear the DebugLog
    static std::vector<std::string> readFile(const std::string& filePath); //Reads all the text from a file, and returns a vector<string>. Each line is a new entry.
    /*
    Returns a string indicating this object's current status, and all objects it manages.
    Should only be used for debugging, but not strictly.
    */
    static std::string getStatusString();
private:
};