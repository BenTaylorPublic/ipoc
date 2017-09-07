#pragma once

#include <string>
//increment this number when adding to the array
#define AMOUNT_OF_TRACKED_CLASSES 21

class TrackedClasses {
public:

    static std::string classNames[AMOUNT_OF_TRACKED_CLASSES];

    static void loadClassNames() {
        TrackedClasses::classNames[0] = "MasterController";
        TrackedClasses::classNames[1] = "InputController";
        TrackedClasses::classNames[2] = "ProcessController";
        TrackedClasses::classNames[3] = "OutputController";
        TrackedClasses::classNames[4] = "EMPTY";
        TrackedClasses::classNames[5] = "EMPTY";
        TrackedClasses::classNames[6] = "EMPTY";
        TrackedClasses::classNames[7] = "EMPTY";
        TrackedClasses::classNames[8] = "Storage";
        TrackedClasses::classNames[9] = "Window";
        TrackedClasses::classNames[10] = "OnscreenButton";
        TrackedClasses::classNames[11] = "Color";
        TrackedClasses::classNames[12] = "Point2D";
        TrackedClasses::classNames[13] = "Font";
        TrackedClasses::classNames[14] = "Text";
        TrackedClasses::classNames[15] = "Texture";
        TrackedClasses::classNames[16] = "Sprite";
        TrackedClasses::classNames[17] = "Frame";
        TrackedClasses::classNames[18] = "EMPTY";
        TrackedClasses::classNames[19] = "ThreadManager";
        TrackedClasses::classNames[20] = "Drawable";
    };
private:

};