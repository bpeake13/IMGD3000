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

PartyDeathEvent::PartyDeathEvent() : DungeonEvent(0.01){

}

void PartyDeathEvent::start(){
	DungeonEvent::start();

	int deathnum = Math::randomRange(1,10);
	string death;
	switch(deathnum){
	case 1://
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
	case 9:
		death = " can't even.";
		break;
	default:
		death = " has died.";
		break;
	}
	PartyManager& pm = PartyManager::getInstance();
	size_t partySize = pm.getPartySize();

	Adventurer* a = NULL;
	while(!a || a->isDead())
	{
		a = pm.getPartyMember(Math::randomRange(0, partySize));
	}

	string fullMessage = a->getName() + " " + death;

	setViewString(fullMessage);

	a->damage(a->getHealth());
}
