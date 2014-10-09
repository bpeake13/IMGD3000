/*
 * DungeonEvent.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Benny
 */

#ifndef DUNGEONEVENT_H_
#define DUNGEONEVENT_H_

#include "TextObject.h"
#include "Event.h"

/**
 * Represents an event that that can happen at random while walking through the dungeon
 */
class DungeonEvent : public TextObject
{
public:
	/**
	 * Creates a new DungeonEvent
	 */
	DungeonEvent();

	/**
	 * Checks to see if this event has finished
	 * @return True if this event has finished
	 */
	virtual bool isDone() const;

	/**
	 * Handles events for this object
	 * @param e The event
	 * @return 1 if the event was eaten, 0 otherwise
	 */
	virtual int eventHandler(Event* e);

private:

	bool hasPressedKey;
};

#endif /* DUNGEONEVENT_H_ */
