/*
 * TextObject.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Benny
 */

#include "TextObject.h"
#include "LogManager.h"

TextObject::TextObject() : ViewObject()
{
	// TODO Auto-generated constructor stub

}

string TextObject::getRenderString() const
{
	return getViewString();
}
