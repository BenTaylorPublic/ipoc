#include "DecimatedProcess.h"
#include "Debug.h"

DecimatedProcess::DecimatedProcess()
{
	tickBeforeLoop = true;
	counter = 0;
	Debug::notifyOfConstruction(11);
}

DecimatedProcess::~DecimatedProcess()
{
	Debug::notifyOfDestruction(11);
}

void DecimatedProcess::setProcessEveryXLoops(const unsigned int& x)
{
	counterGoal = x;
}

void DecimatedProcess::tick()
{
	counter++;
	if (counter == counterGoal)
	{
		process();
		counter = 0;
	}
}