/*
 * InputManager.h
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#ifdef CYGWIN
#include <ncurses/curses.h>
#else
#include <curses.h>
#endif

#include "Manager.h"

/**
 * A singleton class that handles ionput
 */
class InputManager : public Manager
{
private:
	//singleton object, these are not used
	InputManager();
	InputManager (InputManager const&);
	InputManager& operator=(const InputManager& other);

public:

	/**
	 * Get the static instance of this object
	 * @return A reference to the input manager
	 */
	static InputManager& getInstance();

	/**
	 * Called when the input manager is started
	 * @return 0 if ok, otherwise -1
	 */
	int startUp();

	/**
	 * Called when the input manager is shutdown
	 */
	void shutDown();

	/**
	 * Called once per frame to check the input device for events
	 */
	void getInput();
};

#endif /* INPUTMANAGER_H_ */
