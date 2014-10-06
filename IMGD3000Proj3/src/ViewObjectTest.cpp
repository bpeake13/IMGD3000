/*
 * ViewObjectTest.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: Benny
 */

#include "ViewObjectTest.h"

ViewObjectTest::ViewObjectTest(string tag, ViewObjectLocation location, int value, bool border)
{
	setViewString(tag);
	setValue(value);
	setViewObjectLocation(location);
	setDrawBorder(border);
}

