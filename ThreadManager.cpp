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

void ThreadManager::IPOCLoad(Storage* inputStorage, Frame* inputFrame, OnscreenButtonManager* inputOnscreenButtonManager)
{
    storage = inputStorage;
    frame = inputFrame;
    onscreenButtonManager = inputOnscreenButtonManager;
}

std::string ThreadManager::getStatusString()
{
    return "N/A";
}

void ThreadManager::loadMainMenuStart()
{
    loadMainMenuJoinable = false;
    loadMainMenu = new std::thread(&ThreadManager::loadMainMenuThread, this);
    Debug::log("[INFO] loadMainMenuThread started");
    Debug::commitLogLine();
}

void ThreadManager::loadMainMenuJoin()
{
    loadMainMenu->join();
    delete loadMainMenu;
    Debug::log("[INFO] loadMainMenuThread joined");
    Debug::commitLogLine();
}

void ThreadManager::loadMainMenuThread()
{
    //Fonts
    storage->font1 = new Font("test font", "courier new.ttf");

    //Loading screen
    storage->txtLoading = new Text("loading text", *storage->font1, 0, "Loading...", Point2D(100, 700));
    frame->addToFrame(storage->txtLoading);
    frame->markAsDrawable();
    
    storage->windowToggleMode = true;

    //Textures
    storage->textures.push_back(new Texture("test texture", "default texture.png"));
    storage->textures.push_back(new Texture("circle texture", "mouse circle.png"));
    storage->textures.push_back(new Texture("button up texture", "button up.png"));
    storage->textures.push_back(new Texture("button down texture", "button down.png"));
    storage->textures.push_back(new Texture("cursor texture", "cursor.png"));

    //Texts
    storage->txtCounter = new Text("counter text", *storage->font1, 0, "0", Point2D(20, 20));
    storage->counter = 0;

    //Sprites
    storage->sprCursor = new Sprite("cursor sprite", *storage->textures[4], 2);

    //Buttons
    //Buttons - TriggerOnUp
    storage->btnTriggerOnUp = new OnscreenButton(TriggerOnUp, 1, Point2D(20, 100));
    storage->btnTriggerOnUp->setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->btnTriggerOnUp->addToUp(new Sprite("trigger on up up sprite", *storage->textures[2]));
    storage->btnTriggerOnUp->addToUp(new Text("trigger on up up text", *storage->font1, "Trigger On Up"), Point2D(20, 30));
    storage->btnTriggerOnUp->addToDown(new Sprite("trigger on up down sprite", *storage->textures[3]));
    storage->btnTriggerOnUp->addToDown(new Text("trigger on up down text", *storage->font1, "Trigger On Up"), Point2D(20, 37));
    onscreenButtonManager->addOnscreenButton(storage->btnTriggerOnUp);

    //Buttons - TriggerOnDown
    storage->btnTriggerOnDown = new OnscreenButton(TriggerOnDown, 1, Point2D(20, 260));
    storage->btnTriggerOnDown->setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->btnTriggerOnDown->addToUp(new Sprite("trigger on down up sprite", *storage->textures[2]));
    storage->btnTriggerOnDown->addToUp(new Text("trigger on down up text", *storage->font1, "Trigger On Down"), Point2D(20, 30));
    storage->btnTriggerOnDown->addToDown(new Sprite("trigger on down down sprite", *storage->textures[3]));
    storage->btnTriggerOnDown->addToDown(new Text("trigger on down down text", *storage->font1, "Trigger On Down"), Point2D(20, 37));
    onscreenButtonManager->addOnscreenButton(storage->btnTriggerOnDown);

    //Buttons - TriggerOnHold
    storage->btnTriggerOnHold = new OnscreenButton(TriggerOnHold, 1, Point2D(20, 420));
    storage->btnTriggerOnHold->setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->btnTriggerOnHold->addToUp(new Sprite("trigger on hold up sprite", *storage->textures[2]));
    storage->btnTriggerOnHold->addToUp(new Text("trigger on hold up text", *storage->font1, "Trigger On Hold"), Point2D(20, 30));
    storage->btnTriggerOnHold->addToDown(new Sprite("trigger on hold down sprite", *storage->textures[3]));
    storage->btnTriggerOnHold->addToDown(new Text("trigger on hold down text", *storage->font1, "Trigger On Hold"), Point2D(20, 37));
    onscreenButtonManager->addOnscreenButton(storage->btnTriggerOnHold);
    
    //Buttons - ToggleWindowMode
    storage->btnToggleWindowMode = new OnscreenButton(TriggerOnUp, 1, Point2D(340, 100));
    storage->btnToggleWindowMode->setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->btnToggleWindowMode->addToUp(new Sprite("toggle window mode up sprite", *storage->textures[2]));
    storage->btnToggleWindowMode->addToUp(new Text("toggle window mode up text", *storage->font1, "Toggle Window"), Point2D(20, 30));
    storage->btnToggleWindowMode->addToDown(new Sprite("toggle window mode down sprite", *storage->textures[3]));
    storage->btnToggleWindowMode->addToDown(new Text("toggle window mode down text", *storage->font1, "Toggle Window"), Point2D(20, 37));
    onscreenButtonManager->addOnscreenButton(storage->btnToggleWindowMode);

    //Buttons - Exit
    storage->btnExit = new OnscreenButton(TriggerOnUp, 1, Point2D(20, 580));
    storage->btnExit->setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->btnExit->addToUp(new Sprite("exit button up sprite", *storage->textures[2]));
    storage->btnExit->addToUp(new Text("exit button up text", *storage->font1, "Exit"), Point2D(20, 30));
    storage->btnExit->addToDown(new Sprite("exit button down sprite", *storage->textures[3]));
    storage->btnExit->addToDown(new Text("exit button down text", *storage->font1, "Exit"), Point2D(20, 37));
    onscreenButtonManager->addOnscreenButton(storage->btnExit);

    //Remove loading screen
    frame->removeFromFrame(storage->txtLoading);

    //Add to the frame
    frame->addToFrame(storage->txtCounter);
    frame->addToFrame(storage->sprCursor);
    frame->addToFrame(storage->btnTriggerOnUp);
    frame->addToFrame(storage->btnTriggerOnDown);
    frame->addToFrame(storage->btnTriggerOnHold);
    frame->addToFrame(storage->btnToggleWindowMode);
    frame->addToFrame(storage->btnExit);
    storage->state = MainMenu;
    
    loadMainMenuJoinable = true;
}

