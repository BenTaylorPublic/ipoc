#pragma once
#include <string>
#include <vector>
#include "Point2D.h"
#include "Color.h"
#include "Font.h"
#include "Text.h"
#include "Texture.h"
#include "Sprite.h"
#include "OnscreenButton.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"

class Storage {
public:
    Storage();
    ~Storage();
    std::string getStatusString() const;
};