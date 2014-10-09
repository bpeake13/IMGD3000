/*
 * Battle.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: Eric
 */

#include "Battle.h"
#include "DeathEvent.h"
#include "EventStep.h"
#include "SceneManager.h"
#include "SceneOverEvent.h"
#include "WorldManager.h"
#include <string>

Battle::Battle()
{
	enemyList = new DynamicPtrArray();

	message = new TextObject;
	message->setViewString("");
	message->setViewObjectLocation(CENTER_CENTER);

	this->battlePhase = BATTLE_PHASE_PLAYER;
	this->battlePhaseState = BATTLE_PHASE_STATE_INPUT;
}

Battle::~Battle()
{
	enemyList->clear();

	delete enemyList;
}

void Battle::addMonster(Monster* monster)
{
	enemyList->add(monster);
	addObject(monster);
}

Monster* Battle::getMonster(int i)
{
	void* v = enemyList->get(i);
	if(v)
		return static_cast<Monster*>(v);

	return NULL;
}

size_t Battle::getMonsterCount()
{
	return enemyList->getSize();
}

int Battle::eventHandler(Event* e)
{
	string eventName = e->getType();

	if(eventName == DF_DEATH_EVENT)
	{
		DeathEvent* de = static_cast<DeathEvent*>(e);
		Monster* m = dynamic_cast<Monster*>(de->getKilled());
		if(!m)
			return 0;

		enemyList->remove(m);

		checkBattleOver();

		return 1;
	}
	else if(eventName == DF_EVENT_STEP)
	{
		if(this->battlePhase == BATTLE_PHASE_PLAYER)
		{
			if(this->battlePhaseState == BATTLE_PHASE_STATE_INPUT)
			{

			}
		}
	}

	return 0;
}

void Battle::checkBattleOver()
{
	if(enemyList->getSize() == 0)
		endBattle("BattleWon");
}

void Battle::endBattle(string reason)
{
	SceneManager& sm = SceneManager::getInstance();
	sm.pop();

	SceneOverEvent e = SceneOverEvent(reason, "");
	WorldManager& world = WorldManager::getInstance();
	world.onEvent(&e);
	world.markForDelete(this);
}
