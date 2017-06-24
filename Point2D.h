#pragma once

#include <string>

using namespace std;

/*
Point2D is a Data Type
Point2D is used to indicate a position on the screen
Point2D contains 2 doubles to indicate the position
*/
class Point2D
{
public:
    Point2D(const double& inputX, const double& inputY); //Creates a new Point2D, with X and Y specified
    Point2D(const int& inputX, const int& inputY); //Creates a new Point2D, with X and Y specified
    Point2D(); //Creates a new Point2D, with X and Y defaulted to 0
    ~Point2D();
    Point2D operator+(const Point2D& rhs);
    Point2D operator-(const Point2D& rhs);
    Point2D& operator+=(const Point2D& rhs);
    Point2D getRelative(const Point2D& otherPoint);
    void random(const int& maxX, const int& maxY); //Sets X and Y to a random double, between 0 and the maximum specified
    double x; //X component of the position
    double y; //Y component of the position
    /*
    Returns a string indicating this object's current status, and all objects it manages.
    Should only be used for debugging, but not strictly.
    */
    std::string getStatusString();
private:
};