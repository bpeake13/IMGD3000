/*
 * ObjectListIterator.h
 *
 *  Created on: Sep 16, 2014
 *      Author: Benny
 */

#ifndef OBJECTLISTITERATOR_H_
#define OBJECTLISTITERATOR_H_

#include "ObjectList.h"

class Object;
class ObjectList;

/**
 * Used to iterate through an object list
 */
class ObjectListIterator
{
private:
	ObjectListIterator();

	int index;
	const ObjectList* list;

public:
	/**
	 * Creates a new iterator for a list
	 * @param list The list to create this iterator for
	 */
	ObjectListIterator(const ObjectList* list);

	/**
	 * Moves the iterator to the first element in the list
	 */
	void first();

	/**
	 * Moves the iterator to the next element in the list
	 */
	void next();

	/**
	 * Checks to see if this iterator has been through the entire list
	 * @return True if it has, false otherwise
	 */
	bool isDone() const;

	/**
	 * Gets the current element this iterator is on
	 * @return
	 */
	Object* getCurrent() const;

	/**
	 * Sets one iterator equal to another
	 * @param rhs The iterator to copy
	 * @return This
	 */
	ObjectListIterator &operator=(const ObjectListIterator &rhs);

	/**
	 * Set the list this iterator uses
	 * @param list The list this iterator uses
	 */
	void setList(const ObjectList* list);
};

#endif /* OBJECTLISTITERATOR_H_ */
