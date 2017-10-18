#include "Line.h"
#include "Debug.h"
#include "Settings.h"

Line::Line()
{
    setZ(DEFAULT_Z_VALUE);
    Debug::notifyOfConstruction(10);
}

Line::~Line()
{
    Debug::notifyOfDestruction(10);
}

void Line::draw(sf::RenderTarget& target)
{
    target.draw(line, 2, sf::Lines);
}

void Line::setPosition(const Point2D& newPoint)
{
    line[0] = sf::Vector2f(newPoint.x, newPoint.y);
}

void Line::setPosition2(const Point2D& newPoint)
{
    line[1] = sf::Vector2f(newPoint.x, newPoint.y);
}

void Line::setColor(const Color& color)
{
//    line.Color = sf::Color(color.r, color.g, color.b);
}