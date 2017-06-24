#include "OutputController.h"
#include "IPOCSettings.h"
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

void OutputController::IPOCLoad(IPOCFrame* inputFrame)
{
	window.load();
	
	frame = inputFrame;
}

void OutputController::createGraphicsWindow(InputController* inputController)
{
	window.openWindow(IPOCSettings::screenWidth, IPOCSettings::screenHeight, IPOCSettings::screenTitle, IPOCSettings::windowType, IPOCSettings::hideCursor);
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