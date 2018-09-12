#pragma once

#include <string>
#include <vector>
#include "Drawable.h"
#include "View.h"
#include <SFML/Graphics.hpp>

/**
 * Frame is a controller you add Drawable's to \n
 * There is only one Frame (it isn't made every loop)
 */
class Frame
{
public:
	/**
	 * Constructor for the Frame
	 */
	Frame();
	/**
	 * Destructor for the Frame
	 */
	~Frame();
	/**
	 * Adds a Drawable to the frame \n
	 * The Drawable will be drawn at the end of the current game loop, and forever, until it's removeFromFrame()'d \n
	 * Make sure you set the Drawable's View index before adding it to the Frame
	 * @param drawable
	 */
	void addToFrame(Drawable* drawable);
	/**
	 * <b> IPOC ONLY </b> \n
	 * Used by IPOC to draw all the Drawable's currently held in the frame, onto the next game frame
	 * @param target SFML window to draw all Drawable's on
	 */
	void drawAll(sf::RenderTarget& target);
	/**
	 * Returns a string indicating this object's current status, and all objects it manages. \n
	 * Should only be used for debugging, but not strictly.
	 * @return status string
	 */
	std::string getStatusString() const;
	/**
	 * <b> IPOC ONLY </b> \n
	 * Called when IPOC is loading
	 */
	void IPOCLoad();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Constantly checked by the OutputController on the output thread, as it waits for frames to draw
	 * @return
	 */
	bool isDrawable() const;
	/**
	 * <b> IPOC ONLY </b> \n
	 * Marks the frame as drawable, so that isDrawable() returns true, so the OutputController can draw it
	 */
	void markAsDrawable();
	/**
	 * Removes a drawable from the frame \n
	 * The Drawable will not be draw in the frame at the end of the current game loop
	 * @param drawable
	 */
	void removeFromFrame(Drawable* drawable);
	/**
	 * Sets the view port of a specified view
	 * TODO: Clarify this more
	 * @param viewIndex index of the view
	 * @param topLeftX Not sure atm
	 * @param topLeftY Not sure atm
	 * @param sizeX Not sure atm
	 * @param sizeY Not sure atm
	 */
	void setViewPort(const unsigned int& viewIndex,
					 const float& topLeftX,
					 const float& topLeftY,
					 const float& sizeX,
					 const float& sizeY);
private:
	/**
	 * Vector of views to contain the drawables
	 */
	std::vector<View*> views;
	/**
	 * Used by isDrawable() and markAsDrawable()
	 */
	bool isDrawableBool;
};