#include "Rectangle.h"
#include "Debug.h"

Rectangle::Rectangle()
{
    Debug::notifyOfConstruction(8);
}

Rectangle::~Rectangle()
{
    Debug::notifyOfDestruction(8);
}

void Rectangle::setSize(const int& width, const int& height)
{
    rectangle.setSize(sf::Vector2f(width, height));
}

void Rectangle::setColor(const Color& color)
{
    rectangle.setFillColor(sf::Color(color.r, color.g, color.b));
}

void Rectangle::draw(sf::RenderTarget& target)
{
    target.draw(rectangle);
}

void Rectangle::setPosition(const Point2D& newPoint)
{
    rectangle.setPosition(sf::Vector2f(newPoint.x, newPoint.y));
}

void Rectangle::setCornerOne(const Point2D& newPoint)
{
    rectangle.setPosition(sf::Vector2f(newPoint.x, newPoint.y));
}

void Rectangle::setCornerTwo(const Point2D& newPoint)
{
    rectangle.setSize(sf::Vector2f(newPoint.x - rectangle.getPosition().x, newPoint.y - rectangle.getPosition().y));
}