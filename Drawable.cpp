#include "Drawable.h"
#include "Debug.h"

Drawable::Drawable()
{
    Debug::notifyOfConstruction(7);
}

Drawable::~Drawable()
{
    Debug::notifyOfDestruction(7);
}

void Drawable::setZ(const unsigned int& inputZ)
{
    z = inputZ;
}

int Drawable::getZ() const
{
    return z;
}