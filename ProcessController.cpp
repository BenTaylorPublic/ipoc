#include "ProcessController.h"
#include "Debug.h"
#include "Conversions.h"
#include "Settings.h"
#include "InputEnums.h"
#include "Color.h"
#include <cmath>

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
	global();

    } else if (storage.state == Exiting)
    {
	exiting();
    }


    if (storage.state == ButtonTesting)
    {
	if (storage.state2 == Safe)
	{
	    buttonTestingSafe();
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
	    shapeFunSafe();
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

void ProcessController::global()
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
}

void ProcessController::exiting()
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

void ProcessController::buttonTestingSafe()
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
}

void ProcessController::shapeFunSafe()
{
    if (storage.global->btnButtonTesting.isTriggered())
    {
	tm.unloadShapeFunStart();
	tm.loadButtonTestingStart();
	storage.state = ButtonTesting;
	storage.state2 = Loading;
    } else if (storage.shapeFun->btnClear.isTriggered())
    {
	//Rectangles
	if (storage.shapeFun->rectangle != nullptr)
	{
	    frame->removeFromFrame(storage.shapeFun->rectangle);
	    delete storage.shapeFun->rectangle;
	    storage.shapeFun->rectangle = nullptr;
	    storage.shapeFun->settingRectangleSize = false;
	}

	for (Rectangle* it : storage.shapeFun->rectangles)
	{
	    frame->removeFromFrame(it);
	    delete it;
	}
	storage.shapeFun->rectangles.clear();

	//Circles
	if (storage.shapeFun->circle != nullptr)
	{
	    frame->removeFromFrame(storage.shapeFun->circle);
	    delete storage.shapeFun->circle;
	    storage.shapeFun->circle = nullptr;
	    storage.shapeFun->settingCircleSize = false;
	}

	for (Circle* it : storage.shapeFun->circles)
	{
	    frame->removeFromFrame(it);
	    delete it;
	}
	storage.shapeFun->circles.clear();

	//Lines
	if (storage.shapeFun->line != nullptr)
	{
	    frame->removeFromFrame(storage.shapeFun->line);
	    delete storage.shapeFun->line;
	    storage.shapeFun->line = nullptr;
	    storage.shapeFun->settingLineSize = false;
	}

	for (Line* it : storage.shapeFun->lines)
	{
	    frame->removeFromFrame(it);
	    delete it;
	}
	storage.shapeFun->lines.clear();
    } else
    {
	if (ic->getPhysicalButtonStatus(MouseLeft, ButtonDown))
	{
	    if (storage.shapeFun->mode == RectangleMode)
	    {
		//RECTANGLES
		if (!storage.shapeFun->settingRectangleSize)
		{
		    storage.shapeFun->rectangle = new Rectangle();
		    storage.shapeFun->settingRectangleSize = true;
		    storage.shapeFun->rectangle->setCornerOne(ic->getMousePoint());
		    storage.shapeFun->rectangle->setSize(0, 0);
		    storage.shapeFun->rectangle->setZ(1);
		    storage.shapeFun->rectangle->setColor(Color::Random());
		    frame->addToFrame(storage.shapeFun->rectangle);
		} else
		{
		    storage.shapeFun->rectangles.push_back(storage.shapeFun->rectangle);
		    storage.shapeFun->settingRectangleSize = false;
		    storage.shapeFun->rectangle->setCornerTwo(ic->getMousePoint());
		    storage.shapeFun->rectangle = nullptr;
		}
	    } else if (storage.shapeFun->mode == CircleMode)
	    {
		//CIRCLES
		if (!storage.shapeFun->settingCircleSize)
		{
		    storage.shapeFun->circle = new Circle();
		    storage.shapeFun->settingCircleSize = true;
		    storage.shapeFun->circle->setPointCount(50);
		    storage.shapeFun->circle->setRadius(0);
		    storage.shapeFun->circleCenter = ic->getMousePoint();
		    storage.shapeFun->circle->setCenter(storage.shapeFun->circleCenter);
		    storage.shapeFun->circle->setZ(1);
		    storage.shapeFun->circle->setColor(Color::Random());
		    frame->addToFrame(storage.shapeFun->circle);

		} else
		{
		    int radius = storage.shapeFun->circleCenter.distanceTo(ic->getMousePoint());

		    storage.shapeFun->circle->setRadius(radius);
		    storage.shapeFun->circle->setCenter(storage.shapeFun->circleCenter);
		    storage.shapeFun->circles.push_back(storage.shapeFun->circle);
		    storage.shapeFun->settingCircleSize = false;
		    storage.shapeFun->circle = nullptr;
		}
	    } else if (storage.shapeFun->mode == LineMode)
	    {
		if (!storage.shapeFun->settingLineSize)
		{
		    storage.shapeFun->line = new Line();
		    storage.shapeFun->settingLineSize = true;
		    storage.shapeFun->line->setPosition(ic->getMousePoint());
		    storage.shapeFun->line->setZ(1);
		    storage.shapeFun->line->setColor(Color::Random());
		    frame->addToFrame(storage.shapeFun->line);
		} else
		{
		    storage.shapeFun->line->setPosition2(ic->getMousePoint());
		    storage.shapeFun->lines.push_back(storage.shapeFun->line);
		    storage.shapeFun->settingLineSize = false;
		    storage.shapeFun->line = nullptr;
		}
	    }

	}

	if (storage.shapeFun->settingRectangleSize)
	{
	    //set corner two, not permanently
	    storage.shapeFun->rectangle->setCornerTwo(ic->getMousePoint());
	} else if (storage.shapeFun->settingCircleSize)
	{
	    //set radius, not permanently
	    int radius = storage.shapeFun->circleCenter.distanceTo(ic->getMousePoint());

	    storage.shapeFun->circle->setRadius(radius);
	    storage.shapeFun->circle->setCenter(storage.shapeFun->circleCenter);
	} else if (storage.shapeFun->settingLineSize)
	{
	    //set point 2, not permanently
	    storage.shapeFun->line->setPosition2(ic->getMousePoint());
	} else if (ic->getPhysicalButtonStatus(KeyTab, ButtonDown))
	{
	    if (storage.shapeFun->mode == RectangleMode)
		storage.shapeFun->mode = CircleMode;
	    else if (storage.shapeFun->mode == CircleMode)
		storage.shapeFun->mode = LineMode;
	    else if (storage.shapeFun->mode == LineMode)
		storage.shapeFun->mode = RectangleMode;
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