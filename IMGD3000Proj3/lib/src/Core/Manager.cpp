/*
 * Manager.cpp
 *
 *  Created on: Sep 14, 2014
 *      Author: Benny
 */

#include <Manager.h>

Manager::Manager()
{
	isStarted = false;
}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}

int Manager::startUp()
{
	isStarted = true;
	return 0;
}

void Manager::shutDown()
{
	isStarted = false;
}

bool Manager::hasStarted() const
{
	return isStarted;
}

int Manager::onEvent(Event* e) const
{
	return 0;
}
