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
#include "BattleOverEvent.h"
#include "MathExt.h"

BattleEvent::BattleEvent() : DungeonEvent(0.4){
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

int BattleEvent::eventHandler(Event* e)
{
	DungeonEvent::eventHandler(e);

	string eventType = e->getType();

	if(eventType == DF_BATTLE_OVER_EVENT)
	{
		BattleOverEvent* boe = static_cast<BattleOverEvent*>(e);

		if(boe->getReason() == "Win")
		{
			PartyManager::getInstance().addTreasure(Math::randomRange(5, 15));
			return 1;
		}
	}

	return 0;
}
