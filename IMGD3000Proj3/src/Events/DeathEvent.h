/*
 * DeathEvent.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Benny
 */

#ifndef DEATHEVENT_H_
#define DEATHEVENT_H_

#define DF_DEATH_EVENT "__death__"

#include "Event.h"
#include "Creature.h"

/**
 * Event called whenever a creature is killed
 */
class DeathEvent : public Event
{
public:
	/**
	 * Creates a new death event
	 * @param killed The creature that was killed
	 */
	DeathEvent(Creature* killed);

	/**
	 * Gets the creature that was killed
	 * @return The creature that was killed
	 */
	Creature* getKilled() const;

private:
	Creature* killed;
};

#endif /* DEATHEVENT_H_ */
