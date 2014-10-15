/*
 * PlayerStatView.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Eric
 */

#ifndef PLAYERSTATVIEW_H_
#define PLAYERSTATVIEW_H_

#include "StatusBar.h"
#include "Adventurer.h"
#include "Event.h"

class PlayerStatView: public ViewObject {
public:
	PlayerStatView();
	PlayerStatView(int maxhealth);

	/**
	 * Creates a status bar for an adventurer's health
	 * @param adv The adventurer to display for
	 */
	PlayerStatView(Adventurer* adv);

	int eventHandler(Event* e);

private:
	Adventurer* adventurer;
};

#endif /* PLAYERSTATVIEW_H_ */
