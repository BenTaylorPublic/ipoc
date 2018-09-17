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
	void addToDown(Drawable* drawable);
	void addToDown(Drawable* drawable,
				   const Point2D& offsetFromTopLeft);
	void addToUp(Drawable* drawable);
	void addToUp(Drawable* drawable,
				 const Point2D& offsetFromTopLeft);
	void clearTriggered();
	void draw(sf::RenderTarget& target) const override;
	std::string getStatusString() const;
	bool isTriggered() const;
	bool mouseDown(const Point2D& mousePoint);
	void mouseHold(const Point2D& mousePoint);
	bool mouseUp(const Point2D& mousePoint);
	void setButtonTriggerType(const OnscreenButtonType& inputOnscreenButtonType);
	void setHitBox(const Point2D& inputTopLeft,
				   const Point2D& inputBottomRight);
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