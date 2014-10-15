/*
 * BattlePhase.cpp
 *
 *  Created on: Oct 12, 2014
 *      Author: Benny
 */

#include "BattlePhase.h"
#include "Battle.h"

#include <stdlib.h>

BattlePhase::BattlePhase(Battle* battle)
{
	this->battle = battle;
}

BattlePhase::~BattlePhase()
{
	battle = NULL;
}

int BattlePhase::eventHandler(Event* e)
{
	return 0;
}

BattlePhase* BattlePhase::getNext()
{
	return NULL;
}

bool BattlePhase::endBattle(string* reason, string* info)
{
	return false;
}

string BattlePhase::getMessage()
{
	return "";
}

Battle* BattlePhase::getBattle() const
{
	return battle;
}
