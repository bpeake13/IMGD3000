#include "DynamicPtrArrayCell.h"

#include <stdio.h>

DynamicPtrArrayCell::DynamicPtrArrayCell(size_t cellSize, DynamicPtrArrayCell* prev, DynamicPtrArrayCell* next, DynamicPtrArray* list)
{
	this->next = next;
	this->prev = prev;

	if(this->next)
		this->next->prev = this;

	if(this->prev)
		this->prev->next = this;

	this->cellSize = cellSize;
	this->list = list;

	this->data = new void*[cellSize];//create an array of pointers

	this->cellCount = 0;
}

DynamicPtrArrayCell::DynamicPtrArrayCell(const DynamicPtrArrayCell& other)
{
	//if we are a copied cell, then we do not know what list we are a part of
	this->next = NULL;
	this->prev = NULL;
	this->list = NULL;

	this->cellSize = other.cellSize;
	this->cellCount = other.cellCount;

	this->data = new void*[cellSize];

	for(int i = 0; i < cellCount; i++)
	{
		data[i] = other.data[i];
	}
}

DynamicPtrArrayCell::~DynamicPtrArrayCell()
{
	delete[] data;//deletes the void** of this cell, not the actual data, the data will be retained in case other sources are still using it
}

DynamicPtrArrayCell& DynamicPtrArrayCell::operator =(
		const DynamicPtrArrayCell& other)
{
	//if we are a copied cell, then we do not know what list we are a part of
	this->next = NULL;
	this->prev = NULL;
	this->list = NULL;

	this->cellSize = other.cellSize;
	this->cellCount = other.cellCount;

	this->data = new void*[cellSize];

	for(int i = 0; i < cellCount; i++)
	{
		data[i] = other.data[i];
	}

	return *this;
}

void* DynamicPtrArrayCell::get(int i)
{
	if(i >= cellCount)//if we are outside of this cell then check the next
	{
		if(next)
			return next->get(i - cellCount);
		else//when there is no next cell just return NULL
			return NULL;
	}

	return data[i];
}

bool DynamicPtrArrayCell::add(void* data)
{
	if(cellCount >= cellSize)
	{
		if(next)
			return next->add(data);
		else
			return false;
	}

	this->data[cellCount] = data;
	cellCount++;

	return true;
}

bool DynamicPtrArrayCell::remove(void* data)
{
	void** ptr = this->data;
	for(int i = 0; i < cellCount; i++, ptr++)
	{
		if(*ptr == data)
			return remove(i);
	}

	if(!next)
		return false;
	else
		return next->remove(data);
}

bool DynamicPtrArrayCell::remove(int index)
{
	if(index >= cellCount)
	{
		if(next)
			return next->remove(index - cellCount);
		else
			return false;
	}

	for(int i = index + 1; i < cellCount; i++)
	{
		data[i - 1] = data[i];
	}

	cellCount--;

	if(cellCount == 0)
	{
		clear();
	}

	return true;
}

bool DynamicPtrArrayCell::clear()
{
	cellCount = 0;//set our count to zero

	bool isFirst = list->first == this;
	bool isLast = list->last == this;

	if(isFirst && isLast)//if we are both the first and last cell then do not delete
		return false;

	if(next)
		next->prev = prev;
	if(prev)
		prev->next = next;

	if(isFirst)
		list->first = next;
	else if(isLast)
		list->last = prev;

	delete this;//SELF DESTRUCT!!!!

	return true;
}

size_t DynamicPtrArrayCell::getSize()
{
	return cellCount;
}

