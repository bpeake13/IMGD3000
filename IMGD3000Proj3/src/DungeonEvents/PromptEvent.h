/*
 * PromptEvent.h
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#ifndef PROMPTEVENT_H_
#define PROMPTEVENT_H_

#include "DungeonEvent.h"
#include "Event.h"
#include "Adventurer.h"

#define PROBABILITY .25

class PromptEvent: public DungeonEvent {
private:
	string prompt;
	string accept;
	string reject;
	bool madechoice;
	int promptnumber;
	int goldlost;
	TextObject rejectText;
	TextObject acceptText;
	Adventurer* adv;
	void hasAccepted();
	void hasRejected();

public:
	PromptEvent();
	void start();
	int eventHandler(Event* e);

};

#endif /* PROMPTEVENT_H_ */
