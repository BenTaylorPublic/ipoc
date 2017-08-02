#include "Drawable.h"

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