/*
 * TargetSelectPhase.h
 *
 *  Created on: Oct 13, 2014
 *      Author: Benny
 */

#ifndef TARGETSELECTPHASE_H_
#define TARGETSELECTPHASE_H_

#include "BattlePhase.h"
#include "Adventurer.h"

/**
 * Phase of battle where the player selects what enemy to attack
 */
class TargetSelectPhase : public BattlePhase
{
public:
	/**
	 * Creates a new target select phase
	 * @param selectedAdv The adventurer who is selecting a target
	 */
	TargetSelectPhase(Adventurer* selectedAdv, Battle* battle);

	/**
	 * Called each time there is an event
	 * @param e The event that was triggered
	 * @return 1 if the event was eaten, 0 if not
	 */
	int eventHandler(Event* e);

	/**
	 * Gets the next phase in the battle
	 * @return The next phase in the battle, or NULL to keep it on this phase
	 */
	BattlePhase* getNext();

	/**
	 * Gets the message to display to the screen
	 * @return
	 */
	string getMessage();

private:
	Adventurer* selectedAdv;
	Monster* selectedMonster;
};

#endif /* TARGETSELECTPHASE_H_ */
