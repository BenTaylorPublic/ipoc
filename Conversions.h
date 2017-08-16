#pragma once

#include <string>
#include "InputEnums.h"

/*
Conversions is a Static Helper
 */
class Conversions {
public:
    static bool stringContains(const std::string& inputString, const std::string& containsString); //Returns true if a specified string contains a second specified string
    static std::string convertKeyToString(const PhysicalButton& inputKey); //Converts a keycode into a string, eg A to "A"
    static std::string replaceStringInString(const std::string& inputString, const std::string& stringToReplace, const std::string& stringToReplaceWith); //Replaces all occurances of a string, with a specified string
    static std::string insertCommas(const int& inputInt);
    /*
    Returns a string indicating this object's current status, and all objects it manages.
    Should only be used for debugging, but not strictly.
     */
    static std::string getStatusString();
private:
    static std::string keyEnumStrings[]; //Used to contain the keycode string versions
};