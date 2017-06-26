#pragma once

#include <string>
#include "Point2D.h"
#include "IPOCTexture.h"
#include <SFML/Graphics.hpp>
#include "Drawable.h"

/*
IPOCSprite is a Data Type (Wrapper)
*/
class IPOCSprite : public Drawable
{
public:
    IPOCSprite(const string& inputName, IPOCTexture& inputTexture);
    IPOCSprite(const string& inputName, IPOCTexture& inputTexture, const int& inputZ);
    ~IPOCSprite();
    std::string name; //Name that is mainly used for debugging
    void setPosition(const Point2D& newPoint) override; //Sets the position of the sprite, to the new provided position
    Point2D getPosition(); //Returns the current position of the text (TL)
    int getWidth(); //Returns an integer which represents the width of the sprite in pixels
    int getHeight(); //Returns an integer which represents the height of the sprite in pixels
    void draw(sf::RenderTarget& target) override; //Draws the SFML Sprite to the provided SFML Render Target
    /*
    Returns a string indicating this object's current status, and all objects it manages.
    Should only be used for debugging, but not strictly.
    */
    std::string getStatusString();
private:    
    sf::Sprite sprite; //SFML Sprite object that this class wraps
};