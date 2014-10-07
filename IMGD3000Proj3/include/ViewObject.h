/*
 * ViewObject.h
 *
 *  Created on: Sep 30, 2014
 *      Author: Benny
 */

#ifndef VIEWOBJECT_H_
#define VIEWOBJECT_H_

#include "Object.h"

#include "GraphicsManager.h"

/**
 * The location on the screen
 */
enum ViewObjectLocation {
  TOP_LEFT,     //!< TOP_LEFT
  TOP_CENTER,   //!< TOP_CENTER
  TOP_RIGHT,    //!< TOP_RIGHT
  CENTER_CENTER,//!< CENTER_CENTER
  BOTTOM_LEFT,  //!< BOTTOM_LEFT
  BOTTOM_CENTER,//!< BOTTOM_CENTER
  BOTTOM_RIGHT, //!< BOTTOM_RIGHT
};

class ViewObject : public Object
{
private:
	string viewString;
	int value;
	bool drawBorder;
	ViewObjectLocation location;
	Justification justification;
public:
	ViewObject();

	virtual int eventHandler(Event* e);

	/**
	 * Called every frame when the view object is drawn
	 */
	virtual void draw();

	/**
	 * Get the string to display
	 * @return The string that will be displayed next to the value
	 */
	string getViewString() const;

	/**
	 * Sets the string to display
	 * @param viewString The new string to display next to the value
	 */
	void setViewString(string viewString);

	/**
	 * Get the value to display
	 * @return The value to display
	 */
	int getValue() const;

	/**
	 * Set the value to display
	 * @param value The new value to display
	 */
	void setValue(int value);

	/**
	 * Gets if we are drawing a border on this object
	 * @return True if we are drawing a border, false otherwise
	 */
	bool getDrawBorder() const;

	/**
	 * Sets if we are drawing a border on this object
	 * @param drawBorder If true then a border will be draw, otherwise a border will not be drawn
	 */
	void setDrawBorder(bool drawBorder);

	/**
	 * Gets the justification on the string that is going to be drawn
	 * @return The justification on the string
	 */
	Justification getJustification() const;

	/**
	 * Sets the justification on the string that is being drawn
	 * @param justification The justification on the string being drawn
	 */
	void setJustification(Justification justification);

	/**
	 * Gets the view objects relative location on screen
	 * @return The view objects relative location on screen
	 */
	ViewObjectLocation getViewObjectLocation() const;

	/**
	 * The view objects relative location on screen
	 * @param The view objects relative location on screen
	 */
	void setViewObjectLocation(ViewObjectLocation);

protected:
	/**
	 * Gets the string to be rendered
	 * @return The string to render on screen (this does not include the border
	 */
	virtual string getRenderString() const;
};

#endif /* VIEWOBJECT_H_ */
