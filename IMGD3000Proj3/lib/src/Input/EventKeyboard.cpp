/*
 * EventKeybaord.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#include "EventKeyboard.h"

EventKeyboard::EventKeyboard(int key)
{
	this->key = key;

	setType(DF_EVENT_KEYBOARD);
}

int EventKeyboard::getKey() const
{
	return key;
}
