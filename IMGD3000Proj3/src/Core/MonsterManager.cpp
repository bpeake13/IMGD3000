/*
 * MonsterManager.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#include "GraphicsManager.h"
#include "MonsterManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "Utility.h"

#include "MathExt.h"

#include <iostream>
#include <fstream>
#include <typeinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

#define BUCKET_COUNT 128

int readLineInt(ifstream* file, int* lineNumber, const char* tag, int* error = NULL)
{
	if(error)
		*error = 0;

	string line;
	getline(*file, line);//read the line from file

	size_t tagLength = strlen(tag);

	string testToken = line.substr(0, tagLength);
	if(testToken.compare(tag) != 0)//compare the tokens, if they are not the same then give an error
	{
		if(error)
			*error = 1;
		return -1;
	}

	string data = line.substr(tagLength);
	int i = atoi(data.c_str());//read the data from the line

	*lineNumber += 1;//increase the line count

	return i;
}

string readLineString(ifstream* file, int* lineNumber, const char* tag, int* error = NULL)
{
	if(error)
		*error = 0;

	string line;
	getline(*file, line);//read the line from file

	size_t tagLength = strlen(tag);

	string testToken = line.substr(0, tagLength);
	if(testToken.compare(tag) != 0)//compare the tokens, if they are not the same then give an error
	{
		LogManager::getInstance().writeLog("Looking for '%s' found '%s'", tag, testToken.c_str());
		if(error)
			*error = 1;
		return "";
	}

	string data = line.substr(tagLength + 1);
	data = data.substr(0, data.length() - 1);

	*lineNumber += 1;

	return data;
}

MonsterManager& MonsterManager::getInstance() {
	static MonsterManager instance;
	return instance;
}

int MonsterManager::startUp(){
	if(hasStarted()){
		return 0;
	}

	keycount=0;
	Manager::startUp();
	this->resourceTable = new HashTable(BUCKET_COUNT);


	loadMonster("monsters/stat-centaur.txt", "sprites/mon-centaur-spr.txt", "centaur", COLOR_YELLOW);
	loadMonster("monsters/stat-statue.txt", "sprites/mon-statue-spr.txt", "statue");
	loadMonster("monsters/stat-werewolf.txt", "sprites/mon-werewolf-spr.txt", "werewolf");
	loadMonster("monsters/stat-imp.txt", "sprites/mon-imp-spr.txt", "imp", COLOR_RED);
	loadMonster("monsters/stat-slime.txt", "sprites/mon-slime-spr.txt", "slime", COLOR_BLUE);
	loadMonster("monsters/stat-advslime.txt", "sprites/mon-slime-spr.txt", "advslime", COLOR_MAGENTA);
	loadMonster("monsters/stat-satyr.txt", "sprites/mon-satyr-spr.txt", "satyr", COLOR_YELLOW);
	loadMonster("monsters/stat-dragon.txt", "sprites/mon-dragon-spr.txt", "dragon", COLOR_GREEN);

	return 0;
}

void MonsterManager::shutDown() {
	if(!hasStarted())
		return;

	Manager::shutDown();
	delete resourceTable;
}

bool MonsterManager::loadMonster(string file, string sprite, string label, int color) {
	if(resourceTable->contains(label))
		return false;

	//Too many monsters already loaded
	if(keycount+1 >= MAXLOADEDMONSTERS){
		return false;
	}

	ifstream fileStream(file.c_str());

	int error = 0;
	int line = 0;

	LogManager& log = LogManager::getInstance();

	string name = readLineString(&fileStream, &line, "name", &error);
	if(error)
	{
		fileStream.close();
		log.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	int health = readLineInt(&fileStream, &line, "health", &error);
	if(error)
	{
		fileStream.close();
		log.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	int attack = readLineInt(&fileStream, &line, "attack", &error);
	if(error)
	{
		fileStream.close();
		log.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	int reward = readLineInt(&fileStream, &line, "reward", &error);
	if(error)
	{
		fileStream.close();
		log.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	string desc = readLineString(&fileStream, &line, "description", &error);
	if(error)
	{
		fileStream.close();
		log.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	string eofLine;
	getline(fileStream, eofLine);
	eofLine = eofLine.substr(0, eofLine.length() - 1);
	if(eofLine != "eof")
	{
		log.writeLog("ERROR: No eof in monster stat");
		return false;
	}

	Monster *newMon = new Monster(name, health, attack, reward, desc);
	ResourceManager &rm = ResourceManager::getInstance();
	newMon->setColor(color);
	if(rm.loadSprite(sprite, label)){

		newMon->setSprite(rm.getSprite(label));
	}else{
		return false;
	}
	resourceTable->set(label, newMon);

	keys[keycount] = label;
	keycount++;

	LogManager::getInstance().writeLog("Loaded %s successfully", label.c_str());
	return true;
}

bool MonsterManager::unloadMonster(string label) {
	void* data = resourceTable->get(label);
	if(!data)//if this monster doesn't exist on our table then give an error
		return false;

	Monster* mon = static_cast<Monster*>(data);

	resourceTable->remove(label);

	delete mon;

	//Remove the label from keys, and shift array
	for(int i=0; i<keycount; i++){
		if(keys[i] == label){
			for(int j=i; j<keycount-1; j++){
				keys[j] = keys[j+1];
			}
		}
	}

	keycount--;

	return true;
}

Monster* MonsterManager::getMonster(string label){
	void* data = resourceTable->get(label);
	if(!data)//if this monster doesn't exist on our table then give an error
		return false;

	Monster* mon = static_cast<Monster*>(data);

	Monster* returnmon  = new Monster(mon->getName(), mon->getHealth(), mon->getAttack(), mon->getReward(), mon->getDesc());
	returnmon->setColor(mon->getColor());
	returnmon->setSprite(mon->getSprite());
	WorldManager &wm = WorldManager::getInstance();
	wm.addObject(returnmon);
	return returnmon;
}

Monster* MonsterManager::randomMonster(){
	int r = Math::randomRange(0, keycount);

	string key = keys[r];
	LogManager &lm = LogManager::getInstance();
	lm.writeLog("0-%d, chose %d -> %s", keycount, r, key.c_str());
	return getMonster(key);
}

MonsterManager::MonsterManager() {
	this->keycount = 0;
	this->resourceTable = NULL;
}

MonsterManager::MonsterManager(const MonsterManager&) {
	this->keycount = 0;
	this->resourceTable = NULL;
}

MonsterManager& MonsterManager::operator =(const MonsterManager& other) {
	this->resourceTable = NULL;
}
