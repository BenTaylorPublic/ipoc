#include "Identifiable.h"
#include "Debug.h"

unsigned int Identifiable::nextIdToAdd = 1;
std::queue<unsigned int> Identifiable::idsToGive;

Identifiable::Identifiable()
{
    id = 0;
}

Identifiable::~Identifiable()
{
    clearId();
}

void Identifiable::registerId()
{
    if (id != 0)
    {
	//Already has an id, so don't get a new one
	return;
    }
    if (idsToGive.empty())
    {
	//No IDs in the queue, so get the next one
	id = Identifiable::nextIdToAdd;
	Identifiable::nextIdToAdd++;
    } else
    {
	//Get the next id from the queue
	id = Identifiable::idsToGive.front();
	Identifiable::idsToGive.pop();
    }
}

void Identifiable::clearId()
{
    if (id != 0)
    {
	Identifiable::idsToGive.push(id);
	id = 0;
    }
}

bool Identifiable::matches(const Identifiable* identifiable) const
{
    return (id == identifiable->getId());
}

unsigned int Identifiable::getId() const
{
    return id;
}