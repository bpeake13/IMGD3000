/*
 * HashTable.h
 *
 *  Created on: Sep 26, 2014
 *      Author: Benny
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "DynamicPtrArray.h"
#include "Utility.h"

#define DEFAULT_BUCKET_COUNT 16
#define DEFAULT_BUCKET_CELL_SIZE 16

/**
 * Provides a string to ptr hashtable
 * By using a ptr like a base data type you could in theory store any 4-byte or under data
 */
class HashTable
{
public:
	/**
	 * Creates a new hashtable
	 * @param bucketCount The number of buckets to create to store info in
	 */
	HashTable(size_t bucketCount = DEFAULT_BUCKET_COUNT);

	/**
	 * Sets the value to store at a key inside the hash table
	 * @param key The key to use
	 * @param value The value to store at that key
	 * @return The value that was at that key, or if its a new key then NULL
	 */
	void* set(string key, void* value);

	/**
	 * Removes a key from the hashtable
	 * @param key They key to remove
	 * @return The value that was at that key, or NULL if the key wasn't found
	 */
	void* remove(string key);

	/**
	 * Checks to see if the hashtable contains a key
	 * @param key The key to check for
	 * @return True if the key exists, false otherwise
	 */
	bool contains(string key);

	/**
	 * Gets the value stored at the key
	 * @param key The key to get the value at
	 * @return The ptr value at that key, or NULL if the key could not be found
	 */
	void* get(string key);


private:
	size_t getHash(string key);//gets the hash from a key
private:
	DynamicPtrArray** buckets;//dynamic array array for each bucket

	size_t bucketCount;
};

#endif /* HASHTABLE_H_ */
