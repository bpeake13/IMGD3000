/*
 * TestObjectSolid.h
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#ifndef TESTOBJECTSOLID_H_
#define TESTOBJECTSOLID_H_

#include "Object.h"
#include "Event.h"

class TestObjectSolid : public Object
{
public:
	TestObjectSolid();

	int eventHandler(Event* e);

	void draw();
};

#endif /* TESTOBJECTSOLID_H_ */
