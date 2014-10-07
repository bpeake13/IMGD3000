/*
 * StatusBar.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Benny
 */

#include "StatusBar.h"

StatusBar::StatusBar(int maxValue) : ViewObject()
{
	this->maxValue = maxValue;
	setValue(maxValue);
}

string StatusBar::getRenderString() const
{
	string s = getViewString() + " [";
	int value = getValue();

	for(int i = 0; i < maxValue; i++)
	{
		if(i < value)
			s += "|";
		else
			s +=  " ";
	}

	s += "]";

	return s;
}
