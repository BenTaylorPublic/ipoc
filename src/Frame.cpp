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

void Frame::addToFrame(Drawable* drawable)
{
	views.at(drawable->getViewIndex())->addDrawable(drawable);
}

void Frame::drawAll(sf::RenderTarget& target)
{

	for (unsigned int zIndex = 0; zIndex < HIGHEST_Z_INDEX; zIndex++)
	{
		for (unsigned int viewIndex = 0; viewIndex < views.size(); viewIndex++)
		{
			views.at(viewIndex)->drawAllAtZ(zIndex, target);
		}
	}
	isDrawableBool = false;
}

std::string Frame::getStatusString() const
{
	return "N/A";
}

void Frame::IPOCLoad()
{
	for (unsigned int i = 0; i < AMOUNT_OF_VIEWS; i++)
	{
		views.push_back(new View());
		views.at(i)->IPOCLoad();
	}
}

bool Frame::isDrawable() const
{
	return isDrawableBool;
}

void Frame::markAsDrawable()
{
	isDrawableBool = true;
}

void Frame::removeFromFrame(Drawable* drawable)
{
	views.at(drawable->getViewIndex())->removeDrawable(drawable);
}

void Frame::setViewPort(const unsigned int& viewIndex,
						const float& topLeftX,
						const float& topLeftY,
						const float& sizeX,
						const float& sizeY)
{
	views.at(viewIndex)->setViewPort(topLeftX, topLeftY, sizeX, sizeY);
}

