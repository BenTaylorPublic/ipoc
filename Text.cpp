#include "Text.h"
#include "Debug.h"

Text::Text(const std::string& inputName, Font& inputFont)
{
    text.setFont(*inputFont.getFont());
    text.setString("SAMPLE TEXT");
    name = inputName;
    Debug::notifyOfConstruction(14);
}

Text::Text(const std::string& inputName, Font& inputFont, const std::string& inputString)
{
    text.setFont(*inputFont.getFont());
    text.setString(inputString);
    name = inputName;
    Debug::notifyOfConstruction(14);
}

Text::Text(const std::string& inputName, Font& inputFont, const int& inputZ, const std::string& inputString)
{
    text.setFont(*inputFont.getFont());
    text.setString(inputString);
    setZ(inputZ);
    name = inputName;
    Debug::notifyOfConstruction(14);
}

Text::Text(const std::string& inputName, Font& inputFont, const int& inputZ)
{
    text.setFont(*inputFont.getFont());
    text.setString("SAMPLE TEXT");
    setZ(inputZ);
    name = inputName;
    Debug::notifyOfConstruction(14);
}

Text::Text(const std::string& inputName, Font& inputFont, const std::string& inputString, const Point2D& point)
{
    text.setFont(*inputFont.getFont());
    text.setString(inputString);
    setPosition(point);
    name = inputName;
    Debug::notifyOfConstruction(14);
}

Text::Text(const std::string& inputName, Font& inputFont, const int& inputZ, const std::string& inputString, const Point2D& point)
{
    text.setFont(*inputFont.getFont());
    text.setString(inputString);
    setPosition(point);
    setZ(inputZ);
    name = inputName;
    Debug::notifyOfConstruction(14);
}

Text::Text(const std::string& inputName, Font& inputFont, const int& inputZ, const Point2D& point)
{
    text.setFont(*inputFont.getFont());
    text.setString("SAMPLE TEXT");
    setPosition(point);
    setZ(inputZ);
    name = inputName;
    Debug::notifyOfConstruction(14);
}

Text::~Text()
{
    Debug::notifyOfDestruction(14);
}

Point2D Text::getPosition()
{
    Point2D result;
    result.x = text.getPosition().x;
    result.y = text.getPosition().y;
    return result;
}

int Text::getWidth()
{
    return text.getGlobalBounds().width;
}

int Text::getHeight()
{
    return text.getGlobalBounds().height;
}

int Text::getLength()
{
    return text.getString().getSize();
}

void Text::setPosition(const Point2D& newPosition)
{
    text.setPosition(sf::Vector2f(newPosition.x, newPosition.y));
}

void Text::setText(const std::string& input)
{
    text.setString(input);
}

void Text::addText(const std::string& input)
{
    text.setString(text.getString() + input);
}

void Text::draw(sf::RenderTarget& target)
{
    target.draw(text);
}

std::string Text::getStatusString()
{
    return "Sprite name=" + name + " text=" + text.getString();
}