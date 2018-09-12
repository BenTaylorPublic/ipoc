#pragma once

#include <string>
#include <SFML/Graphics.hpp>

/**
 * IPOCFont is a Data Type (Wrapper)
 */
class Font
{
public:
	/**
	 * Constructor for a Font
	 */
	Font();
	/**
	 * Constructor for a font, which takes setup values \n
	 * Used as an alternative to loadFont()
	 * @param inputName name for the font
	 * @param fileName file name (not file path, that's grabbed from Settings)
	 */
	Font(const std::string& inputName,
		 const std::string& fileName);
	/**
	 * Destructor for a font
	 */
	~Font();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Used by IPOC when creating a new Text object
	 * @return SFML Font
	 */
	const sf::Font* getFont() const;
	/**
	 * Returns a string indicating this object's current status, and all objects it manages.
	 * Should only be used for debugging, but not strictly.
	 * @return status string
	 */
	std::string getStatusString() const;
	/**
	 * Loads the font
	 * @param inputName name for the font
	 * @param fileName file name (not file path, that's grabbed from Settings)
	 */
	void loadFont(const std::string& inputName,
				  const std::string& fileName);
	/**
	 * Name that is mainly used for debugging
	 */
	std::string name;
private:
	/**
	 * SFML Font object that this class wraps
	 */
	sf::Font font;
};