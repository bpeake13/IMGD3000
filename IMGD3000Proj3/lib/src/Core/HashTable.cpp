/*
 * HashTable.cpp
 *
 *  Created on: Sep 26, 2014
 *      Author: Benny
 */

#include "HashTable.h"
#include "StringPtrPair.h"

HashTable::HashTable(size_t bucketCount)
{
	this->bucketCount = bucketCount;
	this->buckets = new DynamicPtrArray*[bucketCount];

	for(int i = 0; i < bucketCount; i++)
	{
		buckets[i] = new DynamicPtrArray(DEFAULT_BUCKET_CELL_SIZE);
	}
}

void* HashTable::set(string key, void* value)
{
	size_t hash = getHash(key);

	DynamicPtrArray* bucket = *(buckets + hash);//get the correct bucket
	size_t bucketSize = bucket->getSize();

	for(int i = 0; i < bucketSize; i++)//search the bucket to see if the pair already exists
	{
		StringPtrPair* pair = static_cast<StringPtrPair*>(bucket->get(i));

		if(pair->getKey() == key)//if it does then put in the new value
		{
			void* old = pair->getValue();
			pair->setValue(value);
			return old;
		}
	}

	StringPtrPair* newPair = new StringPtrPair(key, value);//if it doesn't then add the pair to the bucket
	bucket->add(newPair);

	return NULL;
}

void* HashTable::remove(string key)
{
	size_t hash = getHash(key);

	DynamicPtrArray* bucket = *(buckets + hash);//get the bucket to use
	size_t bucketSize = bucket->getSize();

	for(int i = 0; i < bucketSize; i++)
	{
		StringPtrPair* pair = static_cast<StringPtrPair*>(bucket->get(i));

		if(pair->getKey() == key)
		{
			void* value = pair->getValue();
			bucket->remove(i);
			delete pair;//delete the pair to prevent memory leaks
			return value;
		}
	}

	return NULL;
}

bool HashTable::contains(string key)
{
	size_t hash = getHash(key);

	DynamicPtrArray* bucket = *(buckets + hash);//get the bucket to use
	size_t bucketSize = bucket->getSize();

	for(int i = 0; i < bucketSize; i++)
	{
		StringPtrPair* pair = static_cast<StringPtrPair*>(bucket->get(i));

		if(pair->getKey() == key)
			return true;
	}

	return false;
}

void* HashTable::get(string key)
{
	size_t hash = getHash(key);

	DynamicPtrArray* bucket = *(buckets + hash);//get the bucket to use
	size_t bucketSize = bucket->getSize();

	for(int i = 0; i < bucketSize; i++)
	{
		StringPtrPair* pair = static_cast<StringPtrPair*>(bucket->get(i));

		if(pair->getKey() == key)
		{
			void* value = pair->getValue();
			return value;
		}
	}

	return NULL;
}

size_t HashTable::getHash(string key)
{
	size_t keyLength = key.length();

	size_t sum = 0;
	for(int i = 0; i < keyLength; i++)
	{
		unsigned char c = key[i];
		sum += c;
	}

	return sum % bucketCount;
}
