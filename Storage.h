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
    Text* tLoading;    
    Sprite* sCursor;
    
    //state: MainMenu + LoadingMainMenu
    Text* tCounter;
    int counter;
    OnscreenButton* bTriggerOnUp;
    OnscreenButton* bTriggerOnDown;
    OnscreenButton* bTriggerOnHold;
    OnscreenButton* bExit;
};