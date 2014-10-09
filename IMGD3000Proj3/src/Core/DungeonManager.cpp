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
	//Generate monsters and scenes.
	for (int i=1; i<=10; i++){

		//Randomly choose a monster to add
		int random=1;
		string filename = "mon-" + MONSTERS[random] +"-spr.txt";
		Monster *m = new Monster;
		m->setSpr(filename); //Gets Monster to set its sprite

		//Set the stats for the monster
		m->setHealth(100);
		m->setAttack(10);
		m->setReward(50);

		//Create the scene and add the monster
		Scene *sc = new Scene;
		sc->addObject((Object *) m);

		//Add to the top of stack
		SceneManager &sm = SceneManager::getInstance();
		sm.push(sc);
	}
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

	//We must add the object to the world manager
	//This way it will recieve events just like an object
	//And can translate them and send a different event to objects
	WorldManager &wm = WorldManager::getInstance();
	wm.addObject((Object *) this);
	//Casting to object, the only functions that should be called
	//On this incorrectly casted object is eventHandler
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
