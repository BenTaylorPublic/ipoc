#pragma once

#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Point2D.h"
#include "Color.h"

/**
 * Circle is a data type \n
 * Circle has a TrackedClasses ID of 5
 */
class Circle : public Drawable
{
public:
	/**
	 * Constructor for the Circle class
	 */
	Circle();
	/**
	 * Destructor for the Circle class
	 */
	~Circle();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Draws the Circle to the render target \n
	 * @param target sf::RenderTarget render target to draw to
	 */
	void draw(sf::RenderTarget& target) const override;
	/**
	 * Sets the center position of the Circle \n
	 * This function is based off the Circle's current radius, so use setRadius() before using setCenter()
	 * @param newPoint Point2D new center point for the Circle
	 */
	void setCenter(const Point2D& newPoint);
	/**
	 * Sets the Circle's fill color
	 * @param color Color new fill color for the Circle
	 */
	void setColor(const Color& color);
	/**
	 * The point count define how many points there are around the Circle \n
	 * This affects the Circle's smoothness, but can also impact on performance \n
	 * I believe the default point count is 30.
	 * @param pointCount int the new amount of points for the circle
	 */
	void setPointCount(const int& pointCount);
	/**
	 * Sets the top left position of the Circle
	 * @param newPoint Point2D new point to set as the new top left of the Circle
	 */
	void setPosition(const Point2D& newPoint) override;
	/**
	 * Sets the Circle's radius \n
	 * If you need to use setCenter(), call setRadius() before hand
	 * @param radius int new radius for the Circle
	 */
	void setRadius(const int& radius);
private:
	/**
	 * The SFML circle object
	 */
	sf::CircleShape circle;
};