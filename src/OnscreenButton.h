#pragma once

#include <string>
#include <vector>
#include "Drawable.h"
#include "Identifiable.h"
#include "Point2D.h"

enum OnscreenButtonType
{
	TriggerOnUp = 0, TriggerOnDown = 1, TriggerOnHold = 2
};

/**
 * OnscreenButton is a Drawable that's clickable (and isTriggered() after being clicked)
 */
class OnscreenButton : public Drawable
{
public:
	/**
	 * Constructor for the button with no params
	 */
	OnscreenButton();
	/**
	 * Constructor for the button with an OnscreenButtonType
	 * @param inputOnscreenButtonType OnscreenButtonType
	 */
	OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType);
	/**
	 * Constructor for the button with OnscreenButtonType and Z index
	 * @param inputOnscreenButtonType OnscreenButtonType
	 * @param inputZ Z index
	 */
	OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType,
				   const unsigned int& inputZ);
	/**
	 * Constructor for the button with OnscreenButtonType, Z index, and the top left Point2D
	 * @param inputOnscreenButtonType OnscreenButtonType
	 * @param inputZ Z index
	 * @param point Point2D Top left location
	 */
	OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType,
				   const unsigned int& inputZ,
				   const Point2D& point);
	/**
	 * Destructor for the OnscreenButton
	 */
	~OnscreenButton();
	/**
	 * Adds a drawable to the down state of the button
	 * @param drawable drawable to add to the down state of the button
	 */
	void addToDown(Drawable* drawable);
	/**
	 * Adds a drawable to down state of the button with a offset
	 * @param drawable drawable to add to the down state of the button
	 * @param offsetFromTopLeft Offset from the top left of button
	 */
	void addToDown(Drawable* drawable,
				   const Point2D& offsetFromTopLeft);
	/**
	 * Adds a drawable to the up state of the button
	 * @param drawable drawable to add to the up state of the button
	 */
	void addToUp(Drawable* drawable);
	/**
	 * Adds a drawable to up state of the button with a offset
	 * @param drawable drawable to add to the up state of the button
	 * @param offsetFromTopLeft Offset from the top left of button
	 */
	void addToUp(Drawable* drawable,
				 const Point2D& offsetFromTopLeft);
	/**
	 * <b> IPOC ONLY </b> \n
	 * Clears the buttons triggered state at the end of the loop
	 */
	void clearTriggered();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Draws to render target
	 * @param target
	 */
	void draw(sf::RenderTarget& target) const override;
	/**
	 * Returns a string indicating this object's current status, and all objects it manages. \n
	 * Should only be used for debugging, but not strictly.
	 * @return status string
	 */
	std::string getStatusString() const;
	/**
	 * Returns whether or not the button is triggered
	 * @return true or false depending on the button type (set via setButtonTriggerType()) and if it's been clicked
	 */
	bool isTriggered() const;
	/**
	 * <b> IPOC ONLY </b> \n
	 * Used for calculating if the button is triggered
	 * @param mousePoint mouse point Point2D
	 * @return true if the button needs to be un triggered after this loop
	 */
	bool mouseDown(const Point2D& mousePoint);
	/**
	 * <b> IPOC ONLY </b> \n
	 * Used for calculating if the button is triggered
	 * @param mousePoint mouse point Point2D
	 */
	void mouseHold(const Point2D& mousePoint);
	/**
	 * <b> IPOC ONLY </b> \n
	 * Used for calculating if the button is triggered
	 * @param mousePoint mouse point Point2D
	 * @return true if the button needs to be un triggered after this loop
	 */
	bool mouseUp(const Point2D& mousePoint);
	/**
	 * Sets the button's trigger type (OnscreenButtonType)
	 * @param inputOnscreenButtonType OnscreenButtonType to indicate how the button is triggered
	 */
	void setButtonTriggerType(const OnscreenButtonType& inputOnscreenButtonType);
	/**
	 * Sets the hit box for the OnscreenButton
	 * @param inputTopLeft top left of the hit box
	 * @param inputBottomRight bottom right of the hit box
	 */
	void setHitBox(const Point2D& inputTopLeft,
				   const Point2D& inputBottomRight);
	/**
	 * Sets the top left position of the OnscreenButton
	 * @param newPoint new top left position of the OnscreenButton
	 */
	void setPosition(const Point2D& newPoint) override;
private:
	bool triggered = false;
	bool stateUp = true;
	OnscreenButtonType onscreenButtonType;
	std::vector<Drawable*> stateUpDrawables;
	std::vector<Drawable*> stateDownDrawables;
	std::vector<Point2D> stateUpOffset;
	std::vector<Point2D> stateDownOffset;
	Point2D hitBoxTopLeft;
	Point2D hitBoxBottomRight;
	Point2D drawingPosition;
	bool isInside(const Point2D& point) const;
};