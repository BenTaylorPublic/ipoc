#pragma once

#include <string>
#include "InputEnums.h"

/**
 * Conversions is a static helper
 */
class Conversions
{
public:
	/**
	 * Returns true if a specified string (inputString) contains a second specified string (containsString)
	 * @param inputString The string that could contain the containsString
	 * @param containsString The string that could be inside the inputString
	 * @return true if containsString is inside inputString, otherwise false
	 */
	static bool stringContains(const std::string& inputString,
							   const std::string& containsString);
	/**
	 * Converts the PhysicalButton Enum to it's corresponding key as a string
	 * @param inputKey PhysicalButton Enum to convert to a string
	 * @return String representation of inputKey
	 */
	static std::string convertKeyToString(const PhysicalButton& inputKey);
	/**
	 * Replaces all occurrences of a string, with a specified string
	 * @param inputString the original string
	 * @param stringToReplace the string to be replaced
	 * @param stringToReplaceWith the string to be replaced with
	 * @return A string with all occurrences of a string, replaced with the specified string
	 */
	static std::string replaceStringInString(const std::string& inputString,
											 const std::string& stringToReplace,
											 const std::string& stringToReplaceWith);
	/**
	 * Returns a number with commas every 3 digits
	 * @param inputInt integer to put commas into
	 * @return A string with commas every 3 digits
	 */
	static std::string insertCommas(const int& inputInt);
private:
	/**
	 * Used to contain the keycode string versions
	 */
	static std::string keyEnumStrings[];
};