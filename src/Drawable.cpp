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

void Drawable::setZIndex(const unsigned int& inputZIndex)
{
	zIndex = inputZIndex;
}

unsigned int Drawable::getZIndex() const
{
	return zIndex;
}

void Drawable::setViewIndex(const unsigned int& inputViewIndex)
{
	viewIndex = inputViewIndex;
}

unsigned int Drawable::getViewIndex() const
{
	return viewIndex;
}