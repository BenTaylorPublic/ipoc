#pragma once

#include <vector>
#include "DecimatedProcess.h"

/**
 * Decimates Process Handler handles all decimated processes currently added to it \n
 * It is responsible for calling tick() on all of it's DecimatedProcess's
 */
class DecimatedProcessHandler
{
public:
	/**
	 * Constructor for the DecimatedProcessHandler
	 */
	DecimatedProcessHandler();
	/**
	 * Destructor for the DecimatedProcessHandler
	 */
	~DecimatedProcessHandler();
	/**
	 * Adds the DecimatedProcess to be handled every loop
	 * @param decimatedProcessesToAdd DecimatedProcess to add
	 */
	void addToHandler(DecimatedProcess* decimatedProcessesToAdd);
	/**
	 * <b> IPOC ONLY </b> \n
	 * Marks the start of the game loop \n
	 * Every DecimatedProcess in decimatedProcessesPreLoop will get tick() called
	 */
	void markEndOfLoop();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Marks the end of the game loop \n
	 * Every DecimatedProcess in decimatedProcessesPostLoop will get tick() called
	 */
	void markStartOfLoop();
	/**
	 * <b> IPOC ONLY </b> \n
	 * Called while the program starts up
	 */
	void IPOCLoad();
	/**
	 * Removes the DecimatedProcess from the handler
	 * @param decimatedProcessesToRemove DecimatedProcess to remove
	 */
	void removeFromHandler(DecimatedProcess* decimatedProcessesToRemove);
private:
	/**
	 * Vector of the DecimatedProcess's to be handled, and that are tick()'d pre game loop via markStartOfLoop()
	 */
	std::vector<DecimatedProcess*> decimatedProcessesPreLoop;
	/**
	 * Vector of the DecimatedProcess's to be handled, and that are tick()'d post game loop via markEndOfLoop()
	 */
	std::vector<DecimatedProcess*> decimatedProcessesPostLoop;
};