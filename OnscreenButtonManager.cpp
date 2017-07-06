
#include "Debug.h"
#include "OnscreenButtonManager.h"

OnscreenButtonManager::OnscreenButtonManager()
{
    for (int i = 0; i < 50; i++)
    {
	idsToGive.push(i);
    }
    Debug::notifyOfConstruction(18);
}

OnscreenButtonManager::~OnscreenButtonManager()
{
    Debug::notifyOfDestruction(18);
}

void OnscreenButtonManager::IPOCLoad(InputController* inputControllerPtr)
{
    inputController = inputControllerPtr;
}

void OnscreenButtonManager::addOnscreenButton(OnscreenButton* onscreenButtonToAdd)
{
    onscreenButtons.push_back(onscreenButtonToAdd);
    onscreenButtonToAdd->setOnscreenButtonManagerId(idsToGive.front());
    idsToGive.pop();
}

void OnscreenButtonManager::removeOnscreenButton(OnscreenButton* onscreenButtonToAdd)
{
    for (int i = 0; i < onscreenButtons.size(); i++)
    {
	if (onscreenButtons[i]->getOnscreenButtonManagerId() == onscreenButtonToAdd->getOnscreenButtonManagerId())
	{
	    onscreenButtons.erase(onscreenButtons.begin() + i);
	    idsToGive.push(onscreenButtonToAdd->getOnscreenButtonManagerId());
	    onscreenButtonToAdd->setOnscreenButtonManagerId(-1);
	    return;
	}
    }
}

void OnscreenButtonManager::markStartOfLoop()
{

    Point2D mousePoint = inputController->getMousePoint();
    Debug::notifyOfCopy(12);

    if (inputController->getMouseStatus(LeftButton, ButtonUntouched))
    {
	return;
    } else if (inputController->getMouseStatus(LeftButton, ButtonDown))
    {
	for (OnscreenButton* it : onscreenButtons)
	{
	    if (it->mouseDown(mousePoint))
		toClear.push(it);
	}
    } else if (inputController->getMouseStatus(LeftButton, ButtonHold))
    {
	for (OnscreenButton* it : onscreenButtons)
	{
	    it->mouseHold(mousePoint);
	}

    } else if (inputController->getMouseStatus(LeftButton, ButtonUp))
    {
	for (OnscreenButton* it : onscreenButtons)
	{
	    if (it->mouseUp(mousePoint))
		toClear.push(it);
	}
    }

    toClear.push(nullptr);
}

void OnscreenButtonManager::markEndOfLoop()
{
    while (toClear.size() >= 1)
    {
	OnscreenButton* temp = toClear.front();
	if (temp == nullptr)
	{
	    toClear.pop();
	    return;
	} else
	{
	    temp->clearTriggered();
	    toClear.pop();
	}
    }
}

std::string OnscreenButtonManager::getStatusString()
{
    return "OnscreenButtonManager: Nothing to report\n";
}