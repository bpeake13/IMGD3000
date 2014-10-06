/*
 * ObjectList.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: Benny
 */

#include "ObjectList.h"
#include "LogManager.h"

ObjectList::ObjectList()
{
	this->max_count = 0;
	this->items = NULL;
	this->count = 0;
}

ObjectList::ObjectList(int maxSize)
{
	this->max_count = maxSize;
	this->items = new Object*[maxSize];
	this->count = 0;
}

ObjectList::~ObjectList()
{
	delete[] items;
}

ObjectList::ObjectList(const ObjectList& other)
{
	this->count = other.count;
	this->max_count = other.max_count;
	this->items = new Object*[max_count];

	int i;
	Object** itemT;
	Object** itemO;
	for(i = 0, itemT = items, itemO = other.items; i < count; i++, itemT++, itemO++)
	{
		*itemT = *itemO;
	}
}

ObjectList& ObjectList::operator =(const ObjectList& rhs)
{
	this->count = rhs.count;
	this->max_count = rhs.max_count;
	this->items = new Object*[max_count];

	int i;
	Object** itemT;
	Object** itemO;
	for(i = 0, itemT = items, itemO = rhs.items; i < count; i++, itemT++, itemO++)
	{
		*itemT = *itemO;
	}

	return *this;
}

Object* ObjectList::operator [](int index) const
{
	if(index < count)
		return items[index];
	return NULL;
}

int ObjectList::add(Object* obj)
{
	if(!isFull())
	{
		items[count] = obj;
		count++;
		return 1;
	}
	else
		return 0;
}

int ObjectList::remove(Object* obj)
{
	bool found = false;
	int i;
	Object** ptr;
	for(i = 0, ptr = items; i < count; ptr++, i++)
	{
		if(*ptr == obj)
		{
			found = true;
			break;
		}
	}

	if(!found)
		return 0;

	for(int j = i + 1; j < count; j++)
	{
		items[j - 1] = items[j];
	}

	count--;
	return 1;
}

void ObjectList::clear()
{
	count = 0;
}

int ObjectList::getCount() const
{
	return count;
}

bool ObjectList::isEmpty() const
{
	return count == 0;
}

bool ObjectList::isFull() const
{
	return count == max_count;
}

bool ObjectList::contains(Object* obj) const
{
	Object** start = items;
	for(int i = 0; i < count; i++, start++)
	{
		if(*start == obj)
			return true;
	}

	return false;
}

ObjectList ObjectList::operator +(ObjectList* other)
{
	ObjectList newList = ObjectList(max_count);

	Object** start = newList.items;
	for(int i = 0; i < count; i++, start++)
	{
		*start = items[i];
	}

	for(int i = 0; i < other->count; i++)
	{
		*start = other->items[i];
	}

	return newList;
}
