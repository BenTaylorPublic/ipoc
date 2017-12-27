#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "Font.h"
#include "Drawable.h"

/*
IPOCText is a Data Type (Wrapper)
 */
class Text : public Drawable {
public:
    Text();
    Text(Font& inputFont);
    Text(Font& inputFont, const std::string& inputString);
    Text(Font& inputFont, const unsigned int& inputZ);
    Text(Font& inputFont, const unsigned int& inputZ, const std::string& inputString);
    Text(Font& inputFont, const std::string& inputString, const Point2D& point);
    Text(Font& inputFont, const unsigned int& inputZ, const Point2D& point);
    Text(Font& inputFont, const unsigned int& inputZ, const std::string& inputString, const Point2D& point);
    ~Text();
    Point2D getPosition() const; //Returns the current position of the text (TL)
    int getWidth() const; //Returns an integer which represents the width of the text in pixels
    int getHeight() const; //Returns an integer which represents the height of the text in pixels
    int getLength() const;
    void setPosition(const Point2D& newPosition) override; //Sets the position of the text, to the new provided position
    void setFont(Font& inputFont);
    void setText(const std::string& input); //Sets the string of the text, to the new provided string
    void addText(const std::string& input); //Adds to the string of the text, to the new provided string
    void draw(sf::RenderTarget& target) const override; //Draws the SFML Text to the provided SFML Render Target
    /*
    Returns a string indicating this object's current status, and all objects it manages.
    Should only be used for debugging, but not strictly.
     */
    std::string getStatusString() const;
private:
    sf::Text text; //SFML Text object that this class wraps
};