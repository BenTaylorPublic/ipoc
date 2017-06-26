#include "OutputController.h"
#include "Settings.h"
#include "Debug.h"
#include "Point2D.h"
#include "Color.h"

OutputController::OutputController()
{
	Debug::notifyOfConstruction(3);
}

OutputController::~OutputController()
{
	Debug::notifyOfDestruction(3);
}

void OutputController::IPOCLoad(Frame* inputFrame)
{
	window.load();
	
	frame = inputFrame;
}

void OutputController::createGraphicsWindow(InputController* inputController)
{
	window.openWindow(Settings::screenWidth, Settings::screenHeight, Settings::screenTitle, Settings::windowType, Settings::hideCursor);
	inputController->setGraphicsWindow(&window);
}

void OutputController::closeGraphicsWindow()
{
	window.closeWindow();
}

void OutputController::output()
{
	while (!frame->isDrawable())
	{
		window.handleEvents();
	}

	window.clearWindow();
	window.drawFrame(frame);

	window.renderWindow();
}

std::string OutputController::getStatusString()
{
	std::string result = "OutputController:\n";

	result += window.getStatusString();

	return result;
}