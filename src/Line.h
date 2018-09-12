#pragma once

#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Point2D.h"
#include "Color.h"

/**
 * Line is a data type and a Drawable
 */
class Line : public Drawable
{
public:
	/**
	 * Constructor for the Line
	 */
	Line();
	/**
	 * Destructor for the Line
	 */
	~Line();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Draws the Line onto the target
	 * @param target RenderTarget (SFML)
	 */
	void draw(sf::RenderTarget& target) const override;
	/**
	 * Sets the Color of the Line
	 */
	void setColor(const Color& color);
	/**
	 * Sets the first position of the line
	 * @param newPoint new Point2D position of the first point in the line
	 */
	void setPosition(const Point2D& newPoint) override;
	/**
	 * Sets the second position of the line
	 * @param newPoint new Point2D position of the second point in the line
	 */
	void setPosition2(const Point2D& newPoint);
private:
	sf::Vertex line[2];
};