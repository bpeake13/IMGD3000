/*
 * TextObject.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Benny
 */

#ifndef TEXTOBJECT_H_
#define TEXTOBJECT_H_

#include "ViewObject.h"

/**
 * A view object that does not show its value
 */
class TextObject : public ViewObject
{
public:
	/**
	 * Creates a new TextObject
	 */
	TextObject();

	/**
	 * Gets the string to be rendered
	 * @return The string to render on screen (this does not include the border
	 */
	virtual string getRenderString() const;
};

#endif /* TEXTOBJECT_H_ */
