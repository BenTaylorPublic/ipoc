#pragma once

#include <string>

/*
Color is a Data type
Color contains 3 integers which correspond to Red Green and Blue components of color
 */
class Color
{
public:
	Color(const int& inputR,
		  const int& inputG,
		  const int& inputB); //Creates a new color, with the RGB values inputted
	Color(); //Creates a new color, that defaults to black RGB = 0
	~Color();
	static Color Random();
	int r;
	int g;
	int b; //The blue component of the color
	void randomize(); //Randomizes the red green and blue components of the color
	/*
	Returns a string indicating this object's current status, and all objects it manages.
	Should only be used for debugging, but not strictly.
	 */
	std::string getStatusString() const;

private:
};