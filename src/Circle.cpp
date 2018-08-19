#include "Circle.h"
#include "Debug.h"
#include "Settings.h"

Circle::Circle()
{
	setZIndex(DEFAULT_Z_VALUE);
	Debug::notifyOfConstruction(9);
}

Circle::~Circle()
{
	Debug::notifyOfDestruction(9);
}

void Circle::draw(sf::RenderTarget& target) const
{
	target.draw(circle);
}

void Circle::setCenter(const Point2D& newPoint)
{
	circle.setPosition(sf::Vector2f(newPoint.x - circle.getRadius(), newPoint.y - circle.getRadius()));
}

void Circle::setColor(const Color& color)
{
	circle.setFillColor(sf::Color(color.red, color.green, color.blue));
}

void Circle::setPointCount(const int& pointCount)
{
	circle.setPointCount(pointCount);
}

void Circle::setPosition(const Point2D& newPoint)
{
	circle.setPosition(sf::Vector2f(newPoint.x, newPoint.y));
}

void Circle::setRadius(const int& radius)
{
	circle.setRadius(radius);
}