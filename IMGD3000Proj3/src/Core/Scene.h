/*
 * Scene.h
 *
 *  Created on: Oct 6, 2014
 *      Author: Benny
 */

#ifndef SCENE_H_
#define SCENE_H_

#include "Object.h"
#include "DynamicPtrArray.h"

/**
 * Class that contains multiple objects as children
 */
class Scene : public Object
{
public:
	/**
	 * Creates a new scene
	 */
	Scene();

	/**
	 * Destroys this scene and all objects that are children of this scene
	 */
	virtual ~Scene();

	/**
	 * Adds a new object to the scene
	 * @param obj The object to add to the scene
	 * @remarks This will first check the world manager to see if this is a valid object, if not then this funtion has no effect
	 */
	void addObject(Object* obj);

	/**
	 * Removes an object from the scene
	 * @param obj The object to remove from the scene
	 * @remarks This will first check the world manager to see if this is a valid object, if not then this funtion has no effect
	 */
	void removeObject(Object* obj);

	/**
	 * Checks if a child is a child of this scene
	 * @param obj The object to check with
	 * @return True if the object is a child, false otherwise
	 */
	bool isChild(Object* obj);

private:
	DynamicPtrArray* objectList;//list of all objects in this scene
};

#endif /* SCENE_H_ */
