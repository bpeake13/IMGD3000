/*
 * DynamicArray.h
 *
 *  Created on: Sep 26, 2014
 *      Author: Benny
 */

#ifndef DYNAMICPTRARRAY_H_
#define DYNAMICPTRARRAY_H_

#include <stdio.h>
#include "DynamicPtrArrayCell.h"

#define DEFAULT_CELL_SIZE 16

class DynamicPtrArrayCell;

/**
 * Provides a class that can expand as new items are added
 */
class DynamicPtrArray
{
public:
	/**
	 * Creates a new array that can be dynamically allocated
	 * @param cellSize The size of each cell
	 */
	DynamicPtrArray(size_t cellSize = DEFAULT_CELL_SIZE);

	/**
	 * Creates a deep copy of another dynamic ptr array
	 * @param cpy The array to copy
	 */
	DynamicPtrArray(const DynamicPtrArray& cpy);

	/**
	 * Called when the dynamic array is deleted
	 */
	virtual ~DynamicPtrArray();

	/**
	 * Adds a piece of data to the array
	 * @param data The data to add
	 * @return True if the data was able to be added, false otherwise
	 */
	bool add(void* data);

	/**
	 * Removes a piece of data from the array
	 * @param data The data to remove
	 * @return True if the data could be removed
	 */
	bool remove(void* data);

	/**
	 * Removes an element at the ith index
	 * @param i The index of the element to remove
	 * @return True if the element was removed, otherwise false
	 */
	bool remove(int i);

	/**
	 * Clears the array
	 * @return True if items could be cleared otherwise false
	 */
	bool clear();

	/**
	 * Get the element at the ith index
	 * @param i The index to get the element at
	 * @remarks When the index is out of range or invalid, NULL will be returned
	 */
	void* get(int i);

	/**
	 * Gets the size of this cell
	 * @return An integer representation of the size size
	 */
	size_t getSize();

private:
	friend class DynamicPtrArrayCell;

	DynamicPtrArrayCell* first;//the first cell in the list
	DynamicPtrArrayCell* last;//the last cell in the list

	size_t length;//the number of elements in the list

	size_t cellSize;
};

#endif
