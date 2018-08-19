#pragma once

#include <string>
//TODO: Remove red green blue from public, and create get and set accessors

/**
 * Color is a data type \n
 * Color contains 3 integers which correspond to Red Green and Blue components of color
 */
class Color
{
public:
	/**
	 * Creates a new color, with the RGB values inputted
	 * @param inputRed red value to set  (int, 0-255)
	 * @param inputGreen green value to set  (int, 0-255)
	 * @param inputBlue blue value to set (int, 0-255)
	 */
	Color(const int& inputRed,
		  const int& inputGreen,
		  const int& inputBlue);
	/**
	 * Creates a new color that defaults to black
	 */
	Color();
	/**
	 * Destructor for the circle data type
	 */
	~Color();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Returns a string indicating this object's current status, and all objects it manages \n
	 * Should only be used for debugging
	 */
	std::string getStatusString() const;
	/**
	 * Static function to get a random color
	 * @return A color with random RGB values (0-255)
	 */
	static Color random();
	/**
	 * Randomizes the color objects RGB Values (0-255)
	 */
	void randomize();
	/**
	 * The red component of the color (int, 0-255)
	 */
	int red;
	/**
	 * The green component of the color (int, 0-255)
	 */
	int green;
	/**
	 * The blue component of the color (int, 0-255)
	 */
	int blue;
private:
};