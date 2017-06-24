#include "IPOCSettings.h"
#include "Debug.h"
#include <string>
#include "FileManager.h"
#include "Conversions.h"
#include <vector>
#include <Windows.h>

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
	char buffer[MAX_PATH];
	//LPWSTR buffer;
	/*GetModuleFileName(NULL, buffer, MAX_PATH);
	wstring buffer2 = buffer;
	std::string temp(buffer2.begin(), buffer2.end());
	std::string::size_type pos = temp.find_last_of("\\/");
        
	filePath = temp.substr(0, pos) + "\\files\\";*/

        filePath = "C:\\Users\\Ben\\Documents\\NetBeansProjects\\IPOC Core\\dist\\Debug\\MinGW-Windows\\files\\";
	Debug::setFilePath(filePath);

	std::string settingsFilePath = filePath + "Settings.ini";

	//SFML uses forward slashes instead of back slashes
	//Who knew
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

int IPOCSettings::getIntFromSettings(vector<std::string>& inputFile, const std::string& inputString)
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
	
	Debug::log("[CRASH] Couldn't find a setting. Setting name " + inputString);
	Debug::commitLogLine();
	Debug::crash(104, "IPOCSettings.getIntFromSettings()");
	
	return -1;
}

std::string IPOCSettings::getStringFromSettings(vector<std::string>& inputFile, const std::string& inputString)
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
	
	Debug::log("[CRASH] Couldn't find a setting. Setting name " + inputString);
	Debug::commitLogLine();
	Debug::crash(105, "IPOCSettings.getStringFromSettings()");
	
	return "";
}

bool IPOCSettings::getBoolFromSettings(vector<std::string>& inputFile, const std::string& inputString)
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
	
	Debug::log("[CRASH] Couldn't find a setting. Setting name " + inputString);
	Debug::commitLogLine();
	Debug::crash(106, "IPOCSettings.getBoolFromSettings()");
	
	return false;
}

std::string IPOCSettings::getStatusString()
{
	return "N/A";
}

