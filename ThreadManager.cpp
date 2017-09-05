#include "ThreadManager.h"
#include "Debug.h"
#include "Settings.h"

ThreadManager::ThreadManager()
{
    Debug::notifyOfConstruction(19);
}

ThreadManager::~ThreadManager()
{
    Debug::notifyOfDestruction(19);
}

void ThreadManager::IPOCLoad(Storage* inputStorage, Frame* inputFrame, InputController* inputInputController)
{
    storage = inputStorage;
    frame = inputFrame;
    inputController = inputInputController;
}

std::string ThreadManager::getStatusString()
{
    return "N/A";
}

void ThreadManager::loadMainMenuStart()
{
    loadMainMenuJoinable = false;
    loadMainMenuThread = new std::thread(&ThreadManager::loadMainMenu, this);
    Debug::logLine("[INFO] loadMainMenuThread started");
}

void ThreadManager::loadMainMenuJoin()
{
    loadMainMenuThread->join();
    delete loadMainMenuThread;
    Debug::logLine("[INFO] loadMainMenuThread joined");
}

void ThreadManager::loadMainMenu()
{

    //-----------------------------------------------------------------GLOBAL
    storage->global = new StorageGlobal;
    
    //Fonts
    storage->global->font1.loadFont("test font", "courier new.ttf");
    
    //Loading screen
    storage->global->txtLoading.name = "loading text";
    storage->global->txtLoading.setFont(storage->global->font1);
    storage->global->txtLoading.setPosition(Point2D(100, 700));
    frame->addToFrame(&storage->global->txtLoading);
    frame->markAsDrawable();
    
    //Variables
    storage->global->counterForThreadUsage = 0;
    
    //Textures
    storage->global->textures.push_back(new Texture("test texture", "default texture.png"));
    storage->global->textures.push_back(new Texture("circle texture", "mouse circle.png"));
    storage->global->textures.push_back(new Texture("button up texture", "button up.png"));
    storage->global->textures.push_back(new Texture("button down texture", "button down.png"));
    storage->global->textures.push_back(new Texture("cursor texture", "cursor.png"));
    
    storage->global->txtProcessThreadUsage.name = "process thread usage text";
    storage->global->txtProcessThreadUsage.setFont(storage->global->font1);
    storage->global->txtProcessThreadUsage.setPosition(Point2D(500, 500));

    //Sprites
    storage->global->sprCursor.name = "cursor sprite";
    storage->global->sprCursor.setTexture(*storage->global->textures[4]);
    storage->global->sprCursor.setZ(2);
    
    //-----------------------------------------------------------------BUTTON TESTING
    storage->buttonTesting = new StorageButtonTesting;
    
    //Variables
    storage->buttonTesting->counter = 0;
    storage->buttonTesting->windowToggleMode = true;
    
    //Texts
    storage->buttonTesting->txtCounter.name = "counter text";
    storage->buttonTesting->txtCounter.setFont(storage->global->font1);
    storage->buttonTesting->txtCounter.setZ(0);
    storage->buttonTesting->txtCounter.setText("0");
    storage->buttonTesting->txtCounter.setPosition(Point2D(20,20));
    //Buttons
    //Buttons - TriggerOnUp
    storage->buttonTesting->btnTriggerOnUp.setButtonTriggerType(TriggerOnUp);
    storage->buttonTesting->btnTriggerOnUp.setZ(1);
    storage->buttonTesting->btnTriggerOnUp.setPosition(Point2D(20, 100));
    storage->buttonTesting->btnTriggerOnUp.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->buttonTesting->btnTriggerOnUp.addToUp(new Sprite("trigger on up up sprite", *storage->global->textures[2]));
    storage->buttonTesting->btnTriggerOnUp.addToUp(new Text("trigger on up up text", storage->global->font1, "Trigger On Up"), Point2D(20, 30));
    storage->buttonTesting->btnTriggerOnUp.addToDown(new Sprite("trigger on up down sprite", *storage->global->textures[3]));
    storage->buttonTesting->btnTriggerOnUp.addToDown(new Text("trigger on up down text", storage->global->font1, "Trigger On Up"), Point2D(20, 37));
    inputController->addOnscreenButton(&storage->buttonTesting->btnTriggerOnUp);

    //Buttons - TriggerOnDown
    storage->buttonTesting->btnTriggerOnDown.setButtonTriggerType(TriggerOnDown);
    storage->buttonTesting->btnTriggerOnDown.setZ(1);
    storage->buttonTesting->btnTriggerOnDown.setPosition(Point2D(20, 260));
    storage->buttonTesting->btnTriggerOnDown.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->buttonTesting->btnTriggerOnDown.addToUp(new Sprite("trigger on down up sprite", *storage->global->textures[2]));
    storage->buttonTesting->btnTriggerOnDown.addToUp(new Text("trigger on down up text", storage->global->font1, "Trigger On Down"), Point2D(20, 30));
    storage->buttonTesting->btnTriggerOnDown.addToDown(new Sprite("trigger on down down sprite", *storage->global->textures[3]));
    storage->buttonTesting->btnTriggerOnDown.addToDown(new Text("trigger on down down text", storage->global->font1, "Trigger On Down"), Point2D(20, 37));
    inputController->addOnscreenButton(&storage->buttonTesting->btnTriggerOnDown);

    //Buttons - TriggerOnHold
    storage->buttonTesting->btnTriggerOnHold.setButtonTriggerType(TriggerOnHold);
    storage->buttonTesting->btnTriggerOnHold.setZ(1);
    storage->buttonTesting->btnTriggerOnHold.setPosition(Point2D(20, 420)); //blaze it
    storage->buttonTesting->btnTriggerOnHold.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->buttonTesting->btnTriggerOnHold.addToUp(new Sprite("trigger on hold up sprite", *storage->global->textures[2]));
    storage->buttonTesting->btnTriggerOnHold.addToUp(new Text("trigger on hold up text", storage->global->font1, "Trigger On Hold"), Point2D(20, 30));
    storage->buttonTesting->btnTriggerOnHold.addToDown(new Sprite("trigger on hold down sprite", *storage->global->textures[3]));
    storage->buttonTesting->btnTriggerOnHold.addToDown(new Text("trigger on hold down text", storage->global->font1, "Trigger On Hold"), Point2D(20, 37));
    inputController->addOnscreenButton(&storage->buttonTesting->btnTriggerOnHold);

    //Buttons - ToggleWindowMode
    storage->buttonTesting->btnToggleWindowMode.setButtonTriggerType(TriggerOnUp);
    storage->buttonTesting->btnToggleWindowMode.setZ(1);
    storage->buttonTesting->btnToggleWindowMode.setPosition(Point2D(340, 100));
    storage->buttonTesting->btnToggleWindowMode.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->buttonTesting->btnToggleWindowMode.addToUp(new Sprite("toggle window mode up sprite", *storage->global->textures[2]));
    storage->buttonTesting->btnToggleWindowMode.addToUp(new Text("toggle window mode up text", storage->global->font1, "Toggle Window"), Point2D(20, 30));
    storage->buttonTesting->btnToggleWindowMode.addToDown(new Sprite("toggle window mode down sprite", *storage->global->textures[3]));
    storage->buttonTesting->btnToggleWindowMode.addToDown(new Text("toggle window mode down text", storage->global->font1, "Toggle Window"), Point2D(20, 37));
    inputController->addOnscreenButton(&storage->buttonTesting->btnToggleWindowMode);

    //Buttons - Exit
    storage->buttonTesting->btnExit.setButtonTriggerType(TriggerOnUp);
    storage->buttonTesting->btnExit.setZ(1);
    storage->buttonTesting->btnExit.setPosition(Point2D(20, 580));
    storage->buttonTesting->btnExit.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->buttonTesting->btnExit.addToUp(new Sprite("exit button up sprite", *storage->global->textures[2]));
    storage->buttonTesting->btnExit.addToUp(new Text("exit button up text", storage->global->font1, "Exit"), Point2D(20, 30));
    storage->buttonTesting->btnExit.addToDown(new Sprite("exit button down sprite", *storage->global->textures[3]));
    storage->buttonTesting->btnExit.addToDown(new Text("exit button down text", storage->global->font1, "Exit"), Point2D(20, 37));
    inputController->addOnscreenButton(&storage->buttonTesting->btnExit);


    
    //-----------------------------------------------------------------ADDING TO FRAME
    //Remove loading screen
    frame->removeFromFrame(&storage->global->txtLoading);
    //Add button testing
    frame->addToFrame(&storage->buttonTesting->txtCounter);
    frame->addToFrame(&storage->global->sprCursor);
    frame->addToFrame(&storage->buttonTesting->btnTriggerOnUp);
    frame->addToFrame(&storage->buttonTesting->btnTriggerOnDown);
    frame->addToFrame(&storage->buttonTesting->btnTriggerOnHold);
    frame->addToFrame(&storage->buttonTesting->btnToggleWindowMode);
    frame->addToFrame(&storage->buttonTesting->btnExit);
    if (Settings::debugMode)
	frame->addToFrame(&storage->global->txtProcessThreadUsage);

    loadMainMenuJoinable = true;
}

