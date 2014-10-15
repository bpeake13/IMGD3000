/*
 * MonsterManager.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#include "MonsterManager.h"
#include "LogManager.h"
#include "Utility.h"

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
	return 0;
}

void MonsterManager::shutDown() {
	if(!hasStarted())
		return;

	Manager::shutDown();
	delete resourceTable;
}

bool MonsterManager::loadMonster(string file, string label) {
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

	Monster *newMon = new Monster(name, health, attack, reward, desc);
	resourceTable->set(label, newMon);

	keys[keycount] = label;
	keycount++;
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
	for(int i=0; i<=keycount; i++){
		if(keys[i] == label){
			for(int j=i; j<=keycount-1; j++){
				keys[j] = keys[j+1];
			}
		}
	}

	keycount--;

	return true;
}

Monster* MonsterManager::getMonster(string label) const {
	void* data = resourceTable->get(label);
	if(!data)//if this monster doesn't exist on our table then give an error
		return false;

	Monster* mon = static_cast<Monster*>(data);
	return mon;
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
