/*
 * DungeonManager.h
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#ifndef DUNGEONMANAGER_H_
#define DUNGEONMANAGER_H_

#include "Manager.h"
#include "Adventurer.h"
#include "ObjectList.h"
#include "Scene.h"
#include "Monster.h"
#include "HashTable.h"

class DungeonManager: public Manager {
private:
	int treasure; //The amount of treasure amassed
	bool isPlayerTurn; //True if the player can make their turn, or do input
	HashTable party;

public:
	/**
	 * Class used to manage the adventure and party
	 */
	DungeonManager();

	/**
	 * Called when the Dungeon Manager is started. Creates the adventure
	 * @return Returns -1 if failure, 0 otherwise.
	 */
	int startUp();

	/**
	 * Is called when the dungeon manager is shut down.
	 */
	void shutDown();

	/**
	 * This function gets the party member with the given name
	 * @param name The label or name of the party member, such as "paladin"
	 * @return The Adventurer requested
	 */
	Adventurer* getPartyMember(string name);

	/**
	 * Returns the current scene the player is on
	 * @return the current Scene
	 */
	Scene* currentScene();

	/**
	 * Returns the amount of treasure that the player has won
	 * @return the 'treasure' variable of DungeonManager
	 */
	int getTreasure() const;

	/**
	 * Changes the
	 * @param treasure
	 */
	void setTreasure(int treasure);
	void onEvent(Event *p_e);
};

#endif /* DUNGEONMANAGER_H_ */
