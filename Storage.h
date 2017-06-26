#pragma once
#include <string>
#include <vector>
#include "Point2D.h"
#include "Color.h"
#include "Font.h"
#include "IPOCText.h"
#include "IPOCTexture.h"
#include "IPOCSprite.h"
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
    vector<IPOCTexture*> textures;
    IPOCText* textLoading;    
    IPOCSprite* spriteCursor;
    
    //state: MainMenu + LoadingMainMenu
    IPOCText* textHeading;
    OnscreenButton* buttonPlay;
    OnscreenButton* buttonOptions;
    OnscreenButton* buttonExitGame;
    
    //state: SaveScreen
    OnscreenButton* buttonSave1;
    OnscreenButton* buttonSave2;
    OnscreenButton* buttonSave3;
    OnscreenButton* buttonSave4;
};