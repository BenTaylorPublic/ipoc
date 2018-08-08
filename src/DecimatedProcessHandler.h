#pragma once

#include <vector>
#include "DecimatedProcess.h"

class DecimatedProcessHandler
{
public:
	DecimatedProcessHandler();
	~DecimatedProcessHandler();
	void IPOCLoad();
	void markStartOfLoop();
	void markEndOfLoop();
	void addToHandler(DecimatedProcess* decimatedProcessesToAdd);
	void removeFromHandler(DecimatedProcess* decimatedProcessesToRemove);
private:
	std::vector<DecimatedProcess*> decimatedProcessesPreLoop;
	std::vector<DecimatedProcess*> decimatedProcessesPostLoop;
};