#include "Drawable.h"
#include "Debug.h"

Drawable::Drawable()
{
    Debug::notifyOfConstruction(20);
}

Drawable::~Drawable()
{
    Debug::notifyOfDestruction(20);
}

void Drawable::setFrameId(const unsigned int& inputFrameId)
{
    frameId = inputFrameId;
}

const unsigned int& Drawable::getFrameId()
{
    return frameId;
}

void Drawable::setZ(const unsigned int& inputZ)
{
    z = inputZ;
}

int Drawable::getZ()
{
    return z;
}