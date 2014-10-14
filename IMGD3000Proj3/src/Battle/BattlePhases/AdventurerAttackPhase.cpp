/*
 * AdventurerAttackPhase.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Benny
 */

#include "AdventurerAttackPhase.h"
#include "EventKeyboard.h"

#include <stdlib.h>
#include <ostream>

AdventurerAttackPhase::AdventurerAttackPhase(Adventurer* selectedAdv,
		Monster* selectedMonster, Battle* battle) : BattlePhase(battle)
{
	damage = selectedAdv->doAttack();
	selectedMonster->damage(damage);

	this->selectedAdv = selectedAdv;
	this->selectedMonster = selectedMonster;

	buttonPressed = false;
}

int AdventurerAttackPhase::eventHandler(Event* e)
{
	string eventType = e->getType();

	if(eventType == DF_EVENT_KEYBOARD)
	{
		EventKeyboard* ek = static_cast<EventKeyboard*>(e);
		if(ek->getKey() == ' ')
		{
			buttonPressed = true;
			return 1;
		}
	}

	return 0;
}

BattlePhase* AdventurerAttackPhase::getNext()
{
	if(!buttonPressed)
		return NULL;

	Battle* battle = getBattle();

	if(battle->getMonsterCount() <= 0)
	{

	}
	else
	{

	}
}

string AdventurerAttackPhase::getMessage()
{
	std::ostringstream stringStream;

	stringStream << selectedAdv->getName() << " did " << damage << " points of damage to " << selectedMonster->getName();

	return stringStream.str();
}
