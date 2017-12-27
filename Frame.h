#pragma once

#include <string>
#include <vector>
#include "Drawable.h"
#include "View.h"
#include <SFML/Graphics.hpp>

class Frame {
public:
    Frame();
    ~Frame();
    void IPOCLoad();
    void markAsDrawable();
    bool isDrawable() const;
    void addToFrame(Drawable* drawable);
    void removeFromFrame(Drawable* drawable);
    void drawAll(sf::RenderTarget& target);
    std::string getStatusString() const;
private:
    std::vector<View*> views;
    bool isDrawableBool;
};