/*
 * AdventurerSelectPhase.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Benny
 */

#include "AdventurerSelectPhase.h"
#include "TargetSelectPhase.h"
#include "PartyManager.h"
#include "EventKeyboard.h"
#include "LogManager.h"

AdventurerSelectPhase::AdventurerSelectPhase(Battle* battle) : BattlePhase(battle)
{
	selectedAdv = NULL;
}

int AdventurerSelectPhase::eventHandler(Event* e)
{
	string eventType = e->getType();

	if(eventType == DF_EVENT_KEYBOARD)//wait for input to see which character to attack with
	{
		EventKeyboard* ek = static_cast<EventKeyboard*>(e);
		int character = ek->getKey() - '1';

		if(character < 0)
			return 0;

		PartyManager& pm = PartyManager::getInstance();

		if(character >= pm.getPartySize())
			return 0;

		selectedAdv = pm.getPartyMember(character);
		return 1;
	}
}

BattlePhase* AdventurerSelectPhase::getNext()
{
	if(selectedAdv)
		return new TargetSelectPhase(selectedAdv, getBattle());

	return NULL;
}

string AdventurerSelectPhase::getMessage()
{
	string l1 = "Who is going to attack?";
	LogManager& l = LogManager::getInstance();
	l.writeLog("TEST %s", l1.c_str());
	return l1;
}
