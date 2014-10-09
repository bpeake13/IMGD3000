/*
 * EventKeyboard.h
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#ifndef EVENTKEYBAORD_H_
#define EVENTKEYBOARD_H_

#include "Event.h"

#define DF_EVENT_KEYBOARD "__keyboard__"

/**
 * Event called whenever there is a keyboard event
 */
class EventKeyboard : public Event
{
public:
	/**
	 * Creates a new keyboard event
	 * @param key The key value that was pressed
	 */
	EventKeyboard(int key);

	/**
	 * Gets the key value of this event
	 * @return An integer representing the key value
	 */
	int getKey() const;

private:
	int key;
};

#endif /* EVENTKEYBAORD_H_ */
