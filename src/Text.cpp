#include "Text.h"
#include "Debug.h"
#include "Settings.h"

Text::Text()
{
	setZIndex(DEFAULT_Z_VALUE);
	text.setString("SAMPLE TEXT");
	Debug::notifyOfConstruction(2);
}

Text::Text(Font& inputFont)
{
	setZIndex(DEFAULT_Z_VALUE);
	text.setFont(*inputFont.getFont());
	text.setString("SAMPLE TEXT");
	Debug::notifyOfConstruction(2);
}

Text::Text(Font& inputFont,
		   const std::string& inputString)
{
	setZIndex(DEFAULT_Z_VALUE);
	text.setFont(*inputFont.getFont());
	text.setString(inputString);
	Debug::notifyOfConstruction(2);
}

Text::Text(Font& inputFont,
		   const unsigned int& inputZ,
		   const std::string& inputString)
{
	text.setFont(*inputFont.getFont());
	text.setString(inputString);
	setZIndex(inputZ);
	Debug::notifyOfConstruction(2);
}

Text::Text(Font& inputFont,
		   const unsigned int& inputZ)
{
	text.setFont(*inputFont.getFont());
	text.setString("SAMPLE TEXT");
	setZIndex(inputZ);
	Debug::notifyOfConstruction(2);
}

Text::Text(Font& inputFont,
		   const std::string& inputString,
		   const Point2D& point)
{
	setZIndex(DEFAULT_Z_VALUE);
	text.setFont(*inputFont.getFont());
	text.setString(inputString);
	setPosition(point);
	Debug::notifyOfConstruction(2);
}

Text::Text(Font& inputFont,
		   const unsigned int& inputZ,
		   const std::string& inputString,
		   const Point2D& point)
{
	text.setFont(*inputFont.getFont());
	text.setString(inputString);
	setPosition(point);
	setZIndex(inputZ);
	Debug::notifyOfConstruction(2);
}

Text::Text(Font& inputFont,
		   const unsigned int& inputZ,
		   const Point2D& point)
{
	text.setFont(*inputFont.getFont());
	text.setString("SAMPLE TEXT");
	setPosition(point);
	setZIndex(inputZ);
	Debug::notifyOfConstruction(2);
}

Text::~Text()
{
	Debug::notifyOfDestruction(2);
}

Point2D Text::getPosition() const
{
	Point2D result;
	result.x = text.getPosition().x;
	result.y = text.getPosition().y;
	return result;
}

int Text::getWidth() const
{
	return text.getGlobalBounds().width;
}

int Text::getHeight() const
{
	return text.getGlobalBounds().height;
}

int Text::getLength() const
{
	return text.getString().getSize();
}

void Text::setPosition(const Point2D& newPosition)
{
	text.setPosition(sf::Vector2f(newPosition.x, newPosition.y));
}

void Text::setFont(Font& inputFont)
{
	text.setFont(*inputFont.getFont());
}

void Text::setText(const std::string& input)
{
	text.setString(input);
}

void Text::addText(const std::string& input)
{
	text.setString(text.getString() + input);
}

void Text::draw(sf::RenderTarget& target) const
{
	target.draw(text);
}

std::string Text::getStatusString() const
{
	return "Text=" + text.getString();
}