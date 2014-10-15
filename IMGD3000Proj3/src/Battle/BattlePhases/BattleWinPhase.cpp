/*
 * BattleWinPhase.cpp
 *
 *  Created on: Oct 14, 2014
 *      Author: Benny
 */

#include "BattleWinPhase.h"
#include "EventKeyboard.h"

BattleWinPhase::BattleWinPhase(Battle* battle) : BattlePhase(battle)
{
	buttonPressed = false;
}

int BattleWinPhase::eventHandler(Event* e)
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

string BattleWinPhase::getMessage()
{
	return "You win!";
}

BattlePhase* BattleWinPhase::getNext()
{
	return NULL;
}

bool BattleWinPhase::endBattle(string* reason, string* info)
{
	if(buttonPressed)
	{
		*reason = "Win";
		*info = "";
		return true;
	}

	return false;
}
