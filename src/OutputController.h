#pragma once

#include <string>
#include "Window.h"
#include "InputController.h"
#include "Storage.h"
#include "Frame.h"

class OutputController
{
public:
	/**
	 * Constructor for OutputController
	 */
	OutputController();
	/**
	 * Destructor for OutputController
	 */
	~OutputController();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Used while exiting the application from the MasterController
	 */
	void closeGraphicsWindow();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Creates a graphics Window, and gives the InputController a pointer to the Window for input events
	 * @param inputController InputController pointer, so the OutputController can give the InputController a pointer to the Window
	 */
	void createGraphicsWindow(InputController* inputController);
	/**
	 * Returns a string indicating this object's current status, and all objects it manages. \n
	 * Should only be used for debugging, but not strictly.
	 * @return status string
	 */
	std::string getStatusString() const;
	/**
	 * <b> IPOC ONLY </b> \n
	 * Called when IPOC is loading \n
	 * Passes a pointer to the Frame object that the OutputController will be drawing
	 * @param inputFrame Frame object that the Window will be drawing, facilitated by the OutputController
	 */
	void IPOCLoad(Frame* inputFrame);
	/**
	 * <b> IPOC ONLY </b> \n
	 * Main output logic (called endlessly while the application runs)
	 */
	void output();
	/**
	 * Call this after the user has changed graphics settings, to reload the window with the new settings \n
	 * This is required because the InputController needs to pause using the input methods while the Window reloads
	 */
	void reloadGraphicsWindow();
private:
	Window window;
	Frame* frame;
	bool reloadWindow = false;
};