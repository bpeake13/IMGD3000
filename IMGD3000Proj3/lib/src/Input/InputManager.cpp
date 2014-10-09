/*
 * InputManager.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#include "InputManager.h"
#include "EventMouse.h"
#include "EventKeybaord.h"
#include "WorldManager.h"

InputManager::InputManager()
{
}

InputManager::InputManager(const InputManager&)
{
}

InputManager& InputManager::operator =(const InputManager& other)
{
	return *this;
}

InputManager& InputManager::getInstance()
{
	static InputManager instance;
	return instance;
}

int InputManager::startUp()
{
	if(hasStarted())
		return 0;

	keypad(stdscr, TRUE);

	//turn off waiting for input
	cbreak();

	nonl();//disable newline so we can read the enter key

	noecho();//disable echo

	curs_set(0);//turn off cursor

	nodelay(stdscr, TRUE);

	mousemask(BUTTON1_CLICKED | BUTTON1_DOUBLE_CLICKED | BUTTON3_CLICKED | BUTTON3_DOUBLE_CLICKED, NULL);

	return Manager::startUp();
}

void InputManager::shutDown()
{
	if(!hasStarted())
		return;



	Manager::shutDown();
}

void InputManager::getInput()
{
	int key = getch();//get the input

	if(key == ERR)
		return;

	MEVENT m_event;
	if(key == KEY_MOUSE && getmouse(&m_event) == OK)//if we have a mouse input, then send a mouse event
	{
		MouseActionList action = UNDEFINED;
		int x = m_event.x;
		int y = m_event.y;

		if(m_event.bstate & BUTTON1_CLICKED)
			action = LEFT_BUTTON_CLICK;
		else if(m_event.bstate & BUTTON2_CLICKED)
			action = RIGHT_BUTTON_CLICK;

		EventMouse e = EventMouse(x, y, action);//create the mouse event to dispatch

		WorldManager& world = WorldManager::getInstance();
		world.onEvent(&e);
	}
	else
	{
		EventKeyboard e = EventKeyboard(key);

		WorldManager& world = WorldManager::getInstance();
		world.onEvent(&e);
	}
}
