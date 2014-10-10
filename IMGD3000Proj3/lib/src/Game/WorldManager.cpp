/*
 * WorldManager.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#include "WorldManager.h"
#include "EventStep.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "GameManager.h"
#include "GraphicsManager.h"

#include <algorithm>

WorldManager::WorldManager()
{
	objects = ObjectList(MAX_OBJECTS);//create a total object array with chunk size of 50
	markedForDeletion = ObjectList(MAX_OBJECTS);
	collisionCheckList = ObjectList(MAX_OBJECTS);//create the list for collision checks

	layerPools = new ObjectList[LAYER_COUNT];

	for(int i = 0; i < LAYER_COUNT; i++)
	{
		layerPools[i] = ObjectList(MAX_OBJECTS);//each pool should be made to the max object count
	}
}

WorldManager& WorldManager::getInstance()
{
	static WorldManager instance;
	return instance;
}

Box WorldManager::getBounds() const
{
	return bounds;
}

void WorldManager::setBounds(Box bounds)
{
	this->bounds = bounds;
}

Box WorldManager::getView() const
{
	return view;
}

void WorldManager::setView(Box view)
{
	this->view = view;
}

void WorldManager::setViewPosition(const IVector& position)
{
	IVector wMin = bounds.getCorner();
	IVector wMax = bounds.getMaxCorner();

	int vw = view.getHorizontal();
	int vh = view.getVertical();

	IVector viewSize = IVector(vw / 2, vh / 2);

	IVector camPointMin = wMin + viewSize;
	IVector camPointMax = wMax - viewSize;

	int x = std::min(camPointMax.getX(), std::max(position.getX(), camPointMin.getX()));
	int y = std::min(camPointMax.getY(), std::max(position.getY(), camPointMin.getY()));

	IVector viewCorner = IVector(x, y) - viewSize;
	view.setCorner(viewCorner);
}

IVector WorldManager::worldToView(IVector& worldPos) const
{
	return worldPos - view.getCorner();
}

IVector WorldManager::viewToWorld(IVector& viewPos) const
{
	return viewPos + view.getCorner();
}

Object* WorldManager::getFollowing() const
{
	return following;
}

void WorldManager::setFollowing(Object* follow)
{
	this->following = follow;
}

int WorldManager::startUp()
{
	GraphicsManager& graphics = GraphicsManager::getInstance();
	int width = graphics.getHorizontal();
	int height = graphics.getVertical();

	bounds = Box(IVector(0, 0), width, height);
	view = bounds;

	return Manager::startUp();
}

void WorldManager::shutDown()
{
	if(!hasStarted())
		return;

	Manager::shutDown();

	markedForDeletion.clear();//clear out the deletion list

	ObjectListIterator iterator = ObjectListIterator(&objects);//get an iterator for the objects

	for(Object* obj = iterator.getCurrent(); !iterator.isDone(); iterator.next(), obj = iterator.getCurrent())
	{
		delete obj;//delete the object
	}
}

int WorldManager::addObject(Object* obj)
{
	return objects.add(obj);
}

int WorldManager::removeObject(Object* obj)
{
	return objects.remove(obj);
}

bool WorldManager::containsObject(Object* obj)
{
	ObjectListIterator iterator = ObjectListIterator(&objects);
	for(Object* o = iterator.getCurrent(); !iterator.isDone(); iterator.next(), o = iterator.getCurrent())
	{
		if(o == obj)
			return true;
	}

	return false;
}


int WorldManager::addToLayerPool(Object* obj)
{
	unsigned int layer = obj->getAltitude();//get the objects layer
	if(layer >= LAYER_COUNT)
		return 0;//if we are an invalid layer then give back an error

	return layerPools[layer].add(obj);//return the result of adding the object to the pool
}

int WorldManager::removeFromPool(Object* obj)
{
	unsigned int layer = obj->getAltitude();
	if(layer >= LAYER_COUNT)
		return 0;

	return layerPools[layer].remove(obj);
}

int WorldManager::markForDelete(Object* object)
{
	if(!markedForDeletion.contains(object))
		return markedForDeletion.add(object);

	return 0;
}

ObjectList WorldManager::getAllObjects(bool inactive) const
{
	ObjectList newList;
	newList = objects;
	return newList;
}

bool WorldManager::isCollision(Object* obj, IVector position, ObjectList* outList)
{
	if(outList)
		outList->clear();//clear the list of all entries

	bool result = false;

	Box b1 = obj->getWorldBounds(position);

	//loop over every object in the scene
	ObjectListIterator iterator = ObjectListIterator(&objects);
	for(Object* i = iterator.getCurrent(); !iterator.isDone(); iterator.next(), i = iterator.getCurrent())
	{
		if(i == obj || !obj->isCollidable())
			continue;//do not collide with self or with an object that has collision off


		Box b2 = i->getWorldBounds();
		if(!b1.intersects(b2))//if no collision then continue to the next object
			continue;

		if(outList && !outList->isFull())
		{
			outList->add(i);
			result = true;
		}
		else
		{
			return true;
		}
	}

	return result;
}

bool WorldManager::moveObject(Object* obj, IVector position)
{
	if(obj->isCollidable())//if we have a collision model then we must take that into consideration before moving
	{
		if(isCollision(obj, position, &collisionCheckList))//if we have a collision
		{
			bool doMove = true;
			ObjectListIterator iterator = ObjectListIterator(&collisionCheckList);//go through every object
			for(Object* i = iterator.getCurrent(); !iterator.isDone(); iterator.next(), i = iterator.getCurrent())
			{
				if(obj->isCollidable())
				{
					EventCollision e = EventCollision(position, obj, i);//create a collision event

					//send the collision event to both objects
					obj->eventHandler(&e);
					i->eventHandler(&e);

					doMove = i->getSolidness() != Hard && doMove;//check if we should still do the move
				}

			}

			if(doMove)//if we still move then move to the position
			{
				obj->setPosition(position);
				return true;
			}//otherwise do not and return so
			else
				return false;
		}
		else//if there is no collision then we can just move to the location
		{
			obj->setPosition(position);
		}
	}
	else//if we have no collision model, then just jump to the position
	{
		obj->setPosition(position);
		return true;
	}

	return false;
}

int WorldManager::onEvent(Event* e) const
{
	int result = 0;

	ObjectListIterator iterator = ObjectListIterator(&objects);
	for(Object* obj = iterator.getCurrent(); !iterator.isDone(); iterator.next(), obj = iterator.getCurrent())
	{
		if(obj->eventHandler(e))
			result = 1;
	}

	return result;
}

void WorldManager::update()
{
	ObjectListIterator iterator = ObjectListIterator(&objects);//create an iterator

	GameManager& gm = GameManager::getInstance();
	EventStep stepEvent = EventStep(gm.getTickCount());//create the step event
	for(Object* obj = iterator.getCurrent(); !iterator.isDone(); iterator.next(), obj = iterator.getCurrent())
	{
		obj->eventHandler(&stepEvent);//send the event to the object event handler to process

		IVector delta = obj->getVelocityStep();//check to see how much we move by

		IVector newPosition = IVector(0, 0);
		if(delta != IVector(0, 0))//only move if we have velocity
		{
			newPosition = obj->getPosition() + delta;//move the object by the change in position
			moveObject(obj, newPosition);
		}
		else
			newPosition = obj->getPosition();

		if(!bounds.intersects(obj->getWorldBounds()))
		{
			EventOut eo = EventOut();//create an out event
			obj->eventHandler(&eo);
		}
	}

	LogManager& log = LogManager::getInstance();
	ObjectListIterator deleteIterator = ObjectListIterator(&markedForDeletion);
	for(Object* obj = deleteIterator.getCurrent(); !deleteIterator.isDone(); deleteIterator.next(), obj = deleteIterator.getCurrent())
	{
		objects.remove(obj);
		removeFromPool(obj);
		delete obj;
	}

	markedForDeletion.clear();
}

WorldManager::WorldManager(const WorldManager&)
{
	layerPools = NULL;
}

WorldManager& WorldManager::operator =(const WorldManager& other)
{
	return *this;
}

void WorldManager::draw()
{
	if(following)
		setViewPosition(following->getPosition());

	for(int i = 0; i < LAYER_COUNT; i++)
	{
		ObjectListIterator iterator = ObjectListIterator(&layerPools[i]);//create an iterator

		GraphicsManager& graphics = GraphicsManager::getInstance();
		for(Object* obj = iterator.getCurrent(); !iterator.isDone(); iterator.next(), obj = iterator.getCurrent())
		{
			//if(obj->getWorldBounds().intersects(view))
				obj->draw();
		}
	}
}
