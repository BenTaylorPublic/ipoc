#pragma once

#include <string>
#include <SFML/Graphics.hpp>

/*
IPOCFont is a Data Type (Wrapper)
 */
class Font
{
public:
	Font();
	Font(const std::string& inputName,
		 const std::string& fileName);
	~Font();
	void loadFont(const std::string& inputName,
				  const std::string& fileName);
	std::string name; //Name that is mainly used for debugging
	/*
	Returns a string indicating this object's current status, and all objects it manages.
	Should only be used for debugging, but not strictly.
	 */
	std::string getStatusString() const;
	const sf::Font*
	getFont() const; //Should strictly be used for creating new Text objects. AKA don't use this you fuck
private:
	sf::Font font; //SFML Font object that this class wraps
};