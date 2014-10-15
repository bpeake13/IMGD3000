/*
 * PlayerStatView.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Eric
 */

#include "PlayerStatView.h"

PlayerStatView::PlayerStatView(){
}

PlayerStatView::PlayerStatView(int maxhealth){
	setValue(maxhealth);
	setViewString("HP");
}

PlayerStatView::PlayerStatView(Adventurer* adv){
	setValue(adv->getHealth());
	setViewString("HP");
}
