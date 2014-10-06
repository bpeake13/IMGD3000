/*
 * EventMouse.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#include "EventMouse.h"

EventMouse::EventMouse(int x, int y, MouseActionList action)
{
	this->x = x;
	this->y = y;
	this->mouseAction = action;

	setType(DF_EVENT_MOUSE);
}

int EventMouse::getX() const
{
	return x;
}

int EventMouse::getY() const
{
	return y;
}

MouseActionList EventMouse::getMouseAction() const
{
	return mouseAction;
}
