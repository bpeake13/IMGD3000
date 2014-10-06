/*
 * ResourceManager.h
 *
 *  Created on: Sep 29, 2014
 *      Author: Benny
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include "HashTable.h"
#include "Manager.h"
#include "Utility.h"
#include "Sprite.h"

/**
 * Handles loading and unloading resources
 */
class ResourceManager : public Manager
{
public:
	/**
	 * Gets the singleton instance of the resource manager
	 * @return A reference to the resource manager
	 */
	static ResourceManager& getInstance();

	/**
	 * Called when the resource manager is started
	 * @return 0 on ok, -1 otherwise
	 */
	int startUp();

	/**
	 * Called when the resource manager is shut down
	 */
	void shutDown();

	/**
	 * Loads a sprite from file into memory
	 * @param file The file to load from
	 * @param label The label to assign the sprite
	 * @return True if the sprite could be loaded, false otherwise
	 */
	bool loadSprite(string file, string label);

	/**
	 * Unloads a sprite from memory
	 * @param label The label of the sprite
	 * @return True if the sprite could be unloaded, false otherwise
	 */
	bool unloadSprite(string label);

	/**
	 * Gets a sprite from the resource lookup table
	 * @param label The label that the sprite was assigned
	 * @return A ptr to the sprite if the sprite was found, NULL otherwise
	 */
	Sprite* getSprite(string label) const;

private:
	ResourceManager();
	ResourceManager(const ResourceManager&);
	ResourceManager& operator=(const ResourceManager& other);

private:
	HashTable* resourceTable;//lookup table for all resources that have been loaded
};

#endif /* RESOURCEMANAGER_H_ */
