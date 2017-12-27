
#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "Identifiable.h"

class Drawable : public Identifiable {
public:
    Drawable();
    virtual ~Drawable();
    int getZ() const;
    void setZ(const unsigned int& inputZ);
    virtual void draw(sf::RenderTarget& target) const = 0;
    virtual void setPosition(const Point2D& newPoint) = 0;
private:
    int z = 0;
};