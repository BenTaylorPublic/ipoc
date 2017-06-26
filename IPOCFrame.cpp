#include "IPOCFrame.h"
#include "Debug.h"
#include "IPOCSettings.h"

IPOCFrame::IPOCFrame() : drawables (1, vector<Drawable*>(0))
{
	isDrawableBool = false;
	Debug::notifyOfConstruction(17);
}

IPOCFrame::~IPOCFrame()
{
	Debug::notifyOfDestruction(17);	
}

void IPOCFrame::IPOCLoad()
{	
	vector<Drawable*> toAdd;
	for (int i = 0; i < IPOCSettings::maxZ; i++)
	{
		drawables.push_back(toAdd);
	}
	
	for (int i = 0; i < IPOCSettings::maxDrawables; i++)
	{
		frameIdsToGive.push(i);
	}
}

std::string IPOCFrame::getStatusString()
{
	return "N/A";
}

void IPOCFrame::markStartOfDrawing()
{
	currentDrawingIndex = 0;
	currentDrawingZ = 0;
}

void IPOCFrame::addToFrame(Drawable* drawable)
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

void IPOCFrame::removeFromFrame(Drawable* drawable)
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

Drawable* IPOCFrame::getNextDrawable()
{
	while (true)
	{
		if (drawables.at(currentDrawingZ).size() > currentDrawingIndex)
		{
			currentDrawingIndex++;
			return drawables.at(currentDrawingZ).at(currentDrawingIndex - 1);
		}
		else if (drawables.size() - 1 > currentDrawingZ)
		{
			currentDrawingZ++;
			currentDrawingIndex = 0;
		}
		else
		{
			isDrawableBool = false; //End of the frame
			return nullptr;
		}
	}
	
}

void IPOCFrame::markAsDrawable()
{
//	if (isDrawableBool)//Output isn't keeping up (get a better GPU lmao)
//	{
//		Debug::write("!");
//	}
	
	isDrawableBool = true;
}

bool IPOCFrame::isDrawable()
{
	return isDrawableBool;
}

