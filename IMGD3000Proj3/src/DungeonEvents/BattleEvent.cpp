/*
 * BattleEvent.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#include "Monster.h"
#include "BattleEvent.h"
#include "Battle.h"
#include "MonsterManager.h"
#include "PartyManager.h"
#include "SceneManager.h"

BattleEvent::BattleEvent() : DungeonEvent(BATTLEPROBABILITY){
}

void BattleEvent::start() {
	setViewString("A monster has appeared!");
	Battle *nb = new Battle();
	MonsterManager &mm = MonsterManager::getInstance();
	//Monster *mon = mm.getMonster("centaur"); //mm.randomMonster();
	Monster* mon = mm.randomMonster();

	rewardval = mon->getReward();
	nb->addMonster(mon);
	SceneManager::getInstance().push(nb);
}

int BattleEvent::eventHandler(Event* e){
	/*string typeName = e->getType();
	if(typeName == DF_EVENT_KEYBOARD){
		PartyManager::getInstance().addTreasure(rewardval);
	}

	return 0;*/
}
