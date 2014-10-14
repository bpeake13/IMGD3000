/*
 * AdventurerAttackPhase.h
 *
 *  Created on: Oct 13, 2014
 *      Author: Benny
 */

#ifndef ADVENTURERATTACKPHASE_H_
#define ADVENTURERATTACKPHASE_H_

#include "BattlePhase.h"
#include "Adventurer.h"
#include "Monster.h"

/**
 * Phase of battle where the player attacks an enemy
 */
class AdventurerAttackPhase : public BattlePhase
{
public:
	/**
	 * Creates a new player attack phase
	 * @param selectedAdv The player that is attacking
	 * @param selectedMonster The monster that is being attacked
	 * @param battle The battle this phase is apart of
	 */
	AdventurerAttackPhase(Adventurer* selectedAdv, Monster* selectedMonster, Battle* battle);

	/**
	 * Handles incoming events
	 * @param e The incoming event
	 * @return 1 if the event was eaten, otherwise 0
	 */
	int eventHandler(Event* e);

	/**
	 * Gets the next phase in the battle
	 * @return The next phase in the battle, or NULL to stay on the current phase
	 */
	BattlePhase* getNext();

	/**
	 * Gets the message that this phase displays
	 * @return The message to display when this phase is active
	 */
	string getMessage();

private:
	int damage;//the damage done

	Adventurer* selectedAdv;
	Monster* selectedMonster;

	bool buttonPressed;
};

#endif /* ADVENTURERATTACKPHASE_H_ */
