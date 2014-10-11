/*
 * DungeonEvent.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Benny
 */

#include "DungeonEvent.h"

#include "EventKeyboard.h"

DungeonEvent::DungeonEvent(float probability) : TextObject()
{
	this->hasPressedKey = false;
	this->isActive = false;
	this->probability = probability;

	setViewObjectLocation(CENTER_CENTER);
	setColor(COLOR_YELLOW);
}

bool DungeonEvent::isDone() const
{
	return hasPressedKey;
}

void DungeonEvent::start()
{
	isActive = true;
}

void DungeonEvent::finish()
{
	isActive = false;
}

float DungeonEvent::getProbability() const
{
	return probability;
}

int DungeonEvent::eventHandler(Event* e)
{
	string typeName = e->getType();
	if(typeName == DF_EVENT_KEYBOARD)
	{
		EventKeyboard* ek = static_cast<EventKeyboard*>(e);

		if(ek->getKey() == ' ')
		{
			hasPressedKey = true;
			return 1;
		}
	}

	return 0;
}

void DungeonEvent::draw()
{
	if(isActive)
		TextObject::draw();
}

void DungeonEvent::setKeyPressed(bool b) {
	this->hasPressedKey = b;
}

bool DungeonEvent::getKeyPressed() const{
	return this->hasPressedKey;
}
