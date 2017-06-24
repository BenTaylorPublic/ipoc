#include "IPOCDrawable.h"

void IPOCDrawable::setFrameId(const int& inputFrameId)
{
	frameId = inputFrameId;
}

const int& IPOCDrawable::getFrameId()
{
	return frameId;
}

void IPOCDrawable::setZ(const int& inputZ)
{
	z = inputZ;
}

int IPOCDrawable::getZ()
{
	return z;
}