/*
 * ObjectListIterator.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: Benny
 */

#include <ObjectListIterator.h>

ObjectListIterator::ObjectListIterator()
{
	index = 0;
	list = NULL;
}

ObjectListIterator::ObjectListIterator(const ObjectList* list)
{
	this->index = 0;
	this->list = list;
}

void ObjectListIterator::first()
{
	index = 0;
}

void ObjectListIterator::next()
{
	index++;
}

bool ObjectListIterator::isDone() const
{
	return index >= list->count;
}

Object* ObjectListIterator::getCurrent() const
{
	return list->items[index];
}

ObjectListIterator& ObjectListIterator::operator =(
		const ObjectListIterator& rhs)
{
	this->index = rhs.index;
	this->list = rhs.list;

	return *this;
}

void ObjectListIterator::setList(const ObjectList* list)
{
	this->list = list;
	index = 0;
}
