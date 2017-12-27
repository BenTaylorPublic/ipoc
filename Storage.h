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
#include "AnimatedSprite.h"

enum ProgramState {
    FirstLoad, ButtonTesting, ShapeFun, Exiting
};

enum ProgramStateLevel2 {
    Safe, Loading
};

struct StorageGlobal {
    Font font1;
    std::vector<Texture*> textures;
    Text txtLoading;
    Sprite sprCursor;
    OnscreenButton btnButtonTesting;
    OnscreenButton btnShapeFun;
};

struct StorageButtonTesting {
    Text txtCounter;
    unsigned int counter;
    bool windowToggleMode;
    OnscreenButton btnTriggerOnUp;
    OnscreenButton btnTriggerOnDown;
    OnscreenButton btnTriggerOnHold;
    OnscreenButton btnToggleWindowMode;
};

enum shapeFunMode {
    RectangleMode, CircleMode, LineMode
};

struct StorageShapeFun {
    Rectangle* rectangle;
    std::vector<Rectangle*> rectangles;
    bool settingRectangleSize;

    Circle* circle;
    std::vector<Circle*> circles;
    bool settingCircleSize;
    Point2D circleCenter;

    Line* line;
    std::vector<Line*> lines;
    bool settingLineSize;

    shapeFunMode mode;

    OnscreenButton btnClear;
};

class Storage {
public:
    Storage();
    ~Storage();
    std::string getStatusString() const;

    ProgramState state;
    ProgramStateLevel2 state2;

    StorageGlobal* global;
    StorageButtonTesting* buttonTesting;
    StorageShapeFun* shapeFun;
    
    AnimatedSprite* thing;
    Rectangle* rec1;
    Rectangle* rec2;
    Rectangle* rec3;
    Rectangle* rec4;
};