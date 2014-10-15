/*
 * MonsterManager.h
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#ifndef MONSTERMANAGER_H_
#define MONSTERMANAGER_H_

#include "Manager.h"
#include "HashTable.h"
#include "Monster.h"

#include "DynamicPtrArray.h"

#define MAXLOADEDMONSTERS 100

class MonsterManager: public Manager {
public:
	string keys[MAXLOADEDMONSTERS];
	int keycount;
	static MonsterManager& getInstance();
	int startUp();
	void shutDown();
	bool loadMonster(string file, string sprite, string label);
	bool unloadMonster(string label);
	Monster* getMonster(string label) const;
	Monster* randomMonster() const;

private:
	HashTable* resourceTable;
	MonsterManager();
	MonsterManager(MonsterManager const&);
	MonsterManager& operator=(const MonsterManager& other);
};

#endif /* MONSTERMANAGER_H_ */
