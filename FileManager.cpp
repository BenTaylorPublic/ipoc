#include "FileManager.h"
#include "Settings.h"
#include "Debug.h"

void FileManager::writeToFile(const std::string& filePath, const std::string& input)
{
    std::ofstream file;
    file.open(filePath, std::ios_base::app);
    file << input;
    file.close();
}

void FileManager::writeToFile(const std::string& filePath, const char& input)
{
    std::ofstream file;
    file.open(filePath, std::ios_base::app);
    file << input;
    file.close();
}

void FileManager::clearFile(const std::string& filePath)
{
    std::ofstream file;
    file.open(filePath);
    file << "";
    file.close();
}

std::vector<std::string> FileManager::readFile(const std::string& filePath)
{
    std::vector<std::string> result = {};

    std::string line = "";
    std::ifstream file(filePath);
    if (file.is_open())
    {
	while (getline(file, line))
	{
	    result.push_back(line);
	}
	file.close();
    } else
    {
	Debug::log("[WARN] A text file could not be read.");
	Debug::commitLogLine();
    }

    return result;
}

std::string FileManager::getStatusString()
{
    return "N/A";
}
