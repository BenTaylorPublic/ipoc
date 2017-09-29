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
    Text txtProcessThreadUsage;
    int counterForThreadUsage;
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

struct StorageShapeFun {
    Rectangle* rectangle;
    std::vector<Rectangle*> rectangles;
    bool settingRectangleSize;
    OnscreenButton btnClear;
};

class Storage {
public:
    Storage();
    ~Storage();
    std::string getStatusString();

    ProgramState state;
    ProgramStateLevel2 state2;

    StorageGlobal* global;
    StorageButtonTesting* buttonTesting;
    StorageShapeFun* shapeFun;
    
};