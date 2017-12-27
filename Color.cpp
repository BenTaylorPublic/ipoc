#include "Color.h"
#include "Debug.h"

Color::Color(const int& inputR, const int& inputG, const int& inputB)
{
    if (inputR > 255 || inputG > 255 || inputB > 255)
    {
	Debug::logLine("[ERR] A color was made with R G or B over 255!");
    }

    r = inputR;
    g = inputG;
    b = inputB;

    Debug::notifyOfConstruction(5);
}

Color::Color()
{
    r = 0;
    g = 0;
    b = 0;
    Debug::notifyOfConstruction(5);
}

Color::~Color()
{
    Debug::notifyOfDestruction(5);
}

Color Color::Random()
{
    return Color(rand() % 256, rand() % 256, rand() % 256);
}

void Color::randomize()
{
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}

std::string Color::getStatusString() const
{
    std::string result = "(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
    return result;
}
