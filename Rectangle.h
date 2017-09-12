#pragma once
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Point2D.h"

class Rectangle : public Drawable {
public:
    Rectangle();
    ~Rectangle();
    void draw(sf::RenderTarget& target) override;
    void setPosition(const Point2D& newPoint) override;
private:
};