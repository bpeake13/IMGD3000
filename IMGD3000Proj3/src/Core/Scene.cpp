/*
 * Scene.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Benny
 */

#include "Scene.h"
#include "SceneManager.h"
#include "WorldManager.h"

Scene::Scene()
{
	objectList = new DynamicPtrArray(32);
	setSolidness(Spectral);
}

Scene::~Scene()
{
	//delete all children of this scene

	size_t objCount = objectList->getSize();
	for(int i = 0; i < objCount; i++)
	{
		delete static_cast<Object*>(objectList->get(i));
	}

	objectList->clear();
	delete objectList;
}

void Scene::addObject(Object* obj)
{
	WorldManager& world = WorldManager::getInstance();
	if(!world.containsObject(obj))
		return;

	objectList->add(obj);
}

void Scene::removeObject(Object* obj)
{
	WorldManager& world = WorldManager::getInstance();
	if(!world.containsObject(obj))
		return;

	objectList->remove(obj);
}

bool Scene::isChild(Object* obj)
{
	size_t size = objectList->getSize();

	for(int i = 0; i < size; i++)
	{
		if(obj == objectList->get(i))
			return true;
	}

	return false;
}

int Scene::eventHandler(Event* e)
{
	if(SceneManager::peek() != this)//only process events when on the top of the stack
		return 1;

	return 0;
}
