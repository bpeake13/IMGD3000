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
#include "IVector.h"

#define PROBABILITY .25

class PromptEvent: public DungeonEvent {
private:
	int originalx;
	int originaly;
	string prompt;
	string accept;
	string reject;
	bool madechoice;
	int promptnumber;
	int goldlost;
	TextObject rejectText;
	TextObject acceptText;
	int advnum;
	void hasAccepted();
	void hasRejected();

public:
	PromptEvent();
	~PromptEvent();
	void start();
	int eventHandler(Event* e);

};

#endif /* PROMPTEVENT_H_ */
