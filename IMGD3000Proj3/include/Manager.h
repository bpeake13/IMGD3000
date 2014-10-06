/*
 * Manager.h
 *
 *  Created on: Sep 14, 2014
 *      Author: Benny
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Event.h"

/**
 * Base class for all managers in the engine
 */
class Manager {
public:
	Manager();
	virtual ~Manager();

	/**
	 * Called to start the manager
	 * @return 0 if ok, a number < 0 if an error occurred
	 */
	virtual int startUp();

	/**
	 * Shuts down the manager
	 */
	virtual void shutDown();

	/**
	 * Indicates whether the manager has been started or not
	 * @return True if this manager has been started, false otherwise
	 */
	bool hasStarted() const;

	/**
	 * Used to pass events to a manager
	 * @param e The event to pass
	 * @return 1 if the event was able to be passed, 0 otherwise
	 */
	virtual int onEvent(Event* e) const;

private:
	bool isStarted;
};

#endif /* MANAGER_H_ */
