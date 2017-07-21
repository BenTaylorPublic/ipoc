#include "Drawable.h"

void Drawable::setFrameId(const int& inputFrameId)
{
    frameId = inputFrameId;
}

const int& Drawable::getFrameId()
{
    return frameId;
}

void Drawable::setZ(const int& inputZ)
{
    z = inputZ;
}

int Drawable::getZ()
{
    return z;
}