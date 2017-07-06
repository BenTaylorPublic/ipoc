#include "ProcessController.h"
#include "Debug.h"
#include "Conversions.h"
#include "Settings.h"
#include "InputEnums.h"
#include "Color.h"

ProcessController::ProcessController()
{
    Debug::notifyOfConstruction(2);
}

ProcessController::~ProcessController()
{
    Debug::notifyOfDestruction(2);
}

void ProcessController::IPOCLoad(InputController *inputControllerPtr, OnscreenButtonManager* inputOnscreenButtonManager, Frame* inputFrame)
{
    inputController = inputControllerPtr;
    onscreenButtonManager = inputOnscreenButtonManager;
    exitProgram = false;
    loopNumber = 0;
    frame = inputFrame;
    threadManager.IPOCLoad(&storage, frame, onscreenButtonManager);
}

void ProcessController::load()
{
    threadManager.loadMainMenuStart();

    while (!threadManager.loadMainMenuJoinable());

    threadManager.loadMainMenuJoin();
}

void ProcessController::process()
{
    switch (storage.state)
    {
	case Exiting:
	    if (threadManager.exitCleanUpJoinable())
	    {
		threadManager.exitCleanUpJoin();
		exitProgram = true;
	    }
	    break;
	case MainMenu:
	    if (storage.buttonExitGame->isTriggered())
	    {
		storage.state = Exiting;
		threadManager.exitCleanUpStart(MainMenu);
	    }
	    break;

    }

    if (storage.state != Exiting)
    {
	storage.spriteCursor->setPosition(inputController->getMousePoint());

	if (inputController->getKeyboardStatus(EscapeKey, ButtonDown))
	{
	    storage.state = Exiting;
	    threadManager.exitCleanUpStart(MainMenu);
	}
    }
}

bool ProcessController::checkForExitProgram()
{
    return exitProgram;
}

void ProcessController::incrementLoopNumber()
{
    loopNumber++;
}

std::string ProcessController::getStatusString()
{
    std::string result = "exitProgram: ";
    if (exitProgram)
	result += "true\n";
    else
	result += "false\n";

    result += "loopNumber: " + std::to_string(loopNumber) + "\n";

    return result;
}