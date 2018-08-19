#include "Color.h"
#include "Debug.h"

Color::Color(const int& inputR,
			 const int& inputG,
			 const int& inputB)
{
	if (inputR > 255 || inputG > 255 || inputB > 255)
	{
		Debug::logLine("[ERR] A color was made with R G or B over 255!");
	}

	red = inputR;
	green = inputG;
	blue = inputB;

	Debug::notifyOfConstruction(5);
}

Color::Color()
{
	red = 0;
	green = 0;
	blue = 0;
	Debug::notifyOfConstruction(5);
}

Color::~Color()
{
	Debug::notifyOfDestruction(5);
}

Color Color::random()
{
	return Color(rand() % 256, rand() % 256, rand() % 256);
}

void Color::randomize()
{
	red = rand() % 256;
	green = rand() % 256;
	blue = rand() % 256;
}

std::string Color::getStatusString() const
{
	std::string result = "(" + std::to_string(red) + "," + std::to_string(green) + "," + std::to_string(blue) + ")";
	return result;
}
