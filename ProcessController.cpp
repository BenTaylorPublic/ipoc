#include "ProcessController.h"
#include "Debug.h"
#include "Conversions.h"
#include "Settings.h"
#include "InputEnums.h"
#include "Color.h"

ProcessController::ProcessController()
{
}

ProcessController::~ProcessController()
{
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
    storage.state2 = Safe;
}

void ProcessController::process()
{

    if (storage.state != Exiting)
    {
	storage.global->sprCursor.setPosition(ic->getMousePoint());
	if (ic->getPhysicalButtonStatus(KeyEscape, ButtonDown))
	{
	    if (storage.state == ButtonTesting)
	    {
		tm.unloadButtonTestingStart();
	    } else if (storage.state == ShapeFun)
	    {
		tm.unloadShapeFunStart();
	    }
	    storage.state = Exiting;
	    storage.state2 = Loading;
	}


	if (Settings::debugMode)
	{
	    storage.global->counterForThreadUsage++;
	    if (storage.global->counterForThreadUsage == 16)
	    {
		storage.global->counterForThreadUsage = 0;
		storage.global->txtProcessThreadUsage.setText(std::to_string((int) Debug::processThreadUsagePercent) + "%");
	    }
	}
    } else if (storage.state == Exiting)
    {
	if (storage.state2 == Loading)
	{
	    if (tm.unloadButtonTestingJoinable)
	    {
		tm.unloadButtonTestingJoin();
		storage.state2 = Safe;
	    } else if (tm.unloadShapeFunJoinable)
	    {
		tm.unloadShapeFunJoin();
		storage.state2 = Safe;
	    } else if (tm.unloadGlobalJoinable)
	    {
		tm.unloadGlobalJoin();
		exitProgram = true;
	    }
	} else
	{
	    tm.unloadGlobalStart();
	    storage.state2 = Loading;
	}
    }


    if (storage.state == ButtonTesting)
    {
	if (storage.state2 == Safe)
	{
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

	    if (storage.global->btnShapeFun.isTriggered())
	    {
		tm.unloadButtonTestingStart();
		tm.loadShapeFunStart();
		storage.state = ShapeFun;
		storage.state2 = Loading;
	    }
	} else //NOT SAFE, LOADING
	{

	    if (tm.unloadShapeFunJoinable && tm.loadButtonTestingJoinable)
	    {
		tm.unloadShapeFunJoin();
		tm.loadButtonTestingJoin();
		storage.state2 = Safe;
	    }
	}
    } else if (storage.state == ShapeFun)
    {
	if (storage.state2 == Safe)
	{

	    if (ic->getPhysicalButtonStatus(MouseLeft, ButtonDown))
	    {
		if (!storage.shapeFun->settingSquareSizeState)
		{
		    storage.shapeFun->rectangle = new Rectangle();
		    storage.shapeFun->settingSquareSizeState = true;
		    storage.shapeFun->rectangle->setCornerOne(ic->getMousePoint());
		    storage.shapeFun->rectangle->setSize(0, 0);
		    storage.shapeFun->rectangle->setColor(Color::Random());
		    frame->addToFrame(storage.shapeFun->rectangle);
		} else
		{
		    storage.shapeFun->rectangles.push_back(storage.shapeFun->rectangle);
		    storage.shapeFun->settingSquareSizeState = false;
		    storage.shapeFun->rectangle->setCornerTwo(ic->getMousePoint());
		    storage.shapeFun->rectangle = nullptr;
		}

	    }

	    if (storage.shapeFun->settingSquareSizeState)
	    {
		//set corner two not permenantly
		storage.shapeFun->rectangle->setCornerTwo(ic->getMousePoint());
	    }

	    if (storage.global->btnButtonTesting.isTriggered())
	    {
		tm.unloadShapeFunStart();
		tm.loadButtonTestingStart();
		storage.state = ButtonTesting;
		storage.state2 = Loading;
	    }
	} else //NOT SAFE, LOADING
	{
	    if (tm.unloadButtonTestingJoinable && tm.loadShapeFunJoinable)
	    {
		tm.unloadButtonTestingJoin();
		tm.loadShapeFunJoin();
		storage.state2 = Safe;
	    }
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