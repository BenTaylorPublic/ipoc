#pragma once
#include <string>
#include "Storage.h"

class Settings
{
public:
    static std::string getStatusString();
    static void loadSettings();
    static int loopsPerSecond;
    static std::string filePath;
    static int screenWidth;
    static int screenHeight;
    static std::string screenTitle;
    static std::string imageFilePath;
    static std::string fontFilePath;
    static std::string ipocVersion;
    static int maxZ;
    static int maxDrawables;
    static std::string windowType;
    static bool hideCursor;
    static bool logClassAmountInfo;
private:
    static int getIntFromSettings(vector<std::string>& inputFile, const std::string& inputString);
    static std::string getStringFromSettings(vector<std::string>& inputFile, const std::string& inputString);
    static bool getBoolFromSettings(vector<std::string>& inputFile, const std::string& inputString);
};