#include "Point2D.h"
#include "Debug.h"

Point2D::Point2D(const double& inputX, const double& inputY)
{
	x = inputX;
	y = inputY;
	Debug::notifyOfConstruction(12);
}

Point2D::Point2D(const int& inputX, const int& inputY)
{
	x = inputX;
	y = inputY;
	Debug::notifyOfConstruction(12);
}

Point2D::Point2D()
{
	x = 0;
	y = 0;
	Debug::notifyOfConstruction(12);
}

Point2D::~Point2D()
{
	Debug::notifyOfDestruction(12);	
}

Point2D Point2D::operator+(const Point2D& rhs)
{
	return Point2D(x + rhs.x, y + rhs.y);
}

Point2D Point2D::operator-(const Point2D& rhs)
{
	return Point2D(x - rhs.x, y - rhs.y);
}

Point2D& Point2D::operator+=(const Point2D& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Point2D Point2D::getRelative(const Point2D& otherPoint)
{
	return Point2D(otherPoint.x - x, otherPoint.y - y);
}

void Point2D::random(const int& maxX, const int& maxY)
{
	x = rand() % maxX + 1;
	y = rand() % maxY + 1;
}

std::string Point2D::getStatusString()
{
	return "(" + to_string((int)x) + "," + to_string((int)y) + ")";
}