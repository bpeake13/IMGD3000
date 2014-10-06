/*
 * EventCollision.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#include "EventCollision.h"

EventCollision::EventCollision(IVector position, Object* obj1, Object* obj2) : position(position), obj1(obj1), obj2(obj2)
{
	setType(DF_EVENT_COLLISION);
}

IVector EventCollision::getPosition()
{
	return position;
}

Object* EventCollision::getObj1() const
{
	return obj1;
}

Object* EventCollision::getObj2() const
{
	return obj2;
}
