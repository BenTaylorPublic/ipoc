#pragma once

#include "Identifiable.h"

/**
 * DecimatedProcess is an interface to inherit from \n
 * It's used to run a process method, every X loops (X is otherwise known as counterGoal)
 */
class DecimatedProcess : public Identifiable
{
public:
	/**
	 * Constructor for the DecimatedProcess interface
	 */
	DecimatedProcess();
	/**
	 * Destructor for the DecimatedProcess interface
	 */
	virtual ~DecimatedProcess();
	/**
	 * Sets the counter goal to reach. When it reaches that goal, it'll call process()
	 * @param x Calls the process method every X game loops
	 */
	void setProcessEveryXLoops(const unsigned int& x);
	/**
	 * <b> IPOC ONLY </b> \n
	 * Ticks every loops, counter +1
	 */
	void tick();
	/**
	 * Boolean, whether or not it should call the process before or after the ProcessController process() method
	 */
	bool tickBeforeLoop;
private:
	/**
	 * Method to override for a decimated process implementation
	 */
	virtual void process() = 0;
	/**
	 * The counter that counts up to the counterGoal, +1 per tick()
	 */
	unsigned int counter;
	/**
	 * The goal for the counter to reach, as it receives +1 from tick(), at which it will trigger process()
	 */
	unsigned int counterGoal;
};