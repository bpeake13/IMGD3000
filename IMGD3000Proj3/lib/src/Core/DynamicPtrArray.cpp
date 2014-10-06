#include "DynamicPtrArray.h"

DynamicPtrArray::DynamicPtrArray(size_t cellSize)
{
	this->length = 0;
	this->cellSize = cellSize;

	this->first = new DynamicPtrArrayCell(cellSize, NULL, NULL, this);
	this->last = this->first;
}

DynamicPtrArray::DynamicPtrArray(const DynamicPtrArray& cpy)
{
	this->length = cpy.length;
	this->cellSize = cpy.cellSize;

	DynamicPtrArrayCell* cell = cpy.first;
	this->first = new DynamicPtrArrayCell(*cell);
	DynamicPtrArrayCell* cpyCell = this->first;

	while(cell->next)
	{
		DynamicPtrArrayCell* newNext = new DynamicPtrArrayCell(*(cell->next));
		cpyCell->next = newNext;
		newNext->prev = cpyCell;

		cell = cell->next;
	}

	this->last = cpyCell;
}

DynamicPtrArray::~DynamicPtrArray()
{
	DynamicPtrArrayCell* cell = first;
	while(cell)
	{
		DynamicPtrArrayCell* next = cell->next;
		delete cell;
		cell = next;
	}
}

bool DynamicPtrArray::add(void* data)
{
	if(!last->add(data))
	{
		last->next = new DynamicPtrArrayCell(cellSize, last, NULL, this);
		last = last->next;

		if(last->add(data))
		{
			length++;
			return true;
		}

		return false;
	}

	length++;

	return true;
}

bool DynamicPtrArray::remove(void* data)
{
	if(first->remove(data))
	{
		length -= 1;
		return true;
	}


	return false;
}

bool DynamicPtrArray::remove(int i)
{
	DynamicPtrArrayCell* cell = first;
	while(cell && i >= cell->cellCount)
	{
		i -= cell->cellCount;
		cell = cell->next;
	}

	if(!cell)
		return false;

	if(cell->remove(i))
	{
		length -= 1;
		return true;
	}

	return false;
}

bool DynamicPtrArray::clear()
{
	DynamicPtrArrayCell* cell = first;
	while(cell)
	{
		DynamicPtrArrayCell* next = cell->next;
		cell->clear();
		cell = next;
	}

	return true;
}

size_t DynamicPtrArray::getSize()
{
	return length;
}

void* DynamicPtrArray::get(int i)
{
	DynamicPtrArrayCell* cell = first;
	while(cell && i >= cell->cellCount)
	{
		i -= cell->cellCount;
		cell = cell->next;
	}

	if(!cell)
		return NULL;

	return cell->get(i);
}

