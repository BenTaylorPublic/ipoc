#include "AnimatedSprite.h"
#include "Debug.h"

AnimatedSprite::AnimatedSprite()
{
    Debug::notifyOfConstruction(12);
}

AnimatedSprite::~AnimatedSprite()
{
    Debug::notifyOfDestruction(12);
}

void AnimatedSprite::process()
{
    Debug::writeLine("PROCESS");
}