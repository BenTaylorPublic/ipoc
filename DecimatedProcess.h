#pragma once

class DecimatedProcess {
public:
    DecimatedProcess();
    virtual ~DecimatedProcess();
    void tick();
    void setProcessEveryXLoops(const unsigned int& x);
    void setDecimatedProcessId(const int& inputId);
    bool tickBeforeLoop;
    bool decimatedProcessIdMatches(const int& inputId);
    int getDecimatedProcessId();
private:
    virtual void process() = 0;
    unsigned int counter;
    unsigned int counterGoal;
    int decimatedProcessId;
};