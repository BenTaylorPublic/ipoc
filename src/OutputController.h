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
	void IPOCLoad(Frame* inputFrame);
	void createGraphicsWindow(InputController* inputController);
	void reloadGraphicsWindow(); //Used when the settings (resoltions, screen type etc) need to be refreshed
	void output();
	void closeGraphicsWindow();
	std::string getStatusString() const;
private:
	Window window;
	Frame* frame;
	bool reloadWindow = false;
};