/*
 * StringPtrPair.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: Benny
 */

#include "StringPtrPair.h"

StringPtrPair::StringPtrPair(string key, void* value)
{
	this->s = key;
	this->ptr = value;
}

string StringPtrPair::getKey() const
{
	return s;
}

void* StringPtrPair::getValue() const
{
	return ptr;
}

void StringPtrPair::setValue(void* value)
{
	ptr = value;
}
