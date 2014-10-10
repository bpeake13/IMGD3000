/*
 * StatusBar.h
 *
 *  Created on: Oct 6, 2014
 *      Author: Benny
 */

#ifndef STATUSBAR_H_
#define STATUSBAR_H_

#include "ViewObject.h"

/**
 * Renders a value as a bar
 */
class StatusBar : public ViewObject
{
public:

	/**
	 * Creates a new empty status bar
	 */
	StatusBar();

	/**
	 * Creates a new status bar
	 * @param maxValue The max value for the bar
	 */
	StatusBar(int maxValue);

	/**
	 * Sets the max value of the bar
	 */
	void setMaxValue(int mv);

	/**
	 * Returns the max value of the bar
	 * @return The max value of the bar
	 */
	int getMaxValue() const;

protected:
	/**
	 * The string to render to the scene
	 * @return The bar name followed by the bar
	 */
	virtual string getRenderString() const;

private:

	int maxValue;
};

#endif /* STATUSBAR_H_ */
