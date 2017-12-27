#pragma once

#include <string>
#include <vector>
#include <queue>
#include "Drawable.h"

class Frame {
public:
    Frame();
    ~Frame();
    void IPOCLoad();
    void markStartOfDrawing();
    void markAsDrawable();
    bool isDrawable() const;
    void addToFrame(Drawable* drawable);
    void removeFromFrame(Drawable* drawable);
    const Drawable* getNextDrawable();
    std::string getStatusString() const;
private:
    std::vector<std::vector<Drawable*> > drawables;
    bool isDrawableBool;
    int currentDrawingZ;
    int currentDrawingIndex;
};