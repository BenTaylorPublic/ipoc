#include "Settings.h"
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
std::string Settings::ipocVersion = "0.7.1-dev";

std::string Settings::imageFilePath = "default file path";
std::string Settings::fontFilePath = "default file path";
int Settings::loopsPerSecond = 1;
int Settings::loopTimeInNanoseconds = 1;
std::string Settings::filePath = "default file path";

int Settings::screenWidth = 1;
int Settings::screenHeight = 1;
std::string Settings::screenTitle = "default screen title";
unsigned int Settings::maxZ = 0;
unsigned int Settings::maxDrawables = 0;
std::string Settings::windowType = "windowed";
bool Settings::hideCursor = true;
bool Settings::logClassAmountInfo = false;

bool Settings::debugMode = true;

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

    //Need a standard way to deal with windows stupid backslashes. This will do for now
    imageFilePath = Conversions::replaceStringInString(filePath, "\\", "/");
    fontFilePath = Conversions::replaceStringInString(filePath, "\\", "/");

    std::vector<std::string> settingsFile = FileManager::readFile(settingsFilePath);

    imageFilePath += getStringFromSettings(settingsFile, "image_file_path");
    fontFilePath += getStringFromSettings(settingsFile, "font_file_path");
    loopsPerSecond = getIntFromSettings(settingsFile, "loops_per_second");
    loopTimeInNanoseconds = 1000000000 / loopsPerSecond;
    screenWidth = getIntFromSettings(settingsFile, "screen_width");
    screenHeight = getIntFromSettings(settingsFile, "screen_height");
    screenTitle = getStringFromSettings(settingsFile, "screen_title");
    maxZ = getIntFromSettings(settingsFile, "max_z");
    maxDrawables = getIntFromSettings(settingsFile, "max_drawables");
    windowType = getStringFromSettings(settingsFile, "window_type");
    hideCursor = getBoolFromSettings(settingsFile, "hide_cursor");
    logClassAmountInfo = getBoolFromSettings(settingsFile, "log_class_amount_info");
}

int Settings::getIntFromSettings(std::vector<std::string>& inputFile, const std::string& inputString) {
    for (int i = 0; i < inputFile.size(); i++) {
        if (Conversions::stringContains(inputFile[i], inputString)) {
            std::string resultS = inputFile[i].erase(0, inputString.length() + 2);
            int resultI = atoi(resultS.c_str());
            inputFile.erase(inputFile.begin() + i);
            return resultI;
        }
    }

    Debug::log("[CRASH] Couldn't find a setting. Setting name " + inputString + "\n");
    Debug::crash(104, "Settings.getIntFromSettings()");

    return -1;
}

std::string Settings::getStringFromSettings(std::vector<std::string>& inputFile, const std::string& inputString) {
    for (int i = 0; i < inputFile.size(); i++) {
        if (Conversions::stringContains(inputFile[i], inputString)) {
            std::string result = inputFile[i].erase(0, inputString.length() + 2);
            inputFile.erase(inputFile.begin() + i);
            return result;
        }
    }

    Debug::log("[CRASH] Couldn't find a setting. Setting name " + inputString + "\n");
    Debug::crash(105, "Settings.getStringFromSettings()");

    return "";
}

bool Settings::getBoolFromSettings(std::vector<std::string>& inputFile, const std::string& inputString) {
    for (int i = 0; i < inputFile.size(); i++) {
        if (Conversions::stringContains(inputFile[i], inputString)) {
            std::string resultS = inputFile[i].erase(0, inputString.length() + 2);
            inputFile.erase(inputFile.begin() + i);
            if (resultS == "true")
                return true;
            else if (resultS == "false")
                return false;
        }
    }

    Debug::log("[CRASH] Couldn't find a setting. Setting name " + inputString + "\n");
    Debug::crash(106, "Settings.getBoolFromSettings()");

    return false;
}

std::string Settings::getStatusString() {
    return "N/A";
}

