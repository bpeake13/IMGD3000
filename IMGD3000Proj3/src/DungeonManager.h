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

class DungeonManager: public Manager {
private:
	int treasure; //The amount of treasure amassed
	int location; //The scene the players are on
	ObjectList party; //The list of the player's characters
	Scene adventure[11]; //The list of scenes that make up the adventure.


public:
	DungeonManager();
	virtual ~DungeonManager();
	Adventurer getPartyMember(string name);
	Monster getMonster();
	Scene currentScene();
	const ObjectList& getParty() const;
	void setParty(const ObjectList& party);
	int getTreasure() const;
	void setTreasure(int treasure);
};

#endif /* DUNGEONMANAGER_H_ */
