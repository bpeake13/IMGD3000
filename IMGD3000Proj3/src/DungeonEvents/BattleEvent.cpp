/*
 * BattleEvent.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#include "BattleEvent.h"
#include "BattleOverEvent.h"
#include "PartyManager.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "Battle.h"
#include "SceneManager.h"
#include "MathExt.h"

BattleEvent::BattleEvent() : DungeonEvent(BATTLEPROBABILITY){
}

void BattleEvent::start() {
	setViewString("A monster has appeared!");
	Battle *nb = new Battle();
	MonsterManager &mm = MonsterManager::getInstance();
	Monster *mon = mm.getMonster("centaur");

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
