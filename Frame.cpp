#include "Frame.h"
#include "Debug.h"
#include "Settings.h"

Frame::Frame() : drawables(1, std::vector<Drawable*>(0))
{
    isDrawableBool = false;
    Debug::notifyOfConstruction(17);
}

Frame::~Frame()
{
    Debug::notifyOfDestruction(17);
}

void Frame::IPOCLoad()
{
    vector<Drawable*> toAdd;
    for (int i = 0; i < Settings::maxZ; i++)
    {
	drawables.push_back(toAdd);
    }

    for (int i = 0; i < Settings::maxDrawables; i++)
    {
	frameIdsToGive.push(i);
    }
}

std::string Frame::getStatusString()
{
    return "N/A";
}

void Frame::markStartOfDrawing()
{
    currentDrawingIndex = 0;
    currentDrawingZ = 0;
}

void Frame::addToFrame(Drawable* drawable)
{
    drawables.at(drawable->getZ()).push_back(drawable);
    if (frameIdsToGive.size() == 0)
    {
	Debug::log("[CRASH] frameIdsToGive is empty.");
	Debug::commitLogLine();
	Debug::log("[CRASH] There are too many drawables.");
	Debug::commitLogLine();
	Debug::crash(103, "IPOCFrame.addToFrame()");
    }

    drawable->setFrameId(frameIdsToGive.front());
    frameIdsToGive.pop();
}

void Frame::removeFromFrame(Drawable* drawable)
{
    int z = drawable->getZ();

    if (z == -1)
	return;

    for (int i = 0; i < drawables.at(z).size(); i++)
    {
	if (drawables.at(z).at(i)->getFrameId() == drawable->getFrameId())
	{
	    drawables.at(z).erase(drawables.at(z).begin() + i);
	    frameIdsToGive.push(drawable->getFrameId());
	    drawable->setFrameId(-1);
	    return;
	}
    }
}

Drawable* Frame::getNextDrawable()
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
    //	if (isDrawableBool)//Output isn't keeping up (get a better GPU lmao)
    //	{
    //		Debug::write("!");
    //	}

    isDrawableBool = true;
}

bool Frame::isDrawable()
{
    return isDrawableBool;
}

