/*
 * Scene.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Benny
 */

#include "Scene.h"

#include "WorldManager.h"

Scene::Scene()
{
	objectList = new DynamicPtrArray(32);
}

Scene::~Scene()
{
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
