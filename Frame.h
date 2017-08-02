#pragma once

#include <string>
#include <vector>
#include <queue>
#include "Drawable.h"

class Frame
{
public:
    Frame();
    ~Frame();
    void IPOCLoad();
    std::string getStatusString();
    void markStartOfDrawing();
    void markAsDrawable();
    bool isDrawable();
    void addToFrame(Drawable* drawable);
    void removeFromFrame(Drawable* drawable);
    Drawable* getNextDrawable();
private:
    std::vector<std::vector<Drawable*> > drawables;
    std::queue<unsigned int> frameIdsToGive;
    bool isDrawableBool;
    int currentDrawingZ;
    int currentDrawingIndex;
};