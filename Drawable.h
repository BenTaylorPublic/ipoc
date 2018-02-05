
#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "Identifiable.h"

class Drawable : public Identifiable {
public:
    Drawable();
    virtual ~Drawable();
    unsigned int getZIndex() const;
    void setZIndex(const unsigned int& inputZIndex);
    unsigned int getViewIndex() const;
    void setViewIndex(const unsigned int& inputViewIndex);
    virtual void draw(sf::RenderTarget& target) const = 0;
    virtual void setPosition(const Point2D& newPoint) = 0;
private:
    unsigned int zIndex = 0;
    unsigned int viewIndex = 0;
    
};