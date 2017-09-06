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

void ProcessController::IPOCLoad(InputController *inputControllerPtr, Frame* inputFrame, OutputController* outputControllerPtr)
{
    ic = inputControllerPtr;
    oc = outputControllerPtr;
    exitProgram = false;
    loopNumber = 0;
    frame = inputFrame;
    tm.IPOCLoad(&storage, frame, ic);
}

void ProcessController::load()
{
    storage.state = FirstLoad;

    tm.loadGlobalStart();

    while (!tm.loadGlobalJoinable);
    tm.loadGlobalJoin();

    tm.loadButtonTestingStart();

    while (!tm.loadButtonTestingJoinable);
    tm.loadButtonTestingJoin();
    storage.state = ButtonTesting;
}

void ProcessController::process()
{
    switch (storage.state)
    {
	case Exiting:
	    if (tm.unloadButtonTestingJoinable)
	    {
		tm.unloadButtonTestingJoin();
		tm.unloadGlobalStart();
	    } else if (tm.unloadGlobalJoinable)
	    {
		tm.unloadGlobalJoin();
		exitProgram = true;
	    }
	    break;
	case ButtonTesting:
	    storage.global->sprCursor.setPosition(ic->getMousePoint());
	    if (Settings::debugMode)
	    {
		storage.global->counterForThreadUsage++;
		if (storage.global->counterForThreadUsage == 16)
		{
		    storage.global->counterForThreadUsage = 0;
		    storage.global->txtProcessThreadUsage.setText(std::to_string((int) Debug::processThreadUsagePercent) + "%");
		}
	    }

	    if (storage.buttonTesting->btnTriggerOnDown.isTriggered() || storage.buttonTesting->btnTriggerOnUp.isTriggered() || storage.buttonTesting->btnTriggerOnHold.isTriggered())
	    {
		storage.buttonTesting->counter++;
		storage.buttonTesting->txtCounter.setText(std::to_string(storage.buttonTesting->counter));
	    }

	    if (storage.buttonTesting->btnToggleWindowMode.isTriggered())
	    {
		if (!storage.buttonTesting->windowToggleMode)
		{
		    Settings::screenWidth = 1600;
		    Settings::screenHeight = 900;
		    Settings::screenTitle = "IPOC";
		    Settings::windowType = "borderless window";
		    Settings::hideCursor = true;

		    storage.buttonTesting->windowToggleMode = true;
		} else
		{
		    Settings::screenWidth = 800;
		    Settings::screenHeight = 800;
		    Settings::screenTitle = "IPOC toggle 2";
		    Settings::windowType = "windowed";
		    Settings::hideCursor = false;

		    storage.buttonTesting->windowToggleMode = false;
		}
		oc->reloadGraphicsWindow();
	    }

	    if (storage.buttonTesting->btnExit.isTriggered() || ic->getPhysicalButtonStatus(KeyEscape, ButtonDown))
	    {
		storage.state = Exiting;
		tm.unloadButtonTestingStart();
	    }
	    break;

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