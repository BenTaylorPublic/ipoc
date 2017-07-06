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

    storage.sCursor->setPosition(inputController->getMousePoint());
    
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
	    if (storage.bTriggerOnDown->isTriggered() || storage.bTriggerOnUp->isTriggered() || storage.bTriggerOnHold->isTriggered())
	    {
		storage.counter++;
		storage.tCounter->setText(std::to_string(storage.counter));
	    }
	    
	    if (storage.bExit->isTriggered())
	    {
		storage.state = Exiting;
		threadManager.exitCleanUpStart();
	    }
	    break;

    }

    if (storage.state != Exiting)
    {
	if (inputController->getKeyboardStatus(EscapeKey, ButtonDown))
	{
	    storage.state = Exiting;
	    threadManager.exitCleanUpStart();
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