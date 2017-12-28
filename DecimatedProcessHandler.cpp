#include "DecimatedProcessHandler.h"
#include "Settings.h"
#include "Debug.h"

DecimatedProcessHandler::DecimatedProcessHandler()
{

}

DecimatedProcessHandler::~DecimatedProcessHandler()
{

}

void DecimatedProcessHandler::IPOCLoad()
{
}

void DecimatedProcessHandler::markStartOfLoop()
{
    for (int i = 0; i < decimatedProcessesPreLoop.size(); i++)
    {
	decimatedProcessesPreLoop[i]->tick();
    }

}

void DecimatedProcessHandler::markEndOfLoop()
{
    for (int i = 0; i < decimatedProcessesPostLoop.size(); i++)
    {
	decimatedProcessesPostLoop[i]->tick();
    }
}

void DecimatedProcessHandler::addToHandler(DecimatedProcess* decimatedProcessesToAdd)
{
    if (decimatedProcessesToAdd->tickBeforeLoop)
    {
	decimatedProcessesPreLoop.push_back(decimatedProcessesToAdd);
    } else
    {
	decimatedProcessesPostLoop.push_back(decimatedProcessesToAdd);
    }

    decimatedProcessesToAdd->registerId(ID_DECIMATED_PROCESS);
}

void DecimatedProcessHandler::removeFromHandler(DecimatedProcess* decimatedProcessesToRemove)
{
    if (decimatedProcessesToRemove->tickBeforeLoop)
    {
	for (int i = 0; i < decimatedProcessesPreLoop.size(); i++)
	{
	    if (decimatedProcessesToRemove->matches(decimatedProcessesPreLoop[i], ID_DECIMATED_PROCESS))
	    {
		decimatedProcessesPreLoop.erase(decimatedProcessesPreLoop.begin() + i);
		decimatedProcessesToRemove->clearId(ID_DECIMATED_PROCESS);
	    }
	}
    } else
    {
	for (int i = 0; i < decimatedProcessesPostLoop.size(); i++)
	{
	    if (decimatedProcessesToRemove->matches(decimatedProcessesPostLoop[i], ID_DECIMATED_PROCESS))
	    {
		decimatedProcessesPostLoop.erase(decimatedProcessesPostLoop.begin() + i);
		decimatedProcessesToRemove->clearId(ID_DECIMATED_PROCESS);
	    }
	}
    }
}