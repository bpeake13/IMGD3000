/*
 * Event.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#include "Event.h"

Event::Event()
{
	eventType = DEFAULT_EVENT_NAME;
}

Event::~Event()
{
}

void Event::setType(string new_type)
{
	eventType = new_type;
}

string Event::getType() const
{
	return eventType;
}
