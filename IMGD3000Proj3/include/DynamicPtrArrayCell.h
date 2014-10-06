#ifndef DYNAMICPTRARRAYCELL_H_
#define DYNAMICPTRARRAYCELL_H_

#include "DynamicPtrArray.h"

class DynamicPtrArray;

/**
 * A cell of a dynamic array which can hold multiple items
 */
class DynamicPtrArrayCell
{
public:
	/**
	 * Creates a new cell
	 * @param cellSize The number of elements to have in the cell
	 * @param list the owner list of this cell
	 */
	DynamicPtrArrayCell(size_t cellSize, DynamicPtrArrayCell* prev, DynamicPtrArrayCell* next, DynamicPtrArray* list);

	/**
	 * Creates a deep copy of this list
	 * @param other The list to create a copy of
	 */
	DynamicPtrArrayCell(DynamicPtrArrayCell const& other);

	/**
	 * Called when the cell is deleted
	 */
	virtual ~DynamicPtrArrayCell();

	/**
	 * Deep copies a list into another list
	 * @param other The list to copy from
	 * @return The new list that was created
	 */
	DynamicPtrArrayCell& operator=(const DynamicPtrArrayCell& other);

	/**
	 * Gets the ith element in this cell
	 * @param i The index of the element to get
	 */
	void* get(int i);

	/**
	 * Adds an item to the cell if able to
	 * @param data The piece of data to add
	 * @return True if the data was added, false otherwise
	 */
	bool add(void* data);

	/**
	 * Removes an item from the cell
	 * @param data The piece of data to search for to remove
	 * @return True if the data was removed, false otherwise
	 */
	bool remove(void* data);

	/**
	 * Remove an item from the ith index of this cell
	 * @param index The index to remove at
	 * @return True if the index could be removed, false otherwise
	 */
	bool remove(int index);

	/**
	 * Clears the cell and removes it if possible
	 * @return True if the cell was removed, false otherwise
	 */
	bool clear();

	/**
	 * Gets the size of the cell
	 * @return The size of the cell
	 */
	size_t getSize();

private:
	friend class DynamicPtrArray;

	DynamicPtrArrayCell* next;//get the next cell in the array
	DynamicPtrArrayCell* prev;//get the privious cell in the array

	DynamicPtrArray* list;

	void** data;//the data this cell holds

	size_t cellSize;//the number of items this cell can hold
	size_t cellCount;//the number of items this cell is holding
};



#endif
