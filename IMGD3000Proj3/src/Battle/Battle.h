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
#include "BattlePhase.h"
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

class BattlePhase;

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
	 * Removes a monster from the battle
	 * @param monster The monster to remove
	 */
	void removeMonster(Monster* monster);

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

	/**
	 * Get the reason this battle ended
	 * @return The reason this battle ended
	 */
	string getEndReason() const;

	/**
	 * The end info for this battle
	 * @return The end info as a string
	 */
	string getEndInfo() const;

protected:

	/**
	 * Finishes the battle and pops this scene from the stack
	 */
	virtual void endBattle(string reason, string info);
private:

	BattlePhase* currentPhase;

	DynamicPtrArray* enemyList;

	TextObject* message;

	string endReason;

	string endInfo;
};

#endif /* BATTLE_H_ */
