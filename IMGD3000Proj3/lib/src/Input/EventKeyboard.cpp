/*
 * EventKeybaord.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#include "EventKeybaord.h"

EventKeybaord::EventKeybaord(int key)
{
	this->key = key;

	setType(DF_EVENT_KEYBOARD);
}

int EventKeybaord::getKey() const
{
	return key;
}
