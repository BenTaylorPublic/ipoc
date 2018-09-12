#pragma once

#include <string>
#include "Window.h"
#include "InputEnums.h"
#include "Point2D.h"
#include "OnscreenButton.h"
#include <SFML/Graphics.hpp>
#include <queue>

/**
 * InputController is a controller used to receive input from keyboard and mouse \n
 * It also managers onscreen buttons \n
 * It has it's own thread, which is a constant loop of input() called from MasterController
 */
class InputController
{
public:
	/**
	 * InputController constructor
	 */
	InputController();
	/**
	 * InputController destructor
	 */
	~InputController();
	/**
	 * Adds the on screen button, so that it can be triggered
	 * @param onscreenButtonToAdd OnscreenButton to track
	 */
	void addOnscreenButton(OnscreenButton* onscreenButtonToAdd);
	/**
	 * <b> IPOC ONLY </b> \n
	 * The input loop on the input thread \n
	 * Called from MasterController
	 */
	void input();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Called when the program loads
	 */
	void IPOCLoad();
	/**
	 * Gets the current Point2D mouse point, relative to the window
	 * @return current Point2D mouse point, relative to the window
	 */
	const Point2D& getMousePoint() const;
	/**
	 * Gets the ButtonStatus of a specified PhysicalButton \n
	 * <b>Return logic</b>: \n
	 * All of this logic is based off a key being touched during the last loop. \n
	 * <b>ButtonStatus ButtonDown:</b> \n
	 * returns true if the button went down \n
	 * <b>ButtonStatus ButtonHold:</b> \n
	 * returns true if the button went down or if the button has not been released yet \n
	 * <b>ButtonStatus ButtonUp:</b> \n
	 * returns true if the button went up (from the hold state) \n
	 * <b>ButtonStatus ButtonUntouched:</b> \n
	 * returns true if the button wasn't down and still isn't down \n
	 * @param inputPhysicalButton PhysicalButton to check against the ButtonStatus
	 * @param inputStatus ButtonStatus to check against the PhysicalButton
	 * @return See the above description
	 */
	bool getPhysicalButtonStatus(const PhysicalButton& inputPhysicalButton,
								 const ButtonStatus& inputStatus) const;
	/**
	 * Returns a string indicating this object's current status, and all objects it manages. \n
	 * Should only be used for debugging, but not strictly.
	 * @return status string
	 */
	std::string getStatusString() const;
	/**
	 * <b> IPOC ONLY </b> \n
	 * Used to mark ButtonDown to ButtonHold, and ButtonUp to ButtonUntouched
	 */
	void markEndOfLoop();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Used to mark ButtonDown to ButtonHold, and ButtonUp to ButtonUntouched
	 */
	void markStartOfLoop();
	/**
	 * Removes the OnscreenButton from the InputController \n
	 * The OnscreenButton cannot be triggered until it is then re-added via addOnscreenButton()
	 * @param onscreenButtonToRemove OnscreenButton to remove
	 */
	void removeOnscreenButton(OnscreenButton* onscreenButtonToRemove);
	/**
	 * <b> IPOC ONLY </b> \n
	 * Passes the Window to the InputController so it can be used for mouse positions and such
	 * @param inputWindow
	 */
	void setGraphicsWindow(Window* inputWindow);
private:
	void handleLeftClick(const int& index);
	void handlePhysicalButton(const sf::Keyboard::Key& inputButton,
							  const int& index);
	void handlePhysicalButton(const sf::Mouse::Button& inputButton,
							  const int& index);
	void resetInputArrays();
	Point2D mousePoint;
	ButtonStatus physicalButtonStatusArray[AMOUNT_OF_PHYSICAL_BUTTONS];
	std::queue<int> physicalButtonDown; //Used to mark ButtonDown to ButtonHold
	std::queue<int> physicalButtonUp; //Used to mark ButtonUp to ButtonUntouched

	std::vector<OnscreenButton*> onscreenButtons;
	std::queue<OnscreenButton*> onscreenButtonToClearTrigger;

	Window* window; //Needed for mouse location relative to window
};