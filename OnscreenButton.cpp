#include "OnscreenButton.h"
#include "Debug.h"

OnscreenButton::OnscreenButton()
{
    Debug::notifyOfConstruction(10);
}

OnscreenButton::OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType)
{
    onscreenButtonType = inputOnscreenButtonType;
    Debug::notifyOfConstruction(10);
}

OnscreenButton::OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType, const unsigned int& inputZ)
{
    setZ(inputZ);
    onscreenButtonType = inputOnscreenButtonType;
    Debug::notifyOfConstruction(10);
}

OnscreenButton::OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType, const unsigned int& inputZ, const Point2D& point)
{
    setZ(inputZ);
    setPosition(point);
    onscreenButtonType = inputOnscreenButtonType;
    Debug::notifyOfConstruction(10);
}

OnscreenButton::~OnscreenButton()
{
    for (Drawable* it : stateUpDrawables)
    {
	delete it;
    }
    stateUpDrawables.clear();
    stateUpOffset.clear();

    for (Drawable* it : stateDownDrawables)
    {
	delete it;
    }
    stateDownDrawables.clear();
    stateDownOffset.clear();

    Debug::notifyOfDestruction(10);
}

void OnscreenButton::addToUp(Drawable* drawable, const Point2D& offsetFromTopLeft)
{
    Debug::notifyOfCopy(12);
    Debug::notifyOfCopy(12);
    drawable->setPosition(drawingPosition + offsetFromTopLeft);
    stateUpDrawables.push_back(drawable);
    stateUpOffset.push_back(offsetFromTopLeft);
}

void OnscreenButton::addToDown(Drawable* drawable, const Point2D& offsetFromTopLeft)
{
    Debug::notifyOfCopy(12);
    Debug::notifyOfCopy(12);
    drawable->setPosition(drawingPosition + offsetFromTopLeft);
    stateDownDrawables.push_back(drawable);
    stateDownOffset.push_back(offsetFromTopLeft);
}

void OnscreenButton::addToUp(Drawable* drawable)
{
    Debug::notifyOfCopy(12);
    drawable->setPosition(drawingPosition);
    stateUpDrawables.push_back(drawable);
    stateUpOffset.push_back(Point2D(0, 0));
}

void OnscreenButton::addToDown(Drawable* drawable)
{
    Debug::notifyOfCopy(12);
    drawable->setPosition(drawingPosition);
    stateDownDrawables.push_back(drawable);
    stateDownOffset.push_back(Point2D(0, 0));
}

void OnscreenButton::setHitBox(const Point2D& inputTopLeft, const Point2D& inputBottomRight)
{
    hitBoxTopLeft = drawingPosition + inputTopLeft;
    hitBoxBottomRight = drawingPosition + inputBottomRight;
}

bool OnscreenButton::isTriggered()
{
    return triggered;
}

void OnscreenButton::draw(sf::RenderTarget& target)
{
    if (stateUp)
    {
	for (Drawable* it : stateUpDrawables)
	{
	    it->draw(target);
	}
    } else
    {
	for (Drawable* it : stateDownDrawables)
	{
	    it->draw(target);
	}
    }
}

void OnscreenButton::setPosition(const Point2D& newPoint)
{
    Point2D relativeNewPosition = drawingPosition.getRelative(newPoint);
    drawingPosition = newPoint;

    for (int i = 0; i < stateUpDrawables.size(); i++)
    {
	stateUpDrawables[i]->setPosition(stateUpOffset[i] + drawingPosition);
    }

    for (int i = 0; i < stateDownDrawables.size(); i++)
    {
	stateDownDrawables[i]->setPosition(stateDownOffset[i] + drawingPosition);
    }

    hitBoxTopLeft += relativeNewPosition;
    hitBoxBottomRight += relativeNewPosition;
}

bool OnscreenButton::mouseDown(const Point2D& mousePoint)
{
    if (isInside(mousePoint))
    {
	stateUp = false;
	if (onscreenButtonType == TriggerOnDown)
	{
	    triggered = true;
	    return true;
	} else if (onscreenButtonType == TriggerOnHold)
	{
	    triggered = true;
	}
    }
    return false;
}

void OnscreenButton::mouseHold(const Point2D& mousePoint)
{
    if (!isInside(mousePoint))
    {
	stateUp = true;
	if (onscreenButtonType == TriggerOnHold)
	{
	    triggered = false;
	}
    }
}

bool OnscreenButton::mouseUp(const Point2D& mousePoint)
{
    if (isInside(mousePoint))
    {
	if (onscreenButtonType == TriggerOnUp)
	{
	    if (!stateUp)
	    {
		stateUp = true;
		triggered = true;
		return true;
	    }
	}
    }
    triggered = false;
    stateUp = true;
    return false;
}

void OnscreenButton::setOnscreenButtonManagerId(const unsigned int& newId)
{
    onscreenButtonManagerId = newId;
}

void OnscreenButton::setButtonTriggerType(const OnscreenButtonType& inputOnscreenButtonType)
{
    onscreenButtonType = inputOnscreenButtonType;
}

unsigned int& OnscreenButton::getOnscreenButtonManagerId()
{
    return onscreenButtonManagerId;
}

bool OnscreenButton::isInside(const Point2D& point)
{
    if (point.x > hitBoxTopLeft.x && point.x < hitBoxBottomRight.x)
    {
	if (point.y > hitBoxTopLeft.y && point.y < hitBoxBottomRight.y)
	{
	    return true;
	}
    }
    return false;
}

void OnscreenButton::clearTriggered()
{
    triggered = false;
}

std::string OnscreenButton::getStatusString()
{
    return "N/A";
}