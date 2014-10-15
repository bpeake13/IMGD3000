/*
 * BattleEvent.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#include "BattleEvent.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "Battle.h"
#include "SceneManager.h"

BattleEvent::BattleEvent() : DungeonEvent(PROBABILITY){
}

void BattleEvent::start() {
	setViewString("A monster has appeared!");
	Battle *nb = new Battle();
	MonsterManager &mm = MonsterManager::getInstance();
	Monster *mon = mm.getMonster("centaur");

	nb->addMonster(mon);
	SceneManager::getInstance().push(nb);
}
