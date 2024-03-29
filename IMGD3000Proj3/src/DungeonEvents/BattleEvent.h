/*
 * BattleEvent.h
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#ifndef BATTLEEVENT_H_
#define BATTLEEVENT_H_

#include "DungeonEvent.h"
#include "Event.h"

#define BATTLEPROBABILITY .8

class BattleEvent: public DungeonEvent {
public:
	BattleEvent();
	void start();

	int eventHandler(Event* e);

private:
	int rewardval;
};

#endif /* BATTLEEVENT_H_ */
