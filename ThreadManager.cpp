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

bool ThreadManager::loadMainMenuJoinable()
{
    return loadMainMenu->joinable();
}

void ThreadManager::loadMainMenuThread()
{
    //Fonts
    storage->font1 = new Font("test font", "courier new.ttf");

    //Loading screen
    storage->tLoading = new Text("loading text", *storage->font1, 0, "Loading...", Point2D(100, 700));
    frame->addToFrame(storage->tLoading);
    frame->markAsDrawable();

    //Textures
    storage->textures.push_back(new Texture("test texture", "default texture.png"));
    storage->textures.push_back(new Texture("circle texture", "mouse circle.png"));
    storage->textures.push_back(new Texture("button up texture", "button up.png"));
    storage->textures.push_back(new Texture("button down texture", "button down.png"));
    storage->textures.push_back(new Texture("cursor texture", "cursor.png"));

    //Texts
    storage->tCounter = new Text("counter text", *storage->font1, 0, "0", Point2D(20, 20));
    storage->counter = 0;

    //Sprites
    storage->sCursor = new Sprite("cursor sprite", *storage->textures[4], 2);

    //Buttons
    //Buttons - TriggerOnUp
    storage->bTriggerOnUp = new OnscreenButton(TriggerOnUp, 1, Point2D(20, 100));
    storage->bTriggerOnUp->setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->bTriggerOnUp->addToUp(new Sprite("play button up sprite", *storage->textures[2]));
    storage->bTriggerOnUp->addToUp(new Text("play button up text", *storage->font1, "Trigger On Up"), Point2D(20, 30));
    storage->bTriggerOnUp->addToDown(new Sprite("play button down sprite", *storage->textures[3]));
    storage->bTriggerOnUp->addToDown(new Text("play button down text", *storage->font1, "Trigger On Up"), Point2D(20, 37));
    onscreenButtonManager->addOnscreenButton(storage->bTriggerOnUp);

    //Buttons - TriggerOnDown
    storage->bTriggerOnDown = new OnscreenButton(TriggerOnDown, 1, Point2D(20, 260));
    storage->bTriggerOnDown->setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->bTriggerOnDown->addToUp(new Sprite("options button up sprite", *storage->textures[2]));
    storage->bTriggerOnDown->addToUp(new Text("options button up text", *storage->font1, "Trigger On Down"), Point2D(20, 30));
    storage->bTriggerOnDown->addToDown(new Sprite("options button down sprite", *storage->textures[3]));
    storage->bTriggerOnDown->addToDown(new Text("options button down text", *storage->font1, "Trigger On Down"), Point2D(20, 37));
    onscreenButtonManager->addOnscreenButton(storage->bTriggerOnDown);

    //Buttons - TriggerOnHold
    storage->bTriggerOnHold = new OnscreenButton(TriggerOnHold, 1, Point2D(20, 420));
    storage->bTriggerOnHold->setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->bTriggerOnHold->addToUp(new Sprite("exit button up sprite", *storage->textures[2]));
    storage->bTriggerOnHold->addToUp(new Text("exit button up text", *storage->font1, "Trigger On Hold"), Point2D(20, 30));
    storage->bTriggerOnHold->addToDown(new Sprite("exit button down sprite", *storage->textures[3]));
    storage->bTriggerOnHold->addToDown(new Text("exit button down text", *storage->font1, "Trigger On Hold"), Point2D(20, 37));
    onscreenButtonManager->addOnscreenButton(storage->bTriggerOnHold);

    //Buttons - Exit
    storage->bExit = new OnscreenButton(TriggerOnUp, 1, Point2D(20, 580));
    storage->bExit->setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->bExit->addToUp(new Sprite("exit button up sprite", *storage->textures[2]));
    storage->bExit->addToUp(new Text("exit button up text", *storage->font1, "Exit"), Point2D(20, 30));
    storage->bExit->addToDown(new Sprite("exit button down sprite", *storage->textures[3]));
    storage->bExit->addToDown(new Text("exit button down text", *storage->font1, "Exit"), Point2D(20, 37));
    onscreenButtonManager->addOnscreenButton(storage->bExit);

    //Remove loading screen
    frame->removeFromFrame(storage->tLoading);

    //Add to the frame
    frame->addToFrame(storage->tCounter);
    frame->addToFrame(storage->sCursor);
    frame->addToFrame(storage->bTriggerOnUp);
    frame->addToFrame(storage->bTriggerOnDown);
    frame->addToFrame(storage->bTriggerOnHold);
    frame->addToFrame(storage->bExit);
    storage->state = MainMenu;
}

void ThreadManager::exitCleanUpStart()
{
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

bool ThreadManager::exitCleanUpJoinable()
{
    return exitCleanUp->joinable();
}

void ThreadManager::exitCleanUpThread()
{
    frame->removeFromFrame(storage->tCounter);
    frame->removeFromFrame(storage->bTriggerOnHold);
    frame->removeFromFrame(storage->bTriggerOnDown);
    frame->removeFromFrame(storage->bTriggerOnUp);
    frame->removeFromFrame(storage->bExit);
    delete storage->tCounter;
    delete storage->bTriggerOnDown;
    delete storage->bTriggerOnUp;
    delete storage->bTriggerOnHold;
    delete storage->bExit;



    frame->removeFromFrame(storage->tLoading);
    frame->removeFromFrame(storage->sCursor);
    delete storage->tLoading;
    delete storage->sCursor;

    for (Texture* it : storage->textures)
    {
	delete it;
    }
    storage->textures.clear();

    delete storage->font1;
}