
#pragma once

#include <string>
#include <vector>
#include <queue>
#include "OnscreenButton.h"
#include "InputController.h"

class OnscreenButtonManager
{
public:
    OnscreenButtonManager();
    ~OnscreenButtonManager();
    void IPOCLoad(InputController* inputControllerPtr);
    void addOnscreenButton(OnscreenButton* onscreenButtonToAdd);
    void removeOnscreenButton(OnscreenButton* onscreenButtonToAdd);
    void markStartOfLoop();
    void markEndOfLoop();
    std::string getStatusString();
private:
    InputController* inputController;
    std::vector<OnscreenButton*> onscreenButtons;
    std::queue<int> idsToGive;
    std::queue<OnscreenButton*> toClear;
};