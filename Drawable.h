
#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"

class Drawable {
public:

    virtual ~Drawable() {
    };
    int getZ();
    void setZ(const unsigned int& inputZ);
    void setFrameId(const unsigned int& inputFrameId);
    const unsigned int& getFrameId();
    virtual void draw(sf::RenderTarget& target) = 0;
    virtual void setPosition(const Point2D& newPoint) = 0;
private:
    int z = 0;
    unsigned int frameId = 0;
};