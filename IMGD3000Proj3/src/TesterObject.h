/*
 * TesterObject.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#ifndef TESTEROBJECT_H_
#define TESTEROBJECT_H_

#include "Object.h"
#include "WorldManager.h"

class TesterObject : public Object
{
public:
	TesterObject(IVector position);
	virtual ~TesterObject();

	int eventHandler(Event* e);

	void draw();
};

#endif /* TESTEROBJECT_H_ */