void ThreadManager::exitCleanUpStart()
{
    exitCleanUpJoinable = false;
    exitCleanUpThread = new std::thread(&ThreadManager::exitCleanUp, this);
    Debug::logLine("[INFO] exitCleanUpThread started");
}

void ThreadManager::exitCleanUpJoin()
{
    exitCleanUpThread->join();
    delete exitCleanUpThread;
    Debug::logLine("[INFO] exitCleanUpThread joined");
}

void ThreadManager::exitCleanUp()
{
    frame->removeFromFrame(&storage->buttonTesting->txtCounter);
    frame->removeFromFrame(&storage->buttonTesting->btnTriggerOnHold);
    frame->removeFromFrame(&storage->buttonTesting->btnTriggerOnDown);
    frame->removeFromFrame(&storage->buttonTesting->btnTriggerOnUp);
    frame->removeFromFrame(&storage->buttonTesting->btnToggleWindowMode);
    frame->removeFromFrame(&storage->buttonTesting->btnExit);
    frame->removeFromFrame(&storage->global->txtProcessThreadUsage);

    frame->removeFromFrame(&storage->global->txtLoading);
    frame->removeFromFrame(&storage->global->sprCursor);
    
    for (Texture* it : storage->global->textures)
    {
	delete it;
    }
    storage->global->textures.clear();

    delete storage->buttonTesting;
    delete storage->global;

    exitCleanUpJoinable = true;
}