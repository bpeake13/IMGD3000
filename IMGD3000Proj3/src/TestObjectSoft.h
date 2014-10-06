/*
 * TestObjectSoft.h
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#ifndef TESTOBJECTSOFT_H_
#define TESTOBJECTSOFT_H_

#include "Object.h"

class TestObjectSoft : public Object
{
public:
	TestObjectSoft();

	int eventHandler(Event* e);

	void draw();
};

#endif /* TESTOBJECTSOFT_H_ */
