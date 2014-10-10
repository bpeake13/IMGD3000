/*
 * DungeonManager.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#include "PartyManager.h"
#include "Adventurer.h"
#include "ObjectListIterator.h"

#include "EventKeyboard.h"

const string MONSTERS[2] = {"centaur", "slime"};

PartyManager::PartyManager() {}
PartyManager::PartyManager(const PartyManager& other) {}
PartyManager& PartyManager::operator=(const PartyManager& other) {}

/**
 * This function returns the singleton instance of the party manager
 * @return
 */
PartyManager& PartyManager::getInstance(){
	static PartyManager instance;
	return instance;
}

int PartyManager::startUp(){

	party = ObjectList(MAXPARTYSIZE);
	treasure =0;

	//Create the adventurers and put them in a rad party.
	party.add((Object *) new Adventurer("paladin", 100, 100, 100, "A mighty paladin"));
	party.add((Object *) new Adventurer("cleric", 125, 50, 75, "A worldly cleric"));
	party.add((Object *) new Adventurer("wizard", 50, 25, 225, "A wise wizard"));
	party.add((Object *) new Adventurer("rogue", 100, 0, 200, "A sneaky rogue"));
	//Adventurers are ready to take on the world
}

void PartyManager::shutDown(){
	Manager::shutDown();
}

int PartyManager::getTreasure() const {
	return treasure;
}

void PartyManager::setTreasure(int treasure) {
	this->treasure = treasure;
}

void PartyManager::addTreasure(int reward){
	this->treasure = this->treasure + reward;
}

Adventurer* PartyManager::getPartyMember(string name){
	ObjectListIterator oli = ObjectListIterator(&party);

	for(oli.first(); !oli.isDone(); oli.next()){
		Adventurer* a = (Adventurer *) oli.getCurrent();
		if(a->getName() == name){
			return a;
		}
	}

	Adventurer* empty;
	return empty;
}

ObjectList* PartyManager::getParty(){
	return &party;
}
