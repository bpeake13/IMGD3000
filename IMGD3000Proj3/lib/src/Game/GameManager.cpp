/*
 * GameManager.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#include "GameManager.h"
#include "Clock.h"

GameManager::GameManager() : log(LogManager::getInstance()),
	graphics(GraphicsManager::getInstance()),
	resources(ResourceManager::getInstance()),
	input(InputManager::getInstance()),
	world(WorldManager::getInstance())
{
	frameTime = DEFAULT_FRAME_TIME;
	tickCount = 0;
	bIsGameOver = false;
}

GameManager& GameManager::getInstance()
{
	static GameManager gm;
	return gm;
}

int GameManager::startUp()
{
	if(hasStarted())
		return 0;

	Manager::startUp();

	LogManager& log = LogManager::getInstance();
	log.writeLog("STATING GAME MANAGER");

	if(graphics.startUp())
		return -1;
	else if(input.startUp())
		return -2;
	else if(resources.startUp())
		return -3;
	else if(world.startUp())
		return -4;

	return 0;//no errors, give back 0
}

void GameManager::shutDown()
{
	if(!hasStarted())
		return;

	log.writeLog("SHUTTING DOWN");

	Manager::shutDown();

	world.shutDown();
	graphics.shutDown();
	input.shutDown();
	resources.shutDown();
}

void GameManager::run(unsigned int frameTime)
{
	this->frameTime = frameTime;

	Clock clock;//create the clock for timing
	long int nanoFrameTime = frameTime * 1000000;
	while(!bIsGameOver)//main loop
	{
		clock.delta();//set the clock

		input.getInput();//get the input from devices

		world.update();//update the world

		LogManager& log = LogManager::getInstance();

		world.draw();//draw the world

		graphics.swapBuffer(true);//swap the back buffer to the screen

		long int deltaTime = clock.split();//check the change in time
		if(deltaTime < nanoFrameTime)
		{
			timespec t;
			t.tv_sec = 0;
			t.tv_nsec = nanoFrameTime - deltaTime;
			nanosleep(&t, NULL);
		}

		tickCount++;
	}
}

void GameManager::setGameOver(bool gameOver)
{
	bIsGameOver = gameOver;
}

bool GameManager::isGameOver() const
{
	return bIsGameOver;
}

unsigned int GameManager::getFrameTime() const
{
	return frameTime;
}

unsigned int GameManager::getTickCount() const
{
	return tickCount;
}

GameManager::GameManager(const GameManager& other) : log(LogManager::getInstance()),
		graphics(GraphicsManager::getInstance()),
		resources(ResourceManager::getInstance()),
		input(InputManager::getInstance()),
		world(WorldManager::getInstance())
{
	frameTime = 0;
	bIsGameOver = false;
	tickCount = 0;
}

GameManager& GameManager::operator =(const GameManager& other)
{
	return *this;
}
