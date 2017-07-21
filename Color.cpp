#include "Color.h"
#include "Debug.h"

Color::Color(const int& inputR, const int& inputG, const int& inputB)
{
    if (inputR > 255 || inputG > 255 || inputB > 255)
    {
	Debug::log("[ERR] A color was made with R G or B over 255!\n");
    }

    r = inputR;
    g = inputG;
    b = inputB;

    Debug::notifyOfConstruction(11);
}

Color::Color()
{
    r = 0;
    g = 0;
    b = 0;
    Debug::notifyOfConstruction(11);
}

Color::~Color()
{
    Debug::notifyOfDestruction(11);
}

void Color::random()
{
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}

std::string Color::getStatusString()
{
    std::string result = "(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
    return result;
}
