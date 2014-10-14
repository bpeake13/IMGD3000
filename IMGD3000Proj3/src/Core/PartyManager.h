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


#define MAXPARTYSIZE 4

/**
 * Class used to manage the party members and items of the party
 */
class PartyManager: public Manager {
private:
	int treasure;
	ObjectList party;
	PartyManager();
	PartyManager(PartyManager const&);
	PartyManager& operator=(const PartyManager& other);

public:

	/**
	 * Returns the singleton instance of the party manager
	 * @return Reference  to the party manager instance
	 */
	static PartyManager& getInstance();

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
	 * Gets the ith part member
	 * @param i The index of the party member to get
	 * @return The party member at i, or NULL
	 */
	Adventurer* getPartyMember(int i);

	void removePartyMember(Adventurer *adv);

	size_t getPartySize() const;

	/**
	 * This function returns a pointer to an object list containing the adventuring party
	 * @return The pointer to an object list of adventurers
	 */
	ObjectList* getParty();

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

	/**
	 * Adds an amount treasure to the party's treasure
	 * @param reward The amount of treasure to add
	 */
	void addTreasure(int reward);

};

#endif /* DUNGEONMANAGER_H_ */
