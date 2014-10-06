/*
 * TestObjectSoft.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#include "TestObjectSoft.h"
#include "EventCollision.h"
#include "GraphicsManager.h"
#include "LogManager.h"

TestObjectSoft::TestObjectSoft()
{
	setSolidness(Soft);
	setPosition(IVector(5, 1));
}

int TestObjectSoft::eventHandler(Event* e)
{
	if(e->getType() == DF_EVENT_COLLISION)
	{
		LogManager& log = LogManager::getInstance();
		log.writeLog("SOFT COLLISION");

		return 1;
	}

	return 0;
}

void TestObjectSoft::draw()
{
	GraphicsManager& graphics = GraphicsManager::getInstance();
	graphics.drawCh(getPosition(), 'S');
}
