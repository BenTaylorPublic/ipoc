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

bool ProcessController::checkForExitProgram() const
{
	return exitProgram;
}

std::string ProcessController::getStatusString() const
{
	std::string result = "exitProgram: ";
	if (exitProgram)
		result += "true\n";
	else
		result += "false\n";

	result += "loopNumber: " + std::to_string(loopNumber) + "\n";

	return result;
}

void ProcessController::incrementLoopNumber()
{
	loopNumber++;
}

void ProcessController::IPOCLoad(InputController* inputControllerPtr,
								 Frame* inputFrame,
								 OutputController* outputControllerPtr,
								 DecimatedProcessHandler* decimatedProcessHandlerPtr,
								 Storage* storagePtr)
{
	inputController = inputControllerPtr;
	outputController = outputControllerPtr;
	exitProgram = false;
	loopNumber = 0;
	frame = inputFrame;
	decimatedProcessHandler = decimatedProcessHandlerPtr;
	storage = storagePtr;
	threadManager.IPOCLoad(storage, frame, inputController, decimatedProcessHandler);
}

void ProcessController::load()
{
}

void ProcessController::process()
{
	if (inputController->getPhysicalButtonStatus(PhysicalButton::KeyEscape, ButtonStatus::ButtonDown))
	{
		exitProgram = true;
	}
}