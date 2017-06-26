#include "IPOCText.h"
#include "Debug.h"

IPOCText::IPOCText(const std::string& inputName, Font& inputFont)
{
	text.setFont(*inputFont.getFont());
	text.setString("SAMPLE TEXT");
	name = inputName;
	Debug::notifyOfConstruction(14);
}

IPOCText::IPOCText(const std::string& inputName, Font& inputFont, const std::string& inputString)
{
	text.setFont(*inputFont.getFont());
	text.setString(inputString);
	name = inputName;
	Debug::notifyOfConstruction(14);
}

IPOCText::IPOCText(const std::string& inputName, Font& inputFont, const int& inputZ, const std::string& inputString)
{
	text.setFont(*inputFont.getFont());
	text.setString(inputString);
	setZ(inputZ);
	name = inputName;
	Debug::notifyOfConstruction(14);
}

IPOCText::IPOCText(const std::string& inputName, Font& inputFont, const int& inputZ)
{
	text.setFont(*inputFont.getFont());
	text.setString("SAMPLE TEXT");
	setZ(inputZ);
	name = inputName;
	Debug::notifyOfConstruction(14);
}

IPOCText::IPOCText(const std::string& inputName, Font& inputFont, const std::string& inputString, const Point2D& point)
{
	text.setFont(*inputFont.getFont());
	text.setString(inputString);
	setPosition(point);
	name = inputName;
	Debug::notifyOfConstruction(14);
}

IPOCText::IPOCText(const std::string& inputName, Font& inputFont, const int& inputZ, const std::string& inputString, const Point2D& point)
{
	text.setFont(*inputFont.getFont());
	text.setString(inputString);
	setPosition(point);
	setZ(inputZ);
	name = inputName;
	Debug::notifyOfConstruction(14);
}

IPOCText::IPOCText(const std::string& inputName, Font& inputFont, const int& inputZ, const Point2D& point)
{
	text.setFont(*inputFont.getFont());
	text.setString("SAMPLE TEXT");
	setPosition(point);
	setZ(inputZ);
	name = inputName;
	Debug::notifyOfConstruction(14);
}

IPOCText::~IPOCText()
{
	Debug::notifyOfDestruction(14);
}

Point2D IPOCText::getPosition()
{
	Point2D result;
	result.x = text.getPosition().x;
	result.y = text.getPosition().y;
	return result;
}

int IPOCText::getWidth()
{
	return text.getGlobalBounds().width;
}

int IPOCText::getHeight()
{
	return text.getGlobalBounds().height;
}

int IPOCText::getLength()
{
	return text.getString().getSize();
}

void IPOCText::setPosition(const Point2D& newPosition)
{
	text.setPosition(sf::Vector2f(newPosition.x, newPosition.y));
}

void IPOCText::setText(const string& input)
{
	text.setString(input);
}

void IPOCText::addText(const string& input)
{
	text.setString(text.getString() + input);
}

void IPOCText::draw(sf::RenderTarget& target)
{
	target.draw(text);
}

std::string IPOCText::getStatusString()
{
	return "Sprite name=" + name + " text=" + text.getString();
}