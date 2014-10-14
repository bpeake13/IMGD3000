/*
 * AdventurerSelectPhase.h
 *
 *  Created on: Oct 13, 2014
 *      Author: Benny
 */

#ifndef ADVENTURERSELECTPHASE_H_
#define ADVENTURERSELECTPHASE_H_

#include "BattlePhase.h"
#include "Adventurer.h"

/**
 * Phase to select an adventurer to attack with
 */
class AdventurerSelectPhase : public BattlePhase
{
public:
	AdventurerSelectPhase(Battle* battle);

	int eventHandler(Event* e);

	BattlePhase* getNext();

	string getMessage();

private:
	Adventurer* selectedAdv;
};

#endif /* ADVENTURERSELECTPHASE_H_ */
