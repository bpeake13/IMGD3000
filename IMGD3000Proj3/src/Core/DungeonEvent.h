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
	 * @param probability The probability that this event will be used on a step if it is selected
	 */
	DungeonEvent(float probability);

	/**
	 * Gets the probability that this event will fire if chosen
	 * @return A 0-1 range float that represents the probability
	 */
	float getProbability() const;

	/**
	 * Called to start the event
	 */
	virtual void start();

	/**
	 * Called to finish the event
	 */
	virtual void finish();

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
	bool isActive;

	float probability;
};

#endif /* DUNGEONEVENT_H_ */
