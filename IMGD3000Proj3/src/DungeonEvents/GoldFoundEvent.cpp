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
}

void GoldFoundEvent::start(){
	treasure = Math::randomRange(1, 20) + Math::randomRange(1, 20) + Math::randomRange(0, 20);
	string strtreasure = "You found gold, +" +treasure;
	setViewString(strtreasure);
	PartyManager::getInstance().addTreasure(treasure);
}
