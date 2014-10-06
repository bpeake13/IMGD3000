/*
 * EventMouse.h
 *
 *  Created on: Sep 22, 2014
 *      Author: Benny
 */

#ifndef EVENTMOUSE_H_
#define EVENTMOUSE_H_

#include "Event.h"

#define DF_EVENT_MOUSE "__mouse__"

/**
 * Mouse button types
 */
enum MouseActionList
{
	LEFT_BUTTON_CLICK,       //!< LEFT_BUTTON_CLICK The left mouse button has been clicked once
	LEFT_BUTTON_DOUBLECLICK, //!< LEFT_BUTTON_DOUBLECLICK The left mouse button has been double clicked
	RIGHT_BUTTON_CLICK,      //!< RIGHT_BUTTON_CLICK The right mouse button has been clicked
	RIGHT_BUTTON_DOUBLECLICK,//!< RIGHT_BUTTON_DOUBLECLICK The right mouse button has been double clicked
	UNDEFINED                //!< UNDEFINED An unknown mouse input has been used
};

/**
 * Event sent whenever there is a mouse event
 */
class EventMouse : public Event
{
public:
	/**
	 * Creates a new mouse event
	 * @param x The x location of the mouse
	 * @param y The y location of the mouse
	 * @param action The button or action that the mouse did to trigger this event
	 */
	EventMouse(int x, int y, MouseActionList action);

	/**
	 * Get the x location of the mouse when this event was fired
	 * @return An integer representing the mouse x location
	 */
	int getX() const;

	/**
	 * Get the y location of the mouse when this event was fired
	 * @return An integer representing the mouse y location
	 */
	int getY() const;

	/**
	 * Get the mouse action that was used to trigger this event
	 * @return The mouse action
	 */
	MouseActionList getMouseAction() const;

private:
	int x, y;
	MouseActionList mouseAction;
};

#endif /* EVENTMOUSE_H_ */
