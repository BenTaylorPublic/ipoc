#include "Line.h"
#include "Debug.h"
#include "Settings.h"

Line::Line()
{
	setZIndex(DEFAULT_Z_VALUE);
	Debug::notifyOfConstruction(10);
}

Line::~Line()
{
	Debug::notifyOfDestruction(10);
}

void Line::draw(sf::RenderTarget& target) const
{
	target.draw(line, 2, sf::Lines);
}

void Line::setPosition(const Point2D& newPoint)
{
	line[0].position.x = newPoint.x;
	line[0].position.y = newPoint.y;
}

void Line::setPosition2(const Point2D& newPoint)
{
	line[1].position.x = newPoint.x;
	line[1].position.y = newPoint.y;
}

void Line::setColor(const Color& color)
{
	sf::Color newColor(color.r, color.g, color.b);

	line[0].color = newColor;
	line[1].color = newColor;
}