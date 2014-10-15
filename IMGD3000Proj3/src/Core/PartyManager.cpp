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
#include "EventView.h"

#include "WorldManager.h"

PartyManager::PartyManager() {
	this->treasure =0;
}
PartyManager::PartyManager(const PartyManager& other) {
	this->treasure =0;
}
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
	party.add(new Adventurer("Paladin", 100, 100, 100, "A mighty paladin"));
	party.add(new Adventurer("Cleric", 150, 50, 100, "A worldly cleric"));
	party.add(new Adventurer("Wizard", 50, 100, 150, "A wise wizard"));
	party.add(new Adventurer("Rogue", 100, 50, 150, "A sneaky rogue"));
	//Adventurers are ready to take on the world

	return 1;
}

void PartyManager::shutDown(){
	Manager::shutDown();
}

int PartyManager::getTreasure() const {
	return treasure;
}

void PartyManager::setTreasure(int treasure) {
	this->treasure = treasure;

	WorldManager& world = WorldManager::getInstance();

	EventView ev = EventView("Gold", treasure, false);
	world.onEvent(&ev);
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

Adventurer* PartyManager::getPartyMember(int i) const
{
	return dynamic_cast<Adventurer*>(party[i]);
}

void PartyManager::removePartyMember(Adventurer* adv){
	party.remove(adv);
}

Scene* PartyManager::currentScene()
{
}

size_t PartyManager::getPartySize() const
{
	return party.getCount();
}

void PartyManager::addTreasure(int reward)
{
	this->treasure = this->treasure+reward;
}

bool PartyManager::isTotalPartyKill() const
{
	size_t count = party.getCount();
	for(size_t i = 0; i < count; i++)
	{
		Adventurer* a = this->getPartyMember((int)i);
		if(!a->isDead())
			return false;
	}

	return true;
}
