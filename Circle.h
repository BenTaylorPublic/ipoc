#pragma once
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Point2D.h"
#include "Color.h"

class Circle : public Drawable{
public:
    Circle();
    ~Circle();
    void draw(sf::RenderTarget& target) override;
    void setPosition(const Point2D& newPoint) override;
    void setCenter(const Point2D& newPoint);
    void setRadius(const int& radius);
    void setColor(const Color& color);
private:
    sf::CircleShape circle;
};