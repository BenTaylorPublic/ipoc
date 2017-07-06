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

enum ProgramState {LoadingMainMenu, MainMenu, Exiting, SaveScreen};

class Storage
{
public:
    Storage();
    ~Storage();
    std::string getStatusString();
    
    ProgramState state = LoadingMainMenu;
    
    //GLOBAL    
    Font* font1;
    std::vector<Texture*> textures;
    Text* txtLoading;    
    Sprite* sprCursor;
    
    //state: MainMenu + LoadingMainMenu
    Text* txtCounter;
    int counter;
    OnscreenButton* btnTriggerOnUp;
    OnscreenButton* btnTriggerOnDown;
    OnscreenButton* btnTriggerOnHold;
    OnscreenButton* btnExit;
};