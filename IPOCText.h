#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "IPOCFont.h"
#include "IPOCDrawable.h"

/*
IPOCText is a Data Type (Wrapper)
*/
class IPOCText : public IPOCDrawable
{
public:
    IPOCText(const std::string& inputName, IPOCFont& inputFont);
    IPOCText(const std::string& inputName, IPOCFont& inputFont, const std::string& inputString);
    IPOCText(const std::string& inputName, IPOCFont& inputFont, const int& inputZ);
    IPOCText(const std::string& inputName, IPOCFont& inputFont, const int& inputZ, const std::string& inputString);
    IPOCText(const std::string& inputName, IPOCFont& inputFont, const std::string& inputString, const Point2D& point);
    IPOCText(const std::string& inputName, IPOCFont& inputFont, const int& inputZ, const Point2D& point);
    IPOCText(const std::string& inputName, IPOCFont& inputFont, const int& inputZ, const std::string& inputString, const Point2D& point);
    ~IPOCText();
    std::string name; //Name that is mainly used for debugging
    Point2D getPosition(); //Returns the current position of the text (TL)
    int getWidth(); //Returns an integer which represents the width of the text in pixels
    int getHeight(); //Returns an integer which represents the height of the text in pixels
    int getLength();
    void setPosition(const Point2D& newPosition) override; //Sets the position of the text, to the new provided position
    void setText(const string& input); //Sets the string of the text, to the new provided string
    void addText(const string& input); //Adds to the string of the text, to the new provided string
    void draw(sf::RenderTarget& target) override; //Draws the SFML Text to the provided SFML Render Target
    /*
    Returns a string indicating this object's current status, and all objects it manages.
    Should only be used for debugging, but not strictly.
    */
    std::string getStatusString();
private:
    sf::Text text; //SFML Text object that this class wraps
};