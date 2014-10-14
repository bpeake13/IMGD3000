/*
 * MonsterAttackPhase.h
 *
 *  Created on: Oct 14, 2014
 *      Author: Benny
 */

#ifndef MONSTERATTACKPHASE_H_
#define MONSTERATTACKPHASE_H_

#include "BattlePhase.h"
#include "Monster.h"
#include "Adventurer.h"

/**
 * Battle phase for monster turn
 */
class MonsterAttackPhase : public BattlePhase
{
public:
	/**
	 * Creates a new MonsterAttackPhase
	 * @param battle The battle that this phase is a part of
	 */
	MonsterAttackPhase(Battle* battle);

	/**
	 * The event handler for this object
	 * @param event The event that has been triggered
	 * @return 1 if the event is eaten, 0 otherwise
	 */
	int eventHandler(Event* event);

	/**
	 * Gets the next phase of the battle
	 * @return The next phase of the battle or NULL to stay on the current phase
	 */
	BattlePhase* getNext();

	/**
	 * Gets the message to display for this phase
	 * @return The message to display
	 */
	string getMessage();

private:
	bool buttonPressed;

	Monster* monster;
	Adventurer* adventurer;

	int damage;
};

#endif /* MONSTERATTACKPHASE_H_ */
