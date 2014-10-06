/*
 * StringPtrPair.h
 *
 *  Created on: Sep 29, 2014
 *      Author: Benny
 */

#ifndef STRINGPTRPAIR_H_
#define STRINGPTRPAIR_H_

#include "Utility.h"

/**
 * A key value pair that uses strings for the key and pointers for the values
 */
class StringPtrPair
{
public:
	/**
	 * Creates a new key value pair
	 * @param key The key
	 * @param value The value
	 */
	StringPtrPair(string key, void* value);

	/**
	 * Gets the key of this pair
	 * @return A string that is the key for this pair
	 */
	string getKey() const;

	/**
	 * Gets the value for this pair
	 * @return The value in this pair
	 */
	void* getValue() const;

	/**
	 * Changes the value in this key value pair
	 * @param value The new value to set the pair to
	 */
	void setValue(void* value);
private:
	string s;
	void* ptr;
};

#endif /* STRINGPTRPAIR_H_ */
