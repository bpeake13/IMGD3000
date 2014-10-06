/*
 * TestObjectSolid.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#include "TestObjectSolid.h"

#include "EventCollision.h"
#include "GraphicsManager.h"

TestObjectSolid::TestObjectSolid()
{
	setPosition(IVector(15, 0));
	setSolidness(Hard);//set ourself to be solid
}

int TestObjectSolid::eventHandler(Event* e)
{
	return 0;
}

void TestObjectSolid::draw()
{
	Object::draw();
}
