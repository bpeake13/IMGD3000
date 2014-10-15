/*
 * BattleEvent.h
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#ifndef BATTLEEVENT_H_
#define BATTLEEVENT_H_

#include "DungeonEvent.h"

#define PROBABILITY .8

class BattleEvent: public DungeonEvent {
public:
	BattleEvent();
	void start();
};

#endif /* BATTLEEVENT_H_ */