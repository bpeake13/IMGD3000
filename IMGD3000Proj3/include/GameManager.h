/*
 * GameManager.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Manager.h"
#include "LogManager.h"
#include "GraphicsManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "InputManager.h"

class WorldManager;

/**
 * The default time between frames
 */
#define DEFAULT_FRAME_TIME 33

/**
 *Handles game management
 */
class GameManager : public Manager
{
private://singleton
	GameManager();
	GameManager (GameManager const& other);
	GameManager& operator=(const GameManager& other);

public:
	/**
	 * Gets the game manager instance
	 * @return A reference to the game manager instance
	 */
	static GameManager& getInstance();

	/**
	 * Called when the game manager is started
	 * @return 0 when no errors occur, < 0 when an error does occur
	 */
	int startUp();

	/**
	 * Called when the game manager shuts down
	 */
	void shutDown();

	/**
	 * Runs the main game loop
	 * @param frameTime The fixed time to have between frames
	 */
	void run(unsigned int frameTime = DEFAULT_FRAME_TIME);

	/**
	 * Set the game over flag in the game
	 * @param gameOver The value to set the game over flag to
	 */
	void setGameOver(bool gameOver = true);

	/**
	 * Gets the value of the game over flag
	 * @return The value of the game over flag
	 */
	bool isGameOver() const;

	/**
	 * Gets the time between frames
	 * @return An unsigned integer showing the time between frames in milliseconds
	 */
	unsigned int getFrameTime() const;

	unsigned int getTickCount() const;

private:
	unsigned int frameTime;//the time in milliseconds between frames

	bool bIsGameOver;//flag for game over

	LogManager& log;
	GraphicsManager& graphics;
	ResourceManager& resources;
	InputManager& input;
	WorldManager& world;

	unsigned int tickCount;
};

#endif /* GAMEMANAGER_H_ */
