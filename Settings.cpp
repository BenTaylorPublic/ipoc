#include "Settings.h"
#include "IPOCSettings.h"
#include "Debug.h"
#include <string>
#include "FileManager.h"
#include "Conversions.h"
#include <vector>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif 

//All the defaults

std::string Settings::imageFilePath = "default file path";
std::string Settings::fontFilePath = "default file path";
std::string Settings::filePath = "default file path";

int Settings::screenWidth = 1;
int Settings::screenHeight = 1;
std::string Settings::screenTitle = "default window title";
std::string Settings::windowType = "windowed";
bool Settings::hideCursor = true;

InputStatus Settings::inputStatus = Active;

void Settings::loadSettings()
{
    char buff[FILENAME_MAX];
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
#ifdef WINDOWS
    filePath = current_working_dir + "\\files\\";
#else
    filePath = current_working_dir + "/files/";
#endif


    Debug::setFilePath(filePath);

    std::string settingsFilePath = filePath + "Settings.ini";


    Debug::newLog();
    std::vector<std::string> settingsFile = FileManager::readFile(settingsFilePath);
    if (settingsFile.size() == 0)
    {
	//Settings.ini file doesn't exist, create a severe crash report
	Debug::logLine("[CRASH] The IPOC framework was unable to find the Settings.ini file required to start.");
	Debug::logLine("[CRASH] This is a severe issue, as IPOC cannot start.");
	Debug::logLine("[CRASH] Ensure that Settings.ini is in the files directory.");
	Debug::crash(107, "Settings.loadSettings()");
    }

    imageFilePath = filePath + IMAGE_DIRECTORY;
    fontFilePath = filePath + FONT_DIRECTORY;
    //Need a standard way to deal with windows stupid backslashes. This will do for now
    imageFilePath = Conversions::replaceStringInString(imageFilePath, "\\", "/");
    fontFilePath = Conversions::replaceStringInString(fontFilePath, "\\", "/");

    screenWidth = getIntFromSettings(settingsFile, "screen_width");
    screenHeight = getIntFromSettings(settingsFile, "screen_height");
    screenTitle = getStringFromSettings(settingsFile, "screen_title");
    windowType = getStringFromSettings(settingsFile, "window_type");
    hideCursor = getBoolFromSettings(settingsFile, "hide_cursor");
}

int Settings::getIntFromSettings(std::vector<std::string>& inputFile, const std::string& inputString)
{
    for (int i = 0; i < inputFile.size(); i++)
    {
	if (Conversions::stringContains(inputFile[i], inputString))
	{
	    std::string resultS = inputFile[i].erase(0, inputString.length() + 2);
	    int resultI = atoi(resultS.c_str());
	    inputFile.erase(inputFile.begin() + i);
	    return resultI;
	}
    }

    Debug::logLine("[CRASH] Couldn't find a setting. Setting name " + inputString);
    Debug::crash(104, "Settings.getIntFromSettings()");

    return -1;
}

std::string Settings::getStringFromSettings(std::vector<std::string>& inputFile, const std::string& inputString)
{
    for (int i = 0; i < inputFile.size(); i++)
    {
	if (Conversions::stringContains(inputFile[i], inputString))
	{
	    std::string result = inputFile[i].erase(0, inputString.length() + 2);
	    inputFile.erase(inputFile.begin() + i);
	    return result;
	}
    }

    Debug::logLine("[CRASH] Couldn't find a setting. Setting name " + inputString);
    Debug::crash(105, "Settings.getStringFromSettings()");

    return "";
}

bool Settings::getBoolFromSettings(std::vector<std::string>& inputFile, const std::string& inputString)
{
    for (int i = 0; i < inputFile.size(); i++)
    {
	if (Conversions::stringContains(inputFile[i], inputString))
	{
	    std::string resultS = inputFile[i].erase(0, inputString.length() + 2);
	    inputFile.erase(inputFile.begin() + i);
	    if (resultS == "true")
		return true;
	    else if (resultS == "false")
		return false;
	}
    }

    Debug::logLine("[CRASH] Couldn't find a setting. Setting name " + inputString);
    Debug::crash(106, "Settings.getBoolFromSettings()");

    return false;
}

std::string Settings::getStatusString()
{
    return "N/A";
}

