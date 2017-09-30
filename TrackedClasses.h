#pragma once

#include <string>
//increment this number when adding to the array
#define AMOUNT_OF_TRACKED_CLASSES 10

class TrackedClasses {
public:

    static std::string classNames[AMOUNT_OF_TRACKED_CLASSES];

    static void loadClassNames() {
        TrackedClasses::classNames[0] = "Font";
        TrackedClasses::classNames[1] = "Texture";
        TrackedClasses::classNames[2] = "Text";
        TrackedClasses::classNames[3] = "Sprite";
        TrackedClasses::classNames[4] = "Point2D";
        TrackedClasses::classNames[5] = "Color";
        TrackedClasses::classNames[6] = "OnscreenButton";
        TrackedClasses::classNames[7] = "Drawable";
        TrackedClasses::classNames[8] = "Rectangle";
        TrackedClasses::classNames[9] = "Circle";
    };
private:

};