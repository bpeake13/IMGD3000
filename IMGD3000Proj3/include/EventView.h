/*
 * EventView.h
 *
 *  Created on: Sep 30, 2014
 *      Author: Benny
 */

#ifndef EVENTVIEW_H_
#define EVENTVIEW_H_

#include "Event.h"

/**
 * The type name for EventView
 */
#define DF_VIEW_EVENT "__view__"

/**
 * An event used to modify UI elements
 */
class EventView : public Event
{
private:
	string tag;//the view tag
	int value;//the value to change it to
	bool delta;//indicates if we should increase or just set
public:

	/**
	 * Creates a new view event
	 * @param tag The tag on the UI element that this event should apply to
	 * @param value The value to modify the tag with
	 * @param delta If true then we will add value to the current value of the UI element, if false then we will just set
	 */
	EventView(string tag, int value, bool delta = true);

	/**
	 * Get the tag on this event
	 * @return The tag of the UI object that this event applies to
	 */
	string getTag() const;

	/**
	 * Get the value stored in this event
	 * @return The value to modify the UI element with
	 */
	int getValue() const;

	/**
	 * Check to see if this event should only increment the value of the UI element
	 * @return If true then we will only increment the value, otherwise we will set it
	 */
	bool getDelta() const;
};

#endif /* EVENTVIEW_H_ */
