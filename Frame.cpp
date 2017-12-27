#include "Frame.h"
#include "Debug.h"
#include "Settings.h"

Frame::Frame() : drawables(1, std::vector<Drawable*>(0))
{
    isDrawableBool = false;
}

Frame::~Frame()
{
}

void Frame::IPOCLoad()
{
    std::vector<Drawable*> toAdd;
    for (unsigned int i = 0; i < MAX_Z; i++)
    {
	drawables.push_back(toAdd);
    }
}

void Frame::markStartOfDrawing()
{
    currentDrawingIndex = 0;
    currentDrawingZ = 0;
}

void Frame::addToFrame(Drawable* drawable)
{
    drawables.at(drawable->getZ()).push_back(drawable);
    drawable->registerId();
}

void Frame::removeFromFrame(Drawable* drawable)
{
    int z = drawable->getZ();

    for (unsigned int i = 0; i < drawables.at(z).size(); i++)
    {
	if (drawables.at(z).at(i)->matches(drawable))
	{
	    drawables.at(z).erase(drawables.at(z).begin() + i);
	    drawable->clearId();
	    return;
	}
    }
}

const Drawable* Frame::getNextDrawable()
{
    while (true)
    {
	if (drawables.at(currentDrawingZ).size() > currentDrawingIndex)
	{
	    currentDrawingIndex++;
	    return drawables.at(currentDrawingZ).at(currentDrawingIndex - 1);
	} else if (drawables.size() - 1 > currentDrawingZ)
	{
	    currentDrawingZ++;
	    currentDrawingIndex = 0;
	} else
	{
	    isDrawableBool = false; //End of the frame
	    return nullptr;
	}
    }

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

