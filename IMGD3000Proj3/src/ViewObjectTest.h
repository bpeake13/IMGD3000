/*
 * ViewObjectTest.h
 *
 *  Created on: Sep 30, 2014
 *      Author: Benny
 */

#ifndef VIEWOBJECTTEST_H_
#define VIEWOBJECTTEST_H_

#include "ViewObject.h"

class ViewObjectTest : public ViewObject
{
public:
	ViewObjectTest(string tag, ViewObjectLocation location, int value, bool border);
};

#endif /* VIEWOBJECTTEST_H_ */
