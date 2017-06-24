#pragma once

#include <string>
#include <vector>
#include <queue>
#include "IPOCDrawable.h"

class IPOCFrame
{
public:
    IPOCFrame();
    ~IPOCFrame();
    void IPOCLoad();
    std::string getStatusString();
    void markStartOfDrawing();
    void markAsDrawable();
    bool isDrawable();
    void addToFrame(IPOCDrawable* drawable);
    void removeFromFrame(IPOCDrawable* drawable);
    IPOCDrawable* getNextDrawable();
private:
    vector<vector<IPOCDrawable*>> drawables;
    queue<int> frameIdsToGive;
    bool isDrawableBool;
    int currentDrawingZ;
    int currentDrawingIndex;
};