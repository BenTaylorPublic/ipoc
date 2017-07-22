
#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"

class Drawable
{
public:
    virtual ~Drawable() {};
    int getZ();
    void setZ(const int& inputZ);
    void setFrameId(const int& inputFrameId);
    const int& getFrameId();
    virtual void draw(sf::RenderTarget& target) = 0;
    virtual void setPosition(const Point2D& newPoint) = 0;
private:
    int z = 0;
    int frameId = -1;    
};