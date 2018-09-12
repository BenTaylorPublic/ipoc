#pragma once

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "Identifiable.h"

/**
 * Drawable interface needs to be inherited from for a class to be passed to the Frame
 */
class Drawable : public Identifiable
{
public:
	/**
	 * Drawable constructor
	 */
	Drawable();
	/**
	 * virtual Drawable destructor
	 */
	virtual ~Drawable();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Draws the Drawable onto the target (a SFML Window)
	 * @param target SFML Window to draw the drawable onto
	 */
	virtual void draw(sf::RenderTarget& target) const = 0;
	/**
	 * Gets the View Index of the drawable \n
	 * Make sure to set this before adding the Drawable to the Frame
	 * @return
	 */
	unsigned int getViewIndex() const;
	/**
	 * Gets the Z index of the drawable
	 * @return the Z index of the drawable
	 */
	unsigned int getZIndex() const;
	/**
	 * Sets the x y position of the Drawable \n
	 * TODO: This is going to be removed and added to another class that inherits from Drawable. So don't use this.
	 * @param newPoint new Point2D top left location of the drawable
	 */
	virtual void setPosition(const Point2D& newPoint) = 0;
	/**
	 * Sets the View Index of the drawable \n
	 * Make sure to set this before adding the Drawable to the Frame
	 */
	void setViewIndex(const unsigned int& inputViewIndex);
	/**
	 * Sets the Z index of the drawable
	 * @param inputZIndex the new Z index for the drawable
	 */
	void setZIndex(const unsigned int& inputZIndex);
private:
	/**
	 *	The Z Index of the drawable
	 */
	unsigned int zIndex = 0;
	/**
	 * The View index of the drawable
	 */
	unsigned int viewIndex = 0;
};