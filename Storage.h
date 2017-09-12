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
    OnscreenButton btnExit;
};

struct StorageShapeFun {
    Rectangle rectangle;
};

class Storage {
public:
    Storage();
    ~Storage();
    std::string getStatusString();

    ProgramState state;

    StorageGlobal* global;
    StorageButtonTesting* buttonTesting;
    StorageShapeFun* shapeFun;
    
};