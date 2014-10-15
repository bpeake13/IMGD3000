/*
 * BattleOverEvent.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: Benny
 */

#include "BattleOverEvent.h"

BattleOverEvent::BattleOverEvent(string reason, string info)
{
	this->reason = reason;
	this->info = info;

	setType(DF_BATTLE_OVER_EVENT);
}

string BattleOverEvent::getReason() const
{
	return reason;
}

string BattleOverEvent::getInfo() const
{
	return info;
}

