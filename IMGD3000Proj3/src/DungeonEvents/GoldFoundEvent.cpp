/*
 * GoldFoundEvent.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Eric
 */

#include "GoldFoundEvent.h"
#include "EventKeyboard.h"
#include "PartyManager.h"
#include "MathExt.h"

GoldFoundEvent::GoldFoundEvent() : DungeonEvent(PROBABILITY){
	this->treasure=0;
}

void GoldFoundEvent::start(){
	DungeonEvent::start();

	treasure = Math::randomRange(1, 20) + Math::randomRange(1, 20) + Math::randomRange(0, 20);
	string strtreasure = "You found gold";
	setViewString(strtreasure);
	PartyManager::getInstance().addTreasure(treasure);
}
