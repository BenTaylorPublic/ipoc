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

void ProcessController::IPOCLoad(InputController *inputControllerPtr, OnscreenButtonManager* inputOnscreenButtonManager, Frame* inputFrame, OutputController* outputControllerPtr)
{
    ic = inputControllerPtr;
    oc = outputControllerPtr;
    obm = inputOnscreenButtonManager;
    exitProgram = false;
    loopNumber = 0;
    frame = inputFrame;
    tm.IPOCLoad(&storage, frame, obm);
}

void ProcessController::load()
{
    tm.loadMainMenuStart();

    while (!tm.loadMainMenuJoinable());

    tm.loadMainMenuJoin();
}

void ProcessController::process()
{

    storage.sprCursor->setPosition(ic->getMousePoint());
    
    switch (storage.state)
    {
	case Exiting:
	    if (tm.exitCleanUpJoinable())
	    {
		tm.exitCleanUpJoin();
		exitProgram = true;
	    }
	    break;
	case MainMenu:
	    if (storage.btnTriggerOnDown->isTriggered() || storage.btnTriggerOnUp->isTriggered() || storage.btnTriggerOnHold->isTriggered())
	    {
		storage.counter++;
		storage.txtCounter->setText(std::to_string(storage.counter));
	    }
	    
	    if (storage.btnExit->isTriggered())
	    {
		storage.state = Exiting;
		tm.exitCleanUpStart();
	    }
	    break;

    }

    if (storage.state != Exiting)
    {
	if (ic->getKeyboardStatus(EscapeKey, ButtonDown))
	{
	    storage.state = Exiting;
	    tm.exitCleanUpStart();
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