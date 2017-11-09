#pragma once
#include "DecimatedProcess.h"

class AnimatedSprite : public DecimatedProcess {
public:
    AnimatedSprite();
    ~AnimatedSprite();
    void process() override;
private:
};