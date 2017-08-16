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

    while (!tm.loadMainMenuJoinable);

    tm.loadMainMenuJoin();
}

void ProcessController::process()
{

    switch (storage.state)
    {
	case Exiting:
	    if (tm.exitCleanUpJoinable)
	    {
		tm.exitCleanUpJoin();
		exitProgram = true;
	    }
	    break;
	case MainMenu:
	    storage.sprCursor->setPosition(ic->getMousePoint());
	    if (Settings::debugMode)
		storage.txtProcessThreadUsage->setText(std::to_string(Debug::processThreadUsagePercent) + "%");

	    if (storage.btnTriggerOnDown->isTriggered() || storage.btnTriggerOnUp->isTriggered() || storage.btnTriggerOnHold->isTriggered())
	    {
		storage.counter++;
		storage.txtCounter->setText(std::to_string(storage.counter));
	    }

	    if (storage.btnToggleWindowMode->isTriggered())
	    {
		if (!storage.windowToggleMode)
		{
		    Settings::screenWidth = 1600;
		    Settings::screenHeight = 900;
		    Settings::screenTitle = "IPOC";
		    Settings::windowType = "borderless window";
		    Settings::hideCursor = true;

		    storage.windowToggleMode = true;
		} else
		{
		    Settings::screenWidth = 800;
		    Settings::screenHeight = 800;
		    Settings::screenTitle = "IPOC toggle 2";
		    Settings::windowType = "windowed";
		    Settings::hideCursor = false;

		    storage.windowToggleMode = false;
		}
		oc->reloadGraphicsWindow();
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
	if (ic->getPhysicalButtonStatus(KeyEscape, ButtonDown))
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