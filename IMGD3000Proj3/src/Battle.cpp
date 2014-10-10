/*
 * Battle.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: Eric
 */

#include "Battle.h"
#include "DeathEvent.h"
#include "EventStep.h"
#include "EventKeyboard.h"
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
	this->attackTimer = 30;

	this->attackerIndex = 0;
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
				message->setViewString("Select an action for ");
			}
			else if(this->battlePhaseState == BATTLE_PHASE_STATE_ATTACK)
			{
				attackTimer -= 1;
				if(attackTimer <= 0)
				{
					this->battlePhaseState = BATTLE_PHASE_STATE_INPUT;

				}
			}
		}
	}
	else if(DF_EVENT_KEYBOARD && battlePhase == BATTLE_PHASE_PLAYER && battlePhaseState == BATTLE_PHASE_STATE_INPUT)
	{
		EventKeyboard* ke = static_cast<EventKeyboard*>(e);
		int key = ke->getKey();

		int monsterIndex = key - '1';
		if(monsterIndex < 0 || monsterIndex > getMonsterCount())
			return 0;

		Monster* target = getMonster(monsterIndex);

		AttackEvent ae = AttackEvent(NULL, target, 5, "physical");

		battlePhaseState = BATTLE_PHASE_STATE_ATTACK;


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
