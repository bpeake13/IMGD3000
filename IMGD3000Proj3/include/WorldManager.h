/*
 * WorldManager.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#ifndef WORLDMANAGER_H_
#define WORLDMANAGER_H_

#include "Manager.h"
#include "Box.h"
#include "Object.h"
#include "ObjectList.h"

#define MAX_OBJECTS 1024
#define LAYER_COUNT 4

/**
 * Manager class for the world
 */
class WorldManager : public Manager
{
private:
	//singleton object, these are not used
	WorldManager();
	WorldManager (WorldManager const&);
	WorldManager& operator=(const WorldManager& other);

	Box bounds;
	Box view;
	Object* following;
private:
	ObjectList markedForDeletion;//list of objects to delete when its safe
	ObjectList objects;//list of all objects in the world
	ObjectList collisionCheckList;//list for collision checks, we pre allocate this to increase speed of collision checks

	ObjectList* layerPools;//a list of all the pools (kept as a list of pointers to force lists to be created when wanted)
public:
	/**
	 * Get the singleton instance of this object
	 * @return A reference to the instance of this object
	 */
	static WorldManager& getInstance();

	/**
	 * Gets the worlds boundary
	 * @return The world boundary
	 */
	Box getBounds() const;

	/**
	 * Sets the world boundary
	 * @param bounds The new boundary to use for the world
	 */
	void setBounds(Box bounds);

	/**
	 * Gets the viewport in the world
	 * @return the world view
	 */
	Box getView() const;

	/**
	 * Sets the viewport in the world
	 * @param view The new viewport
	 */
	void setView(Box view);

	/**
	 * Sets the position of the viewport
	 * @param position The new position for the viewport
	 */
	void setViewPosition(const IVector& position);

	/**
	 * Gets what object the view should follow
	 * @return A pointer to the object that we are following or NULL if there is none
	 */
	Object* getFollowing() const;

	/**
	 * Sets the object that the view should follow
	 * @param follow A pointer to the object that we should follow, or NULL if no object should be followed
	 */
	void setFollowing(Object* follow);

	/**
	 * Converts a world coordinate to a view coordinate
	 * @param worldPos The world coordinate
	 * @return The view coordinate
	 */
	IVector worldToView(IVector& worldPos) const;

	/**
	 * Converts a view coordinate to a world coordinate
	 * @param viewPos The view coordinates
	 * @return The world coordinates
	 */
	IVector viewToWorld(IVector& viewPos) const;

	/**
	 * Called when the world manager is started
	 * @return 0 when no errors occurred, < 0 if errors did occur
	 */
	int startUp();

	/**
	 * Called to shut down the world manager, this will clean up all objects
	 */
	void shutDown();

	/**
	 * Adds an object to the world
	 * @param obj The object to add
	 * @return 1 if the object was added, 0 if not
	 */
	int addObject(Object* obj);

	/**
	 * Removes the object from the world
	 * @param obj The object to remove
	 * @return 1 if the object was removed, 0 otherwise
	 */
	int removeObject(Object* obj);

	/**
	 * Adds the object to the current layer pool that it has been assigned
	 * @param obj The object to add to a layer pool
	 * @return 1 if the object was added, 0 otherwise
	 */
	int addToLayerPool(Object* obj);

	/**
	 * Removes the object from its current layer pool
	 * @param obj The object to remove
	 * @return 1 if the object was removed, 0 otherwise
	 */
	int removeFromPool(Object* obj);

	/**
	 * Marks an object for deletion when it is safe
	 * @param object The object to delete
	 * @return 1 if ok, 0 if not
	 */
	int markForDelete(Object* object);

	/**
	 * Attempts to move an object to a location based on its collision model
	 * @param obj The object to try and move
	 * @param position The position to move it to
	 * @return True if the object was moved, false otherwise
	 */
	bool moveObject(Object* obj, IVector position);

	/**
	 * Gets a list of all objects in the world
	 * @param inactive If true, then also include objects that are inactive
	 * @return A list of the objects
	 */
	ObjectList getAllObjects(bool inactive=false) const;

	/**
	 * Gets a list of all objects that an object collides with when placed at a position
	 * @param obj The object to test collision with
	 * @param position The position to place the object at
	 * @param outList A list to fill with the objects that obj collised with, if NULL the function will ignore it
	 * @return True if there are any collisions otherwise false
	 */
	bool isCollision(Object* obj, IVector position, ObjectList* outList);

	/**
	 * Passes an event to all objects in the world
	 * @param e The event to pass
	 * @return 1 if any objects ate the event, 0 otherwise
	 */
	int onEvent(Event* e) const;

	/**
	 * Called once every frame to update objects
	 */
	void update();

	/**
	 * Called once every frame to draw
	 */
	void draw();
};

#endif /* WORLDMANAGER_H_ */
