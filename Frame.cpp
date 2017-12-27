#include "Frame.h"
#include "Debug.h"
#include "Settings.h"

Frame::Frame()
{
    isDrawableBool = false;
}

Frame::~Frame()
{
    for (View* it : views)
    {
	delete it;
    }
    views.clear();
}

void Frame::IPOCLoad()
{
    for (unsigned int i = 0; i < MAX_VIEWS; i++)
    {
	views.push_back(new View());
	views.at(i)->IPOCLoad();
    }
}

void Frame::addToFrame(Drawable* drawable)
{
    views.at(drawable->getViewIndex())->addDrawable(drawable);
}

void Frame::removeFromFrame(Drawable* drawable)
{
    views.at(drawable->getViewIndex())->removeDrawable(drawable);
}

void Frame::drawAll(sf::RenderTarget& target)
{

    for (unsigned int zIndex = 0; zIndex < MAX_Z; zIndex++)
    {
	for (unsigned int viewIndex = 0; viewIndex < views.size(); viewIndex++)
	{
	    views.at(viewIndex)->drawAllAtZ(zIndex, target);
	}
    }
    isDrawableBool = false;
}

void Frame::markAsDrawable()
{
    isDrawableBool = true;
}

bool Frame::isDrawable() const
{
    return isDrawableBool;
}

std::string Frame::getStatusString() const
{
    return "N/A";
}

