/*
 * SceneOverEvent.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Benny
 */

#include "SceneOverEvent.h"

SceneOverEvent::SceneOverEvent(string reason, string info)
{
	this->reason = reason;
	this->info = info;
}

string SceneOverEvent::getReason() const
{
	return reason;
}

string SceneOverEvent::getInfo() const
{
	return info;
}
