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
    for (int i = 1; i <= MAX_DECIMATED_PROCESSES; i++)
    {
	decimatedProcessIdsToGive.push(i);
    }
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

    if (decimatedProcessIdsToGive.size() == 0)
    {
	Debug::logLine("[CRASH] decimatedProcessIdsToGive is empty.");
	Debug::logLine("[CRASH] There are too many decimated processes.");
	Debug::crash(108, "DecimatedProcessHandler.addToHandler()");
    }

    decimatedProcessesToAdd->setDecimatedProcessId(decimatedProcessIdsToGive.front());
    decimatedProcessIdsToGive.pop();
}

void DecimatedProcessHandler::removeFromHandler(DecimatedProcess* decimatedProcessesToRemove)
{
    if (decimatedProcessesToRemove->tickBeforeLoop)
    {
	for (int i = 0; i < decimatedProcessesPreLoop.size(); i++)
	{
	    if (decimatedProcessesToRemove->decimatedProcessIdMatches(decimatedProcessesPreLoop[i]->getDecimatedProcessId()))
	    {
		decimatedProcessesPreLoop.erase(decimatedProcessesPreLoop.begin() + i);
		decimatedProcessIdsToGive.push(decimatedProcessesToRemove->getDecimatedProcessId());
		decimatedProcessesToRemove->setDecimatedProcessId(0);
	    }
	}
    } else
    {
	for (int i = 0; i < decimatedProcessesPostLoop.size(); i++)
	{
	    if (decimatedProcessesToRemove->decimatedProcessIdMatches(decimatedProcessesPostLoop[i]->getDecimatedProcessId()))
	    {
		decimatedProcessesPostLoop.erase(decimatedProcessesPostLoop.begin() + i);
		decimatedProcessIdsToGive.push(decimatedProcessesToRemove->getDecimatedProcessId());
		decimatedProcessesToRemove->setDecimatedProcessId(0);
	    }
	}
    }
}