void ThreadManager::exitCleanUpStart()
{
    exitCleanUpJoinable = false;
    exitCleanUp = new std::thread(&ThreadManager::exitCleanUpThread, this);
    Debug::log("[INFO] exitCleanUpThread started");
    Debug::commitLogLine();
}

void ThreadManager::exitCleanUpJoin()
{
    exitCleanUp->join();
    delete exitCleanUp;
    Debug::log("[INFO] exitCleanUpThread joined");
    Debug::commitLogLine();
}

void ThreadManager::exitCleanUpThread()
{
    for (int i = 0; i < 999999999; i++)
    {
	
    }
    
    frame->removeFromFrame(storage->txtCounter);
    frame->removeFromFrame(storage->btnTriggerOnHold);
    frame->removeFromFrame(storage->btnTriggerOnDown);
    frame->removeFromFrame(storage->btnTriggerOnUp);
    frame->removeFromFrame(storage->btnToggleWindowMode);
    frame->removeFromFrame(storage->btnExit);
    delete storage->txtCounter;
    delete storage->btnTriggerOnDown;
    delete storage->btnTriggerOnUp;
    delete storage->btnTriggerOnHold;
    delete storage->btnToggleWindowMode;
    delete storage->btnExit;



    frame->removeFromFrame(storage->txtLoading);
    frame->removeFromFrame(storage->sprCursor);
    delete storage->txtLoading;
    delete storage->sprCursor;

    for (Texture* it : storage->textures)
    {
	delete it;
    }
    storage->textures.clear();

    delete storage->font1;
    
    Debug::log("[INFO] exitCleanUpThread ready to join");
    Debug::commitLogLine();
    
    exitCleanUpJoinable = true;
}