#pragma once
#include <string>
#include "Storage.h"

#define DEFAULT_Z_VALUE 1
#define LOOPS_PER_SECOND 64
#define LOOP_TIME_IN_NANOSECONDS 1000000000 / LOOPS_PER_SECOND
#define SCREEN_TITLE "IPOC Sample"
#define HIGHEST_Z_INDEX 10
#define AMOUNT_OF_VIEWS 2

//For debugging
#define LOG_CLASS_AMOUNT_INFO false
#define DEBUG_MODE true

//Program specific
#define BOSS_SIM_VERSION "0.0.1"

enum InputStatus {
    Active, PauseRequested, Paused
};

class Settings {
public:
    static std::string getStatusString();
    static void loadSettings();
    static std::string filePath;
    static std::string imageFilePath;
    static std::string fontFilePath;
    static int screenWidth;
    static int screenHeight;
    static std::string screenTitle;
    static std::string windowType;
    static bool hideCursor;
    static InputStatus inputStatus;
private:
    static int getIntFromSettings(std::vector<std::string>& inputFile, const std::string& inputString);
    static std::string getStringFromSettings(std::vector<std::string>& inputFile, const std::string& inputString);
    static bool getBoolFromSettings(std::vector<std::string>& inputFile, const std::string& inputString);
};