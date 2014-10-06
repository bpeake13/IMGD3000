/*
 * EventCollision.h
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#ifndef EVENTCOLLISION_H_
#define EVENTCOLLISION_H_

#include "Event.h"
#include "Object.h"
#include "IVector.h"

#define DF_EVENT_COLLISION "__collision__"

/**
 * An event that is fired whenever a collision happens
 * This event is not global, it will only be fired on objects involved in the collision
 */
class EventCollision : public Event
{
public:
	/**
	 * Creates a new collision event
	 * @param position The position that the collision was at
	 * @param obj1 The first object in the collision
	 * @param obj2 The second object in the collision
	 */
	EventCollision(IVector position, Object* obj1, Object* obj2);

	/**
	 * The position the collision was at
	 * @return An IVector that represents the world location that the collision was at
	 */
	IVector getPosition();

	/**
	 * Gets the first object involved in the collision
	 * @return The first object involved in the collision
	 */
	Object* getObj1() const;

	/**
	 * Gets the second object involved in the collision
	 * @return The second object involved in the collision
	 */
	Object* getObj2() const;

private:
	Object* obj1;//the first object in the collision
	Object* obj2;//the second object in the collision

	IVector position;//the position that the collision was at
};

#endif /* EVENTCOLLISION_H_ */
