#include "ThreadManager.h"
#include "Debug.h"
#include "IPOCSettings.h"


ThreadManager::ThreadManager()
{
	Debug::notifyOfConstruction(19);
}

ThreadManager::~ThreadManager()
{
	Debug::notifyOfDestruction(19);
}

void ThreadManager::IPOCLoad(Storage* inputStorage, IPOCFrame* inputFrame, OnscreenButtonManager* inputOnscreenButtonManager)
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
	loadMainMenu = new thread(&ThreadManager::loadMainMenuThread, this);
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
	storage->font1 = new IPOCFont("test font", "courier new.ttf");
	
	//Loading screen
	storage->textLoading = new IPOCText("test text", *storage->font1, 0, "Loading..." , Point2D(100,700));
	frame->addToFrame(storage->textLoading);
	frame->markAsDrawable();
	
	//Textures
	storage->textures.push_back(new IPOCTexture("test texture", "default texture.png"));
	storage->textures.push_back(new IPOCTexture("circle texture", "mouse circle.png"));
	storage->textures.push_back(new IPOCTexture("button up texture", "button up.png"));
	storage->textures.push_back(new IPOCTexture("button down texture", "button down.png"));
	storage->textures.push_back(new IPOCTexture("cursor texture", "cursor.png"));
	
	//Texts
	storage->textHeading = new IPOCText("test text", *storage->font1, 0, "BEVS", Point2D(20,20));
	
	//Sprites
	storage->spriteCursor = new IPOCSprite("cursor sprite", *storage->textures[4], 2);
	
	//Buttons
	storage->buttonPlay = new OnscreenButton(TriggerOnUp, 1, Point2D(20, 100));
	storage->buttonPlay->setHitBox(Point2D(0,0), Point2D(300,100));
	storage->buttonPlay->addToUp(new IPOCSprite("play button up sprite", *storage->textures[2]));
	storage->buttonPlay->addToUp(new IPOCText("play button up text", *storage->font1, "Play"), Point2D(20, 30));
	storage->buttonPlay->addToDown(new IPOCSprite("play button down sprite", *storage->textures[3]));
	storage->buttonPlay->addToDown(new IPOCText("play button down text", *storage->font1, "Play"), Point2D(20, 37));
	onscreenButtonManager->addOnscreenButton(storage->buttonPlay);
	
	storage->buttonOptions = new OnscreenButton(TriggerOnUp, 1, Point2D(20, 260));
	storage->buttonOptions->setHitBox(Point2D(0,0), Point2D(300,100));
	storage->buttonOptions->addToUp(new IPOCSprite("options button up sprite", *storage->textures[2]));
	storage->buttonOptions->addToUp(new IPOCText("options button up text", *storage->font1, "Options"), Point2D(20, 30));
	storage->buttonOptions->addToDown(new IPOCSprite("options button down sprite", *storage->textures[3]));
	storage->buttonOptions->addToDown(new IPOCText("options button down text", *storage->font1, "Options"), Point2D(20, 37));
	onscreenButtonManager->addOnscreenButton(storage->buttonOptions);
	
	storage->buttonExitGame = new OnscreenButton(TriggerOnUp, 1, Point2D(20, 420));
	storage->buttonExitGame->setHitBox(Point2D(0,0), Point2D(300,100));
	storage->buttonExitGame->addToUp(new IPOCSprite("exit button up sprite", *storage->textures[2]));
	storage->buttonExitGame->addToUp(new IPOCText("exit button up text", *storage->font1, "Exit"), Point2D(20, 30));
	storage->buttonExitGame->addToDown(new IPOCSprite("exit button down sprite", *storage->textures[3]));
	storage->buttonExitGame->addToDown(new IPOCText("exit button down text", *storage->font1, "Exit"), Point2D(20, 37));
	onscreenButtonManager->addOnscreenButton(storage->buttonExitGame);
	
	//Remove loading screen
	frame->removeFromFrame(storage->textLoading);
	
	//Add to the frame
	frame->addToFrame(storage->textHeading);
	frame->addToFrame(storage->spriteCursor);
	frame->addToFrame(storage->buttonExitGame);
	frame->addToFrame(storage->buttonOptions);
	frame->addToFrame(storage->buttonPlay);
	storage->state = MainMenu;
}

void ThreadManager::exitCleanUpStart(const ProgramState& inputExitingFrom)
{
	exitCleanUp = new thread(&ThreadManager::exitCleanUpThread, this, inputExitingFrom);
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

void ThreadManager::exitCleanUpThread(const ProgramState& exitingFrom)
{	
	switch (exitingFrom)
	{
		case MainMenu:		
			frame->removeFromFrame(storage->textHeading);
			frame->removeFromFrame(storage->buttonPlay);
			frame->removeFromFrame(storage->buttonOptions);
			frame->removeFromFrame(storage->buttonExitGame);
			delete storage->textHeading;
			delete storage->buttonPlay;
			delete storage->buttonOptions;
			delete storage->buttonExitGame;
			break;
		default:
			Debug::log("[WARNING] Unrecognisable exit state.");
			Debug::commitLogLine();
			Debug::log("[WARNING] There will probably be memory leaks as a result.");
			Debug::commitLogLine();
			Debug::log("[WARNING] Check ThreadManager.exitCleanUpThread() for more info");
			Debug::commitLogLine();
			break;
			
	}
	
	frame->removeFromFrame(storage->textLoading);
	frame->removeFromFrame(storage->spriteCursor);
	delete storage->textLoading;
	delete storage->spriteCursor;	
	
	for (IPOCTexture* it : storage->textures)
	{
		delete it;
	}
	storage->textures.clear();		
	
	delete storage->font1;	
}