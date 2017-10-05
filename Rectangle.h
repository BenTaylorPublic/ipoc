#pragma once
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Point2D.h"
#include "Color.h"

class Rectangle : public Drawable {
public:
    Rectangle();
    ~Rectangle();
    void setSize(const int& width, const int& height);
    void setColor(const Color& color);
    void draw(sf::RenderTarget& target) override;
    void setPosition(const Point2D& newPoint) override;
    void setCornerOne(const Point2D& newPoint);
    void setCornerTwo(const Point2D& newPoint);
private:
    sf::RectangleShape rectangle;
};