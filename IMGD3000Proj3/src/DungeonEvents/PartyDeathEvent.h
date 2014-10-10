/*
 * PartyDeathEvent.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Eric
 */

#ifndef PARTYDEATHEVENT_H_
#define PARTYDEATHEVENT_H_

#include "DungeonEvent.h"

#define PROBABILITY .10

class PartyDeathEvent: public DungeonEvent {
public:
	PartyDeathEvent();
	void start();
};

#endif /* PARTYDEATHEVENT_H_ */
