/*
 * PlayerStatView.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Eric
 */

#include "PlayerStatView.h"

PlayerStatView::PlayerStatView() : StatusBar(0){
}

PlayerStatView::PlayerStatView(int maxhealth) : StatusBar(maxhealth){
	setMaxValue(maxhealth);
	setValue(maxhealth);
	setViewString("HP");
}

PlayerStatView::PlayerStatView(Adventurer* adv) : StatusBar(0){
	setMaxValue(adv->getMaxHealth());
	setValue(adv->getHealth());
	setViewString("HP");
}
