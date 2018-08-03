#pragma once
#include "Identifiable.h"

class DecimatedProcess : public Identifiable {
public:
    DecimatedProcess();
    virtual ~DecimatedProcess();
    void tick();
    void setProcessEveryXLoops(const unsigned int& x);
    bool tickBeforeLoop;
private:
    virtual void process() = 0;
    unsigned int counter;
    unsigned int counterGoal;
};