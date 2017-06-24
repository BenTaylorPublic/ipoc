#include "IPOCSprite.h"
#include "Debug.h"

IPOCSprite::IPOCSprite(const std::string& inputName, IPOCTexture& inputTexture)
{
	name = inputName;
	sprite.setTexture(*inputTexture.getTexture());
	Debug::notifyOfConstruction(16);
}

IPOCSprite::IPOCSprite(const std::string& inputName, IPOCTexture& inputTexture, const int& inputZ)
{
	name = inputName;
	setZ(inputZ);
	sprite.setTexture(*inputTexture.getTexture());
	Debug::notifyOfConstruction(16);
}

IPOCSprite::~IPOCSprite()
{
	Debug::notifyOfDestruction(16);
}

void IPOCSprite::setPosition(const Point2D& newPoint)
{
	sprite.setPosition(sf::Vector2f(newPoint.x, newPoint.y));
}

Point2D IPOCSprite::getPosition()
{
	Point2D result;
	result.x = sprite.getPosition().x;
	result.y = sprite.getPosition().y;
	return result;
}

int IPOCSprite::getWidth()
{
	return sprite.getGlobalBounds().width;
}

int IPOCSprite::getHeight()
{
	return sprite.getGlobalBounds().height;
}

void IPOCSprite::draw(sf::RenderTarget& target)
{
	target.draw(sprite);
}

std::string IPOCSprite::getStatusString()
{
	return "Sprite name=" + name;
}
