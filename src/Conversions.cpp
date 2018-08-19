#include "Conversions.h"
#include "Debug.h"

std::string Conversions::keyEnumStrings[AMOUNT_OF_PHYSICAL_BUTTONS] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "Num0", "Num1", "Num2", "Num3", "Num4", "Num5", "Num6", "Num7", "Num8", "Num9", "Numpad0", "Numpad1", "Numpad2", "Numpad3", "Numpad4", "Numpad5", "Numpad6", "Numpad7", "Numpad8", "Numpad9", "ArrowLeft", "ArrowRight", "ArrowUp", "ArrowDown", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Add", "Subtract", "Divide", "Multiply", "Escape", "BackSlash", "BackSpace", "Comma", "Dash", "Delete", "Equal", "Home", "Insert", "LAlt", "LBracket", "LControl", "LShift", "LSystem", "Menu", "PageUp", "PageDown", "Pause", "Period", "Quote", "RAlt", "RBracket", "RControl", "Return", "RShift", "RSystem", "SemiColon", "Slash", "Space", "Tab", "Tilde", "End"};

std::string Conversions::convertKeyToString(const PhysicalButton& inputKey)
{
	return keyEnumStrings[(int) inputKey];
}

std::string Conversions::insertCommas(const int& inputInt)
{
	std::string numWithCommas = std::to_string(inputInt);
	int insertPosition = numWithCommas.length() - 3;
	while (insertPosition > 0)
	{
		numWithCommas.insert(insertPosition, ",");
		insertPosition -= 3;
	}

	return numWithCommas;
}

std::string Conversions::replaceStringInString(const std::string& inputString,
											   const std::string& stringToReplace,
											   const std::string& stringToReplaceWith)
{
	std::string result = "";

	for (int i = 0; i < inputString.size(); i++) //For each character of the input string
	{
		if (inputString.substr(i, stringToReplace.size()).compare(stringToReplace) == 0) //If the next next x characters matches the string to replace
		{
			result += stringToReplaceWith; //Instead add the replace with text
			i += stringToReplace.size() - 1; //Then increase the character index until it's past the replaced with text
		} else
		{
			//Otherwise just add the character
			result += inputString.at(i);
		}
	}

	return result;
}

bool Conversions::stringContains(const std::string& inputString,
								 const std::string& containsString)
{
	return (inputString.find(containsString) != std::string::npos);
}
