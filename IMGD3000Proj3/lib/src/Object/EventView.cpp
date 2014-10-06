/*
 * EventView.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: Benny
 */

#include "EventView.h"

EventView::EventView(string tag, int value, bool delta)
{
	this->tag = tag;
	this->value = value;
	this->delta = delta;
}

string EventView::getTag() const
{
	return tag;
}

int EventView::getValue() const
{
	return value;
}

bool EventView::getDelta() const
{
	return delta;
}
