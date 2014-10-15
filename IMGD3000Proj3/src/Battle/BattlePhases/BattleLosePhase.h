/*
 * BattleLosePhase.h
 *
 *  Created on: Oct 14, 2014
 *      Author: Benny
 */

#ifndef BATTLELOSEPHASE_H_
#define BATTLELOSEPHASE_H_

#include "BattlePhase.h"
#include "Adventurer.h"

/**
 * Battle phase when player loses
 */
class BattleLosePhase : public BattlePhase
{
public:
	/**
	 * Creates a new battle lose phase
	 * @param battle The battle that this phase is a part of
	 * @param dead The adventurer that died
	 */
	BattleLosePhase(Battle* battle, Adventurer* dead);

	/**
	 * Handles events for this object
	 * @param e The event to handle
	 * @return 1 if the event is eaten, 0 if not
	 */
	int eventHander(Event* e);

	/**
	 * Gets the next phase
	 * @return The next phase, or NULL to stay on the current phase
	 */
	BattlePhase* getNext();

	/**
	 * The message to show to the screen
	 * @return The message to show to the screen
	 */
	string getMessage();

	/**
	 * When true the battle will be ended
	 * @param reason The reason the battle was ended
	 * @param info Info on the battle ending
	 * @return True if the battle should be ended, otherwise flase
	 */
	bool endBattle(string* reason, string* info);

private:
	bool buttonPressed;

	Adventurer* dead;
};

#endif /* BATTLELOSEPHASE_H_ */
