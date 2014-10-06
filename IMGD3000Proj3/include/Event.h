/*
 * Event.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#ifndef EVENT_H_
#define EVENT_H_

#define DEFAULT_EVENT_NAME "EVENT"

#include "Utility.h"

/**
 * The base class for sending events to objects
 */
class Event
{
public:
	/**
	 * Create a new event
	 */
	Event();

	/**
	 * Called when the event is deleted
	 */
	virtual ~Event();

	/**
	 * Change the type of the event
	 * @param new_type The new type that this event should be
	 */
	void setType(string new_type);

	/**
	 * Get the type that this event is
	 * @return The type name of this event
	 */
	string getType() const;

private:
	string eventType;//the type name of this event
};

#endif /* EVENT_H_ */
