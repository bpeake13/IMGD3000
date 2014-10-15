/*
 * MonsterAttackPhase.cpp
 *
 *  Created on: Oct 14, 2014
 *      Author: Benny
 */

#include "MonsterAttackPhase.h"
#include "AdventurerSelectPhase.h"
#include "PartyManager.h"
#include "EventKeyboard.h"

#include <ostream>

#include "MathExt.h"

MonsterAttackPhase::MonsterAttackPhase(Battle* battle) : BattlePhase(battle)
{
	buttonPressed = false;

	size_t maxMonsters = battle->getMonsterCount();
	monster = battle->getMonster(Math::randomRange(0, maxMonsters));

	PartyManager& party = PartyManager::getInstance();

	float highestAttackRatio = 0;
	Adventurer* bestBet = NULL;

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
	string eventType = event->getType();

	if(eventType == DF_EVENT_KEYBOARD)
	{
		EventKeyboard* ek = static_cast<EventKeyboard*>(event);
		if(ek->getKey() == ' ')
		{
			buttonPressed = true;
			return 1;
		}

		return 0;
	}

	return 0;
}

BattlePhase* MonsterAttackPhase::getNext()
{
	if(!buttonPressed)
		return NULL;



	return new AdventurerSelectPhase(getBattle());
}

string MonsterAttackPhase::getMessage()
{
	std::ostringstream ss;

	if(adventurer->isDead())
		ss << monster->getName() << " killed " << adventurer->getName();
	else
		ss << monster->getName() << " did " << damage << " points of damage to " << adventurer->getName();

	return ss.str();
}
