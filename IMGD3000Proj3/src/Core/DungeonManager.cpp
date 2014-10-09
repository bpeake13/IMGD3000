/*
 * DungeonManager.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#include "WorldManager.h"
#include "DungeonManager.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Battle.h"
#include "Adventurer.h"
#include "Monster.h"

#include "EventKeybaord.h"

#include "HashTable.h"

const string MONSTERS[2] = {"centaur", "slime"};

DungeonManager::DungeonManager() {

}

int DungeonManager::startUp(){

	//Generate the dungeon
	//Ten scenes are now in the SceneManager, ready for use

	//Generate the adventurers
	Adventurer *paladin = new Adventurer("paladin", 100, 100, 100, "A mighty paladin");
	Adventurer *cleric = new Adventurer("cleric", 125, 50, 75, "A worldly cleric");
	Adventurer *wizard = new Adventurer("wizard", 50, 25, 225, "A wise wizard");
	Adventurer *rogue = new Adventurer("rogue", 100, 0, 200, "A sneaky rogue");

	//Put them in a rad party.
	party.set("paladin", (void *) paladin);
	party.set("rogue", (void *) rogue);
	party.set("wizard", (void *) wizard);
	party.set("cleric", (void *) cleric);
	//Adventurers are ready to take on the world

	treasure =0; //They are dirt poor though
}

void DungeonManager::shutDown(){
	Manager::shutDown();
}

int DungeonManager::getTreasure() const {
	return treasure;
}

void DungeonManager::setTreasure(int treasure) {
	this->treasure = treasure;
}

Adventurer* DungeonManager::getPartyMember(string name){
	Adventurer *a = (Adventurer *) party.get(name);
	return a;
}
