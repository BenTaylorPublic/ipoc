#include "DecimatedProcess.h"
#include "Debug.h"

DecimatedProcess::DecimatedProcess()
{
    decimatedProcessId = -1;
    tickBeforeLoop = true;
    counter = 0;
    Debug::notifyOfConstruction(11);
}

DecimatedProcess::~DecimatedProcess()
{
    Debug::notifyOfDestruction(11);
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

void DecimatedProcess::setProcessEveryXLoops(const unsigned int& x)
{
    counterGoal = x;
}

void DecimatedProcess::setDecimatedProcessId(const int& inputId)
{
    decimatedProcessId = inputId;
}

bool DecimatedProcess::decimatedProcessIdMatches(const int& inputId)
{
    return (decimatedProcessId == inputId);
}

int DecimatedProcess::getDecimatedProcessId()
{
    return decimatedProcessId;
}