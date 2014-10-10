/*
 * PartyDeathEvent.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Eric
 */

#include "PartyDeathEvent.h"
#include "PartyManager.h"
#include "Adventurer.h"
#include "MathExt.h"

PartyDeathEvent::PartyDeathEvent() : DungeonEvent(PROBABILITY){

}

void PartyDeathEvent::start(){
	int deathnum = Math::randomRange(1,9);
	string death;
	switch(deathnum){
	case 1:
		death = " was impaled by a spike trap.";
		break;
	case 2:
		death = " fell down a bottomless pit.";
		break;
	case 3:
		death = " contracted magical dysentery and died.";
		break;
	case 4:
		death = " was eaten by a grue.";
		break;
	case 5:
		death = " stepped on one too many arrow traps.";
		break;
	case 6:
		death = " got lost in the dungeon.";
		break;
	case 7:
		death = " decided adventuring was too dangerous, and decided to retire and start a family.";
		break;
	case 8:
		death = " has joined the forces of evil.";
		break;
	default:
		death = " has died.";
		break;
	}

	int partymember = Math::randomRange(0,MAXPARTYSIZE);
	PartyManager &pm = PartyManager::getInstance();
	Adventurer* adv = pm.getPartyMember("rogue");

	string fullmessage = adv->getName() + death;
	setViewString(fullmessage);

	//pm.getPartyMember(partymember);
}
