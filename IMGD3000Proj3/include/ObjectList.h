/*
 * ObjectList.h
 *
 *  Created on: Sep 16, 2014
 *      Author: Benny
 */

#ifndef OBJECTLIST_H_
#define OBJECTLIST_H_

#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

class Object;
class ObjectListIterator;

/**
 * Contains a list of objects
 */
class ObjectList
{
private:
	friend class ObjectListIterator;
	int count;
	int max_count;
	Object** items;
public:
	/**
	 * Creates an empty list with 0 size
	 */
	ObjectList();

	/**
	 * Creates a list
	 * @param maxSize The max number of elements that can be held
	 */
	ObjectList(int maxSize);

	/**
	 * Called when the list is destroyed
	 */
	virtual ~ObjectList();


	/**
	 * Copies one list to another
	 * @param other The other list to copy to
	 */
	ObjectList(const ObjectList& other);

	/**
	 * Sets one list equal to another
	 * @param rhs The list we are setting ourselves to
	 * @return This
	 */
	ObjectList& operator=(const ObjectList&rhs);

	/**
	 * Gets the ith element in the array
	 * @param index The index in the array
	 * @return the ith element
	 */
	Object* operator[](int index) const;

	/**
	 * Adds an object to the list
	 * @param obj The object to add
	 * @return 1 if the object was added, 0 otherwise
	 */
	int add(Object* obj);

	/**
	 * Removes an object from the list
	 * @param obj The object to remove
	 * @return 1 if the object was removed, 0 otherwise
	 */
	int remove(Object* obj);

	/**
	 * Clears all elements out of the array
	 */
	void clear();

	/**
	 * Gets the number of elements in the array
	 * @return The count of elements in the list
	 */
	int getCount() const;

	/**
	 * Checks to see if the list is empty
	 * @return True on empty, false otherwise
	 */
	bool isEmpty() const;

	/**
	 * Checks to see if the list is full
	 * @return True on full, flase otherwise
	 */
	bool isFull() const;

	/**
	 * Checks to see if the list contains an object
	 * @param obj The object to check for
	 * @return True when the list contains obj, false otherwise
	 */
	bool contains(Object* obj) const;

	/**
	 * Appends two lists toghether
	 * @param other The list to add to the end of us
	 * @return The new appended list
	 */
	ObjectList operator +(ObjectList* other);
};

#endif /* OBJECTLIST_H_ */
