#include "Identifiable.h"
#include "Debug.h"

unsigned int Identifiable::nextIdToAdd = 1;
std::queue<unsigned int> Identifiable::idsToGive;

Identifiable::Identifiable()
{
    id[0] = 0;
    id[1] = 0;
    Debug::notifyOfConstruction(14);
}

Identifiable::~Identifiable()
{
    for (unsigned int i = 0; i < ID_MAX; i++)
    {
	clearId(i);
    }
    Debug::notifyOfDestruction(14);
}

void Identifiable::registerId(const unsigned int& idIndex)
{
    if (id[idIndex] != 0)
    {
	//Already has an id, so don't get a new one
	return;
    }
    if (idsToGive.empty())
    {
	//No IDs in the queue, so get the next one
	id[idIndex] = Identifiable::nextIdToAdd;
	Identifiable::nextIdToAdd++;
    } else
    {
	//Get the next id from the queue
	id[idIndex] = Identifiable::idsToGive.front();
	Identifiable::idsToGive.pop();
    }
}

void Identifiable::clearId(const unsigned int& idIndex)
{
    if (id[idIndex] != 0)
    {
	Identifiable::idsToGive.push(id[idIndex]);
	id[idIndex] = 0;
    }
}

bool Identifiable::matches(const Identifiable* identifiable, const unsigned int& idIndex) const
{
    return (id[idIndex] == identifiable->getId(idIndex));
}

unsigned int Identifiable::getId(const unsigned int& idIndex) const
{
    return id[idIndex];
}