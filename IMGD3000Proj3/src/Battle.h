/*
 * Battle.h
 *
 *  Created on: Oct 7, 2014
 *      Author: Eric
 */

#ifndef BATTLE_H_
#define BATTLE_H_

#include "Monster.h"
#include "Scene.h"
#include "Event.h"
#include "DynamicPtrArray.h"
#include "TextObject.h"
#include <string>

#define BATTLE_PHASE_PLAYER 0
#define BATTLE_PHASE_MONSTER 1

#define BATTLE_PHASE_STATE_INPUT 0
#define BATTLE_PHASE_STATE_ATTACK 1

#define ATTACK_MODE_PHYSICAL 0
#define ATTACK_MODE_MAGIC 1

/**
 * Is a battle scene and is in charge of managing the battle
 */
class Battle: public Scene {
public:
	/**
	 * Creates a new battle scene
	 */
	Battle();

	/**
	 * Called when the battle is destroyed
	 */
	virtual ~Battle();

	/**
	 * Adds a monster to the battle
	 * @param monster The monster to battle
	 */
	void addMonster(Monster* monster);

	/**
	 * Gets a monster at the ith index
	 * @param i The index of the monster to get
	 * @return The ith monster, or NULL if that monster does not exist
	 */
	Monster* getMonster(int i);

	/**
	 * Gets the number of monsters in the battle
	 * @return The number of monsters in the battle
	 */
	size_t getMonsterCount();

	/**
	 * Handles events for the battle
	 * @param e The event
	 * @return 1 if the event was eaten, 0 otherwise
	 */
	int eventHandler(Event* e);

protected:
	/**
	 * Called to check to see if the battle is over, if the battle is over then it will call endBattle
	 */
	virtual void checkBattleOver();

	/**
	 * Finishes the battle and pops this scene from the stack
	 */
	virtual void endBattle(string reason);
private:

	int battlePhase;//the current phase of the battle
	int battlePhaseState;//the state of the phase of the battle

	int attackMode;//the mode that the player will attack in

	int attackTimer;

	int attackerIndex;

	TextObject* message;
	TextObject* attackModeLabel;

	DynamicPtrArray* enemyList;
};

#endif /* BATTLE_H_ */
