/*
 * DeathEvent.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Benny
 */

#include "DeathEvent.h"

DeathEvent::DeathEvent(Creature* killed)
{
	this->killed = killed;
	setType(DF_DEATH_EVENT);
}

Creature* DeathEvent::getKilled() const
{
	return killed;
}
