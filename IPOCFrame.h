#pragma once

#include <string>
#include <vector>
#include <queue>
#include "Drawable.h"

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
    void addToFrame(Drawable* drawable);
    void removeFromFrame(Drawable* drawable);
    Drawable* getNextDrawable();
private:
    vector<vector<Drawable*>> drawables;
    queue<int> frameIdsToGive;
    bool isDrawableBool;
    int currentDrawingZ;
    int currentDrawingIndex;
};