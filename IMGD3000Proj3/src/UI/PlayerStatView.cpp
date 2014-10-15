/*
 * PlayerStatView.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Eric
 */

#include "PlayerStatView.h"
#include "EventStep.h"

PlayerStatView::PlayerStatView(){
}

PlayerStatView::PlayerStatView(int maxhealth){
	setValue(maxhealth);
	setViewString("HP");
}

PlayerStatView::PlayerStatView(Adventurer* adv){
	setValue(adv->getHealth());
	setViewString("HP");
	this->adventurer = adv;
	this->setViewString(adv->getName() + ": ");
}

int PlayerStatView::eventHandler(Event* e)
{
	string eventType = e->getType();

	if(eventType == DF_EVENT_STEP)
	{
		this->setValue(adventurer->getHealth());
		return 1;
	}
}
