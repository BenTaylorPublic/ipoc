#include "ThreadManager.h"
#include "Debug.h"
#include "Settings.h"
#include "Color.h"

ThreadManager::ThreadManager()
{
}

ThreadManager::~ThreadManager()
{
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

void ThreadManager::loadGlobalStart()
{
    loadGlobalJoinable = false;
    loadGlobalThread = new std::thread(&ThreadManager::loadGlobal, this);
    Debug::logLine("[INFO] loadMainMenuThread started");
}

void ThreadManager::loadGlobalJoin()
{
    loadGlobalThread->join();
    delete loadGlobalThread;
    loadGlobalJoinable = false;
    Debug::logLine("[INFO] loadMainMenuThread joined");
}

void ThreadManager::loadGlobal()
{
    storage->global = new StorageGlobal;

    //Fonts
    storage->global->font1.loadFont("test font", "courier new.ttf");

    //Loading screen
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

    storage->global->txtProcessThreadUsage.setFont(storage->global->font1);
    storage->global->txtProcessThreadUsage.setPosition(Point2D(1530, 5));
    storage->global->txtProcessThreadUsage.setZ(1);

    //Sprites
    storage->global->sprCursor.setTexture(*storage->global->textures[4]);
    storage->global->sprCursor.setZ(2);

    //Buttons
    //Buttons - ButtonTesting
    storage->global->btnButtonTesting.setButtonTriggerType(TriggerOnUp);
    storage->global->btnButtonTesting.setZ(1);
    storage->global->btnButtonTesting.setPosition(Point2D(20, 10));
    storage->global->btnButtonTesting.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->global->btnButtonTesting.addToUp(new Sprite(*storage->global->textures[2]));
    storage->global->btnButtonTesting.addToUp(new Text(storage->global->font1, "Buttons"), Point2D(20, 30));
    storage->global->btnButtonTesting.addToDown(new Sprite(*storage->global->textures[3]));
    storage->global->btnButtonTesting.addToDown(new Text(storage->global->font1, "Buttons"), Point2D(20, 37));
    inputController->addOnscreenButton(&storage->global->btnButtonTesting);

    //Buttons - ShapeFun
    storage->global->btnShapeFun.setButtonTriggerType(TriggerOnUp);
    storage->global->btnShapeFun.setZ(1);
    storage->global->btnShapeFun.setPosition(Point2D(340, 10));
    storage->global->btnShapeFun.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->global->btnShapeFun.addToUp(new Sprite(*storage->global->textures[2]));
    storage->global->btnShapeFun.addToUp(new Text(storage->global->font1, "Shapes"), Point2D(20, 30));
    storage->global->btnShapeFun.addToDown(new Sprite(*storage->global->textures[3]));
    storage->global->btnShapeFun.addToDown(new Text(storage->global->font1, "Shapes"), Point2D(20, 37));
    inputController->addOnscreenButton(&storage->global->btnShapeFun);

    //Remove loading screen
    frame->removeFromFrame(&storage->global->txtLoading);

    //Adding to frame
    frame->addToFrame(&storage->global->sprCursor);
    frame->addToFrame(&storage->global->btnButtonTesting);
    frame->addToFrame(&storage->global->btnShapeFun);
    if (Settings::debugMode)
	frame->addToFrame(&storage->global->txtProcessThreadUsage);

    loadGlobalJoinable = true;
}

void ThreadManager::unloadGlobalStart()
{
    unloadGlobalJoinable = false;
    unloadGlobalThread = new std::thread(&ThreadManager::unloadGlobal, this);
    Debug::logLine("[INFO] unloadGlobalThread started");
}

void ThreadManager::unloadGlobalJoin()
{
    unloadGlobalThread->join();
    delete unloadGlobalThread;
    unloadGlobalJoinable = false;
    Debug::logLine("[INFO] unloadGlobalThread joined");
}

void ThreadManager::unloadGlobal()
{
    frame->removeFromFrame(&storage->global->txtProcessThreadUsage);
    frame->removeFromFrame(&storage->global->txtLoading);
    frame->removeFromFrame(&storage->global->sprCursor);
    frame->removeFromFrame(&storage->global->btnButtonTesting);
    frame->removeFromFrame(&storage->global->btnShapeFun);

    inputController->removeOnscreenButton(&storage->global->btnButtonTesting);
    inputController->removeOnscreenButton(&storage->global->btnShapeFun);

    for (Texture* it : storage->global->textures)
    {
	delete it;
    }
    storage->global->textures.clear();

    delete storage->global;

    unloadGlobalJoinable = true;
}

void ThreadManager::loadButtonTestingStart()
{
    loadButtonTestingJoinable = false;
    loadButtonTestingThread = new std::thread(&ThreadManager::loadButtonTesting, this);
    Debug::logLine("[INFO] loadButtonTestingThread started");
}

void ThreadManager::loadButtonTestingJoin()
{
    loadButtonTestingThread->join();
    delete loadButtonTestingThread;
    loadButtonTestingJoinable = false;
    Debug::logLine("[INFO] loadButtonTestingThread joined");
}

void ThreadManager::loadButtonTesting()
{
    storage->buttonTesting = new StorageButtonTesting;

    //Variables
    storage->buttonTesting->counter = 0;
    storage->buttonTesting->windowToggleMode = true;

    //Texts
    storage->buttonTesting->txtCounter.setFont(storage->global->font1);
    storage->buttonTesting->txtCounter.setZ(1);
    storage->buttonTesting->txtCounter.setText("0");
    storage->buttonTesting->txtCounter.setPosition(Point2D(400, 345));
    //Buttons
    //Buttons - TriggerOnUp
    storage->buttonTesting->btnTriggerOnUp.setButtonTriggerType(TriggerOnUp);
    storage->buttonTesting->btnTriggerOnUp.setZ(1);
    storage->buttonTesting->btnTriggerOnUp.setPosition(Point2D(20, 140));
    storage->buttonTesting->btnTriggerOnUp.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->buttonTesting->btnTriggerOnUp.addToUp(new Sprite(*storage->global->textures[2]));
    storage->buttonTesting->btnTriggerOnUp.addToUp(new Text(storage->global->font1, "Trigger On Up"), Point2D(20, 30));
    storage->buttonTesting->btnTriggerOnUp.addToDown(new Sprite(*storage->global->textures[3]));
    storage->buttonTesting->btnTriggerOnUp.addToDown(new Text(storage->global->font1, "Trigger On Up"), Point2D(20, 37));
    inputController->addOnscreenButton(&storage->buttonTesting->btnTriggerOnUp);

    //Buttons - TriggerOnDown
    storage->buttonTesting->btnTriggerOnDown.setButtonTriggerType(TriggerOnDown);
    storage->buttonTesting->btnTriggerOnDown.setZ(1);
    storage->buttonTesting->btnTriggerOnDown.setPosition(Point2D(20, 300));
    storage->buttonTesting->btnTriggerOnDown.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->buttonTesting->btnTriggerOnDown.addToUp(new Sprite(*storage->global->textures[2]));
    storage->buttonTesting->btnTriggerOnDown.addToUp(new Text(storage->global->font1, "Trigger On Down"), Point2D(20, 30));
    storage->buttonTesting->btnTriggerOnDown.addToDown(new Sprite(*storage->global->textures[3]));
    storage->buttonTesting->btnTriggerOnDown.addToDown(new Text(storage->global->font1, "Trigger On Down"), Point2D(20, 37));
    inputController->addOnscreenButton(&storage->buttonTesting->btnTriggerOnDown);

    //Buttons - TriggerOnHold
    storage->buttonTesting->btnTriggerOnHold.setButtonTriggerType(TriggerOnHold);
    storage->buttonTesting->btnTriggerOnHold.setZ(1);
    storage->buttonTesting->btnTriggerOnHold.setPosition(Point2D(20, 460));
    storage->buttonTesting->btnTriggerOnHold.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->buttonTesting->btnTriggerOnHold.addToUp(new Sprite(*storage->global->textures[2]));
    storage->buttonTesting->btnTriggerOnHold.addToUp(new Text(storage->global->font1, "Trigger On Hold"), Point2D(20, 30));
    storage->buttonTesting->btnTriggerOnHold.addToDown(new Sprite(*storage->global->textures[3]));
    storage->buttonTesting->btnTriggerOnHold.addToDown(new Text(storage->global->font1, "Trigger On Hold"), Point2D(20, 37));
    inputController->addOnscreenButton(&storage->buttonTesting->btnTriggerOnHold);

    //Buttons - ToggleWindowMode
    storage->buttonTesting->btnToggleWindowMode.setButtonTriggerType(TriggerOnUp);
    storage->buttonTesting->btnToggleWindowMode.setZ(1);
    storage->buttonTesting->btnToggleWindowMode.setPosition(Point2D(340, 140));
    storage->buttonTesting->btnToggleWindowMode.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->buttonTesting->btnToggleWindowMode.addToUp(new Sprite(*storage->global->textures[2]));
    storage->buttonTesting->btnToggleWindowMode.addToUp(new Text(storage->global->font1, "Toggle Window"), Point2D(20, 30));
    storage->buttonTesting->btnToggleWindowMode.addToDown(new Sprite(*storage->global->textures[3]));
    storage->buttonTesting->btnToggleWindowMode.addToDown(new Text(storage->global->font1, "Toggle Window"), Point2D(20, 37));
    inputController->addOnscreenButton(&storage->buttonTesting->btnToggleWindowMode);

    //Adding to frame
    frame->addToFrame(&storage->buttonTesting->btnTriggerOnUp);
    frame->addToFrame(&storage->buttonTesting->btnTriggerOnDown);
    frame->addToFrame(&storage->buttonTesting->btnTriggerOnHold);
    frame->addToFrame(&storage->buttonTesting->btnToggleWindowMode);
    frame->addToFrame(&storage->buttonTesting->txtCounter);

    loadButtonTestingJoinable = true;
}

void ThreadManager::unloadButtonTestingStart()
{
    unloadButtonTestingJoinable = false;
    unloadButtonTestingThread = new std::thread(&ThreadManager::unloadButtonTesting, this);
    Debug::logLine("[INFO] unloadButtonTestingThread started");
}

void ThreadManager::unloadButtonTestingJoin()
{
    unloadButtonTestingThread->join();
    delete unloadButtonTestingThread;
    unloadButtonTestingJoinable = false;
    Debug::logLine("[INFO] unloadButtonTestingThread joined");
}

void ThreadManager::unloadButtonTesting()
{
    frame->removeFromFrame(&storage->buttonTesting->txtCounter);
    frame->removeFromFrame(&storage->buttonTesting->btnTriggerOnHold);
    frame->removeFromFrame(&storage->buttonTesting->btnTriggerOnDown);
    frame->removeFromFrame(&storage->buttonTesting->btnTriggerOnUp);
    frame->removeFromFrame(&storage->buttonTesting->btnToggleWindowMode);

    inputController->removeOnscreenButton(&storage->buttonTesting->btnTriggerOnDown);
    inputController->removeOnscreenButton(&storage->buttonTesting->btnTriggerOnHold);
    inputController->removeOnscreenButton(&storage->buttonTesting->btnTriggerOnUp);
    inputController->removeOnscreenButton(&storage->buttonTesting->btnToggleWindowMode);

    delete storage->buttonTesting;

    unloadButtonTestingJoinable = true;
}

void ThreadManager::loadShapeFunStart()
{
    loadShapeFunJoinable = false;
    loadShapeFunThread = new std::thread(&ThreadManager::loadShapeFun, this);
    Debug::logLine("[INFO] loadShapeFunThread started");
}

void ThreadManager::loadShapeFunJoin()
{
    loadShapeFunThread->join();
    delete loadShapeFunThread;
    loadShapeFunJoinable = false;
    Debug::logLine("[INFO] loadShapeFunThread joined");
}

void ThreadManager::loadShapeFun()
{
    storage->shapeFun = new StorageShapeFun;
    
    storage->shapeFun->rectangle = nullptr;
    storage->shapeFun->settingRectangleSize = false;
    
    storage->shapeFun->circle = nullptr;
    storage->shapeFun->settingCircleSize = false;
    
    storage->shapeFun->circleMode = true; //false for rectangle mode
    
    storage->shapeFun->btnClear.setButtonTriggerType(TriggerOnUp);
    storage->shapeFun->btnClear.setZ(1);
    storage->shapeFun->btnClear.setPosition(Point2D(20, 140));
    storage->shapeFun->btnClear.setHitBox(Point2D(0, 0), Point2D(300, 100));
    storage->shapeFun->btnClear.addToUp(new Sprite(*storage->global->textures[2]));
    storage->shapeFun->btnClear.addToUp(new Text(storage->global->font1, "Clear"), Point2D(20, 30));
    storage->shapeFun->btnClear.addToDown(new Sprite(*storage->global->textures[3]));
    storage->shapeFun->btnClear.addToDown(new Text(storage->global->font1, "Clear"), Point2D(20, 37));
    
    frame->addToFrame(&storage->shapeFun->btnClear);
    inputController->addOnscreenButton(&storage->shapeFun->btnClear);

    loadShapeFunJoinable = true;
}

void ThreadManager::unloadShapeFunStart()
{
    unloadShapeFunJoinable = false;
    unloadShapeFunThread = new std::thread(&ThreadManager::unloadShapeFun, this);
    Debug::logLine("[INFO] unloadShapeFunThread started");
}

void ThreadManager::unloadShapeFunJoin()
{
    unloadShapeFunThread->join();
    delete unloadShapeFunThread;
    unloadShapeFunJoinable = false;
    Debug::logLine("[INFO] unloadShapeFunThread joined");
}

void ThreadManager::unloadShapeFun()
{

    inputController->removeOnscreenButton(&storage->shapeFun->btnClear);
    frame->removeFromFrame(&storage->shapeFun->btnClear);
    
    if (storage->shapeFun->rectangle != nullptr)
    {
	frame->removeFromFrame(storage->shapeFun->rectangle);
	delete storage->shapeFun->rectangle;
    }
    
    if (storage->shapeFun->circle != nullptr)
    {
	frame->removeFromFrame(storage->shapeFun->circle);
	delete storage->shapeFun->circle;
    }

    for (Rectangle* it : storage->shapeFun->rectangles)
    {
	frame->removeFromFrame(it);
	delete it;
    }
    storage->shapeFun->rectangles.clear();
    
    for (Circle* it : storage->shapeFun->circles)
    {
	frame->removeFromFrame(it);
	delete it;
    }
    storage->shapeFun->circles.clear();

    delete storage->shapeFun;

    unloadShapeFunJoinable = true;
}