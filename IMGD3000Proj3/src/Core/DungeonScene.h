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
#include "PlayerStatView.h"

/**
 * The scene responsible for the dungeon
 */
class DungeonScene : public Scene
{
public:
	/**
	 * Creates a new dungeon scene
	 * @param stepCount the max number of steps in this dungeon
	 */
	DungeonScene(int stepCount);

	/**
	 * Handles events for the dungeon scene
	 * @param e The event to handle
	 * @return 1 if the event is eaten, 0 otherwise
	 */
	virtual int eventHandler(Event* e);

	/**
	 * Called every frame to draw the scene overlay
	 */
	virtual void draw();

	/**
	 * Gets the number of steps we have made in the dungeon
	 * @return The number of steps we have taken into the dungeon
	 */
	int getSteps() const;

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

	int steps;//the number of steps in the dungeon we have made

	int maxSteps;



	PlayerStatView** statViews;
};

#endif /* DUNGEONSCENE_H_ */
