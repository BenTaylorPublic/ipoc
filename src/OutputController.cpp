#include "OutputController.h"
#include "Settings.h"
#include "Debug.h"
#include "Point2D.h"
#include "Color.h"

OutputController::OutputController()
{
}

OutputController::~OutputController()
{
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

	if (true) //LETTER BOX / BLACK BARS enabled
	{
		double ratio = Settings::screenHeight / Settings::screenWidth;
		double ratioTarget = 19.0 / 9.0;
		if (ratio != ratioTarget)
		{
			//Letter boxing needed


			float windowRatio = Settings::screenWidth / (float) Settings::screenHeight;
			float viewRatio = (float) 16 / (float) 9;
			float sizeX = 1;
			float sizeY = 1;
			float posX = 0;
			float posY = 0;

			bool horizontalSpacing = true;
			if (windowRatio < viewRatio)
				horizontalSpacing = false;

			// If horizontalSpacing is true, the black bars will appear on the left and right side.
			// Otherwise, the black bars will appear on the top and bottom.

			if (horizontalSpacing)
			{
				sizeX = viewRatio / windowRatio;
				posX = (1 - sizeX) / 2.f;
			} else
			{
				sizeY = windowRatio / viewRatio;
				posY = (1 - sizeY) / 2.f;
			}

			frame->setViewPort(0, posX, posY, sizeX, sizeY);
		}
	}
}

void OutputController::reloadGraphicsWindow()
{
	reloadWindow = true;
	Settings::inputStatus = InputStatus::PauseRequested;
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

		if (reloadWindow && Settings::inputStatus == Paused)
		{
			window.openWindow(Settings::screenWidth, Settings::screenHeight, Settings::screenTitle, Settings::windowType, Settings::hideCursor);
			reloadWindow = false;
			Settings::inputStatus = Active;
		}
	}

	window.clearWindow();
	window.drawFrame(frame);

	window.renderWindow();
}

std::string OutputController::getStatusString() const
{
	std::string result = "OutputController:\n";

	result += window.getStatusString();

	return result;
}