/*
 * MonsterAttackPhase.cpp
 *
 *  Created on: Oct 14, 2014
 *      Author: Benny
 */

#include "MonsterAttackPhase.h"
#include "PartyManager.h"

#include <ostream>

#include "MathExt.h"

MonsterAttackPhase::MonsterAttackPhase(Battle* battle) : BattlePhase(battle)
{
	buttonPressed = false;

	size_t maxMonsters = battle->getMonsterCount();
	monster = battle->getMonster(Math::randomRange(0, maxMonsters));

	PartyManager& party = PartyManager::getInstance();

	float highestAttackRatio = 0;
	Adventurer bestBet = NULL;

	size_t partySize = party.getPartySize();
	for(size_t i = 0; i < party.getPartySize(); i++)
	{
		Adventurer* a = party.getPartyMember(i);
		float ratio = (float)a->getAttack() / 100.f / (1.f - ((float)a->getHealth() / (float)a->getMaxHealth()));//get the ratio that determines how much we want to attack this party memeber. Attack high strength characters first

		if(ratio > highestAttackRatio)
		{
			highestAttackRatio = ratio;
			bestBet = a;
		}
	}

	adventurer = bestBet;

	damage = monster->doAttack();

	adventurer->damage(damage);
}

int MonsterAttackPhase::eventHandler(Event* event)
{
}

BattlePhase* MonsterAttackPhase::getNext()
{
}

string MonsterAttackPhase::getMessage()
{
	std::ostringstream ss;

	ss << adventurer->getName() << " was attacked by "
}
