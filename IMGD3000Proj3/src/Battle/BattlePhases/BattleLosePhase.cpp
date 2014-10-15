/*
 * BattleLosePhase.cpp
 *
 *  Created on: Oct 14, 2014
 *      Author: Benny
 */

#include "BattleLosePhase.h"
#include "EventKeyboard.h"

#include <ostream>

BattleLosePhase::BattleLosePhase(Battle* battle, Adventurer* dead) : BattlePhase(battle)
{
	this->dead = dead;

	buttonPressed = false;
}

int BattleLosePhase::eventHander(Event* e)
{
	string typeName = e->getType();

	if(typeName == DF_EVENT_KEYBOARD)
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

BattlePhase* BattleLosePhase::getNext()
{
	return NULL;
}

string BattleLosePhase::getMessage()
{
	std::ostringstream ss;

	ss << dead->getName() << " has died.";
}

bool BattleLosePhase::endBattle(string* reason, string* info)
{
	if(buttonPressed)
	{
		*reason = "Died";
		*info = dead->getName();
	}

	return buttonPressed;
}
