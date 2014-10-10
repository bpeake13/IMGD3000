/*
 * DungeonScene.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Benny
 */

#ifndef DUNGEONSCENE_H_
#define DUNGEONSCENE_H_

#include "Scene.h"
#include "DungeonEvent.h"

/**
 * The scene responsible for the dungeon
 */
class DungeonScene : public Scene
{
public:
	/**
	 * Creates a new dungeon scene
	 */
	DungeonScene();

	/**
	 * Handles events for the dungeon scene
	 * @param e The event to handle
	 * @return 1 if the event is eaten, 0 otherwise
	 */
	virtual int eventHandler(Event* e);

private:
	/**
	 * Steps the player forward one unit
	 */
	void step();

private:
	DungeonEvent** events;//list of possible events that can happen

	DungeonEvent* currentEvent;

	int stepCounter;//the counter to take our next step

	bool isSteping;//if true then we should step when the counter reaches 0
};

#endif /* DUNGEONSCENE_H_ */
