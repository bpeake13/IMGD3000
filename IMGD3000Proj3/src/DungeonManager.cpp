/*
 * DungeonManager.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#include "DungeonManager.h"
#include "Adventurer.h"
#include "ResourceManager.h"
#include "Battle.h"
#include "Monster.h"

const string MONSTERS[2] = {"centaur", "slime"};

/**
 * Generates the adventure
 */
DungeonManager::DungeonManager() {
	// TODO Auto-generated constructor stub
	ResourceManager &rm = ResourceManager::getInstance();


	//Choose a random monster that is available.
	int random =1; //Random choice of monster from 0 to length-1

	string label = MONSTERS[random];
	Battle b;
	b.setEnemy(label);

}

const ObjectList& DungeonManager::getParty() const {
	return party;
}

void DungeonManager::setParty(const ObjectList& party) {
	this->party = party;
}

int DungeonManager::getTreasure() const {
	return treasure;
}

void DungeonManager::setTreasure(int treasure) {
	this->treasure = treasure;
}

DungeonManager::~DungeonManager() {
	// TODO Auto-generated destructor stub
}

/**
 * This function gets the party member with the given name
 * @param name
 * @return
 */
Adventurer DungeonManager::getPartyMember(string name) {

}

/**
 * This function gets the monster of the current scene
 * @return
 */
Monster DungeonManager::getMonster() {

}
