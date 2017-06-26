#pragma once
#include <string>
#include "IPOCWindow.h"
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
    void output();
    void closeGraphicsWindow();
    std::string getStatusString();
private:
    IPOCWindow window;
    Frame* frame;
};