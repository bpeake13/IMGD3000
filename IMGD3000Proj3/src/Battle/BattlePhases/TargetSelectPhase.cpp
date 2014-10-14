/*
 * TargetSelectPhase.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Benny
 */

#include "TargetSelectPhase.h"
#include "EventKeyboard.h"


TargetSelectPhase::TargetSelectPhase(Adventurer* selectedAdv, Battle* battle) : BattlePhase(battle)
{
	this->selectedAdv = selectedAdv;
	this->selectedMonster = NULL;
}

int TargetSelectPhase::eventHandler(Event* e)
{
	string eventType = e->getType();

	if(eventType == DF_EVENT_KEYBOARD)
	{
		EventKeyboard* ke = static_cast<EventKeyboard*>(e);

		int monsterIndex = ke->getKey() - '1';
		if(monsterIndex < 0)
			return 0;

		Battle* battle = getBattle();

		if(monsterIndex >= battle->getMonsterCount())
			return 0;

		selectedMonster = battle->getMonster(monsterIndex);

		return 1;
	}

	return 0;
}

BattlePhase* TargetSelectPhase::getNext()
{

}

string TargetSelectPhase::getMessage()
{
	return "Who are they attacking?";
}
