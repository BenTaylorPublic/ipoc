#pragma once

#include <string>
#include "InputController.h"
#include "OutputController.h"
#include "Storage.h"
#include "Frame.h"
#include "ThreadManager.h"
#include "DecimatedProcessHandler.h"

/**
 * ProcessController is responsible for all program logic
 */
class ProcessController
{
public:
	/**
	 * Constructor for the ProcessController
	 */
	ProcessController();
	/**
	 * Destructor for the ProcessController
	 */
	~ProcessController();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Called from the MasterController to see if the program should end
	 * @return true if the program shouldn't call another process loop (and quit)
	 */
	bool checkForExitProgram() const;
	/**
	 * Returns a string indicating this object's current status, and all objects it manages. \n
	 * Should only be used for debugging, but not strictly.
	 * @return status string
	 */
	std::string getStatusString() const;
	/**
	 * <b> IPOC ONLY </b> \n
	 * Increments the loop number
	 */
	void incrementLoopNumber();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Called when the program is started, and passes all pointers required for the ProcessController
	 * @param inputControllerPtr Pointer to the InputController
	 * @param inputFrame Pointer to the Frame
	 * @param outputControllerPtr Pointer to the OutputController
	 * @param decimatedProcessHandler Pointer to the DecimatedProcessHandler
	 * @param storagePtr Pointer to the Storage
	 */
	void IPOCLoad(InputController* inputControllerPtr,
				  Frame* inputFrame,
				  OutputController* outputControllerPtr,
				  DecimatedProcessHandler* decimatedProcessHandler,
				  Storage* storagePtr);
	/**
	 * Program specific, called just before the start of the loop \n
	 * Load textures and such in here
	 */
	void load();
	/**
	 * The Program specific main loop function
	 */
	void process();
private:
	Frame* frame;
	bool exitProgram;
	unsigned int loopNumber;
	InputController* inputController;
	OutputController* outputController;
	DecimatedProcessHandler* decimatedProcessHandler;
	Storage* storage;
	ThreadManager threadManager;
};