/*
 * BattlePhase.cpp
 *
 *  Created on: Oct 12, 2014
 *      Author: Benny
 */

#include "BattlePhase.h"

#include <stdlib.h>

BattlePhase::BattlePhase()
{

}

BattlePhase::~BattlePhase()
{
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
