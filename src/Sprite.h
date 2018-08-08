#pragma once

#include <string>
#include "Point2D.h"
#include "Texture.h"
#include <SFML/Graphics.hpp>
#include "Drawable.h"

/*
IPOCSprite is a Data Type (Wrapper)
 */
class Sprite : public Drawable
{
public:
	Sprite();
	Sprite(Texture& inputTexture);
	Sprite(Texture& inputTexture,
		   const unsigned int& inputZ);
	~Sprite();
	void setTexture(Texture& inputTexture);
	void setPosition(const Point2D& newPoint) override; //Sets the position of the sprite, to the new provided position
	Point2D getPosition() const; //Returns the current position of the text (TL)
	int getWidth() const; //Returns an integer which represents the width of the sprite in pixels
	int getHeight() const; //Returns an integer which represents the height of the sprite in pixels
	void draw(sf::RenderTarget& target) const override; //Draws the SFML Sprite to the provided SFML Render Target
	/*
	Returns a string indicating this object's current status, and all objects it manages.
	Should only be used for debugging, but not strictly.
	 */
	std::string getStatusString() const;
private:
	sf::Sprite sprite; //SFML Sprite object that this class wraps
};