/*
 * BattleEvent.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#include "BattleEvent.h"
#include "Battle.h"
#include "SceneManager.h"

BattleEvent::BattleEvent() : DungeonEvent(PROBABILITY){
}

void BattleEvent::start() {
	setViewString("A monster has appeared!");
	Battle *nb = new Battle();
	Monster *nm = new Monster("default", 1,1,1, "fix this");
	SceneManager::getInstance().push(nb);
}
