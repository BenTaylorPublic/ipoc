#include "Rectangle.h"
#include "Debug.h"

Rectangle::Rectangle()
{
    Debug::notifyOfConstruction(8);
}

Rectangle::~Rectangle()
{
    Debug::notifyOfConstruction(8);
}

void Rectangle::draw(sf::RenderTarget& target)
{
    Debug::writeLine("RECTANGLE DRAW");
}

void Rectangle::setPosition(const Point2D& newPoint)
{
    Debug::writeLine("RECTANGLE SET POSITION");
}