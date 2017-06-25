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
std::string IPOCSettings::ipocVersion = "0.4.0";

std::string IPOCSettings::imageFilePath = "default file path";
std::string IPOCSettings::fontFilePath = "default file path";
int IPOCSettings::loopsPerSecond = 1;
std::string IPOCSettings::filePath = "default file path";

int IPOCSettings::screenWidth = 1;
int IPOCSettings::screenHeight = 1;
std::string IPOCSettings::screenTitle = "default screen title";
int IPOCSettings::maxZ = 0;
int IPOCSettings::maxDrawables = 0;
std::string IPOCSettings::windowType = "windowed";
bool IPOCSettings::hideCursor = true;
bool IPOCSettings::logClassAmountInfo = false;

void IPOCSettings::loadSettings() 
{
    char buff[FILENAME_MAX];
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);

    //This seems dodgy
    //But the directory only gives me the directory of the cpp and h files
    //Will have to test later on release
    filePath = current_working_dir + "\\dist\\Debug\\MinGW-Windows\\files\\";
    
    Debug::setFilePath(filePath);

    std::string settingsFilePath = filePath + "Settings.ini";

    //Need a standard way to deal with windows stupid backslashes. This will do for now
    imageFilePath = Conversions::replaceStringInString(filePath, "\\", "/");
    fontFilePath = Conversions::replaceStringInString(filePath, "\\", "/");

    vector<string> settingsFile = FileManager::readFile(settingsFilePath);

    imageFilePath += getStringFromSettings(settingsFile, "image_file_path");
    fontFilePath += getStringFromSettings(settingsFile, "font_file_path");
    loopsPerSecond = getIntFromSettings(settingsFile, "loops_per_second");
    screenWidth = getIntFromSettings(settingsFile, "screen_width");
    screenHeight = getIntFromSettings(settingsFile, "screen_height");
    screenTitle = getStringFromSettings(settingsFile, "screen_title");
    maxZ = getIntFromSettings(settingsFile, "max_z");
    maxDrawables = getIntFromSettings(settingsFile, "max_drawables");
    windowType = getStringFromSettings(settingsFile, "window_type");
    hideCursor = getBoolFromSettings(settingsFile, "hide_cursor");
    logClassAmountInfo = getBoolFromSettings(settingsFile, "log_class_amount_info");
}

int IPOCSettings::getIntFromSettings(vector<std::string>& inputFile, const std::string& inputString) {
    for (int i = 0; i < inputFile.size(); i++) {
        if (Conversions::stringContains(inputFile[i], inputString)) {
            std::string resultS = inputFile[i].erase(0, inputString.length() + 2);
            int resultI = atoi(resultS.c_str());
            inputFile.erase(inputFile.begin() + i);
            return resultI;
        }
    }

    Debug::log("[CRASH] Couldn't find a setting. Setting name " + inputString);
    Debug::commitLogLine();
    Debug::crash(104, "IPOCSettings.getIntFromSettings()");

    return -1;
}

std::string IPOCSettings::getStringFromSettings(vector<std::string>& inputFile, const std::string& inputString) {
    for (int i = 0; i < inputFile.size(); i++) {
        if (Conversions::stringContains(inputFile[i], inputString)) {
            std::string result = inputFile[i].erase(0, inputString.length() + 2);
            inputFile.erase(inputFile.begin() + i);
            return result;
        }
    }

    Debug::log("[CRASH] Couldn't find a setting. Setting name " + inputString);
    Debug::commitLogLine();
    Debug::crash(105, "IPOCSettings.getStringFromSettings()");

    return "";
}

bool IPOCSettings::getBoolFromSettings(vector<std::string>& inputFile, const std::string& inputString) {
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

    Debug::log("[CRASH] Couldn't find a setting. Setting name " + inputString);
    Debug::commitLogLine();
    Debug::crash(106, "IPOCSettings.getBoolFromSettings()");

    return false;
}

std::string IPOCSettings::getStatusString() {
    return "N/A";
}

