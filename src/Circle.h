#pragma once

#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Point2D.h"
#include "Color.h"

/**
 * Circle drawable class
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
	 * <b> IPOC ONLY </b>\n
	 * Draws the Circle to the render target\n
	 * @param target render target to draw to
	 */
	void draw(sf::RenderTarget& target) const override;
	/**
	 * Sets the top left position of the Circle
	 * @param newPoint new Point2D to set as the new top left of the Circle
	 */
	void setPosition(const Point2D& newPoint) override;
	/**
	 * Sets the center position of the Circle.\n
	 * This function is based off the Circle's current radius, so use setRadius() before using setCenter()
	 * @param newPoint new center point for the Circle
	 */
	void setCenter(const Point2D& newPoint);
	/**
	 * Sets the Circle's radius\n
	 * If you need to use setCenter(), call setRadius() before hand
	 * @param radius new radius for the Circle
	 */
	void setRadius(const int& radius);
	/**
	 * Sets the Circle's fill color
	 * @param color Circle's new fill color
	 */
	void setColor(const Color& color);
	/**
	 * The point count define how many points there are around the Circle\n
	 * This affects the Circle's smoothness, but can also impact on performance.\n
	 * I believe the default point count is 30.
	 * @param pointCount the new amount of points for the circle
	 */
	void setPointCount(const int& pointCount);
private:
	/**
	 * The SFML circle object
	 */
	sf::CircleShape circle;
};