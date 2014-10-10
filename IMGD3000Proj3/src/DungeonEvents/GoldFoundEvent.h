/*
 * GoldFoundEvent.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Eric
 */

#ifndef GOLDFOUNDEVENT_H_
#define GOLDFOUNDEVENT_H_

#include "DungeonEvent.h"

#define PROBABILITY .25

class GoldFoundEvent: public DungeonEvent {
private:
	int treasure;

public:
	GoldFoundEvent();
	void start();
};

#endif /* GOLDFOUNDEVENT_H_ */
