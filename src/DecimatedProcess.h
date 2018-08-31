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
	 * Ticks every loops
	 */
	void tick();
	/**
	 * Boolean, whether or not it should call the process before or after the ProcessController process() method
	 */
	bool tickBeforeLoop;
private:
	/**
	 * djngkjsd
	 */
	virtual void process() = 0;
	/**
	 * kmldksgsd
	 */
	unsigned int counter;
	/**
	 * dsgds
	 */
	unsigned int counterGoal;
};