#pragma once

#include <string>

/**
 * Point2D is a Data Type
 * Point2D is used to indicate a position on the screen
 * Point2D contains 2 doubles to indicate the position
 */
class Point2D
{
public:
	/**
	 * Creates a new Point2D, with X and Y specified
	 * @param inputX x component of the Point2D
	 * @param inputY y component of the Point2D
	 */
	Point2D(const double& inputX,
			const double& inputY);
	/**
	 * Creates a new Point2D, with X and Y specified
	 * @param inputX x component of the Point2D
	 * @param inputY y component of the Point2D
	 */
	Point2D(const int& inputX,
			const int& inputY);
	/**
	 * Default constructor, setting x and y to 0
	 */
	Point2D();
	/**
	 * Destructor for Point2D
	 */
	~Point2D();
	/**
	 * Gets the distance between two Point2D
	 * @param otherPoint Point2D to get the distance to
	 * @return the double of how far between the two Point2D
	 */
	double distanceTo(const Point2D& otherPoint) const;
	/**
	 * Gets a Point2D of the difference between the two points \n
	 * Not sure if this is a good way to do it (maybe the return should be a new class called Vector2D)
	 * @param otherPoint Point2D to compare to
	 * @return Point2D of the difference between the two points
	 */
	Point2D getRelative(const Point2D& otherPoint);
	/**
	 * Returns a string indicating this object's current status, and all objects it manages. \n
	 * Should only be used for debugging, but not strictly.
	 * @return status string
	 */
	std::string getStatusString() const;
	/**
	 * Randomizes the x and y value between 0 and it's respective Max
	 * @param maxX Limits x to between 0 and maxX
	 * @param maxY Limits y to between 0 and maxY
	 */
	void random(const int& maxX,
				const int& maxY);
	Point2D operator+(const Point2D& rhs);
	Point2D operator-(const Point2D& rhs);
	Point2D& operator+=(const Point2D& rhs);
	double x;
	double y;
private:
};