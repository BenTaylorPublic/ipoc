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

enum ProgramState {
    LoadingMainMenu, MainMenu, Exiting
};

struct StorageGlobal {
    Font* font1;
    std::vector<Texture*> textures;
    Text* txtLoading;
    Text* txtProcessThreadUsage;
    int counterForThreadUsage;
    Sprite* sprCursor;
};

class Storage {
public:
    Storage();
    ~Storage();
    std::string getStatusString();

    ProgramState state = LoadingMainMenu;

    //GLOBAL    
    StorageGlobal* global;

    //state: MainMenu + LoadingMainMenu
    Text* txtCounter;
    unsigned int counter;
    bool windowToggleMode;
    OnscreenButton* btnTriggerOnUp;
    OnscreenButton* btnTriggerOnDown;
    OnscreenButton* btnTriggerOnHold;
    OnscreenButton* btnToggleWindowMode;
    OnscreenButton* btnExit;
};