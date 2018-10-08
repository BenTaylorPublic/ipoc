#pragma once

#include <string>
#include "Window.h"
#include "InputController.h"
#include "Storage.h"
#include "Frame.h"

class OutputController
{
public:
	OutputController();
	~OutputController();
	void closeGraphicsWindow();
	void createGraphicsWindow(InputController* inputController);
	std::string getStatusString() const;
	void IPOCLoad(Frame* inputFrame);
	void output();
	void reloadGraphicsWindow(); //Used when the settings (resoltions, screen type etc) need to be refreshed
private:
	Window window;
	Frame* frame;
	bool reloadWindow = false;
};