/*
 * StatisticsManager.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Eric
 */

#include "StatisticsManager.h"
#include "LogManager.h"
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
		if(error)
			*error = 1;
		return "";
	}

	string data = line.substr(tagLength + 1);
	data = data.substr(0, data.length() - 1);

	*lineNumber += 1;

	return data;
}


StatisticsManager::StatisticsManager() {}
StatisticsManager::StatisticsManager(const StatisticsManager& other) {}
StatisticsManager& StatisticsManager::operator =(const StatisticsManager& other) {
}

StatisticsManager& StatisticsManager::getInstance() {
	static StatisticsManager sm;
	return sm;
}

int StatisticsManager::startUp() {
	if(hasStarted())
		return 0;

	Manager::startUp();

	this->statisticsTable = new HashTable(BUCKET_COUNT);

	return 0;
}

void StatisticsManager::shutDown() {
	if(!hasStarted())
		return;

	Manager::shutDown();

	delete statisticsTable;
}

bool StatisticsManager::loadStatistic(string file, string label) {
	if(statisticsTable->contains(label))
		return false;

	ifstream fileStream(file.c_str());
	if(!fileStream.good())
		return false;

	int error=0;
	int line=0;

	LogManager &lm = LogManager::getInstance();

	string name = readLineString(&fileStream, &line, "name", &error);
	if(error)
	{
		fileStream.close();
		lm.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	int health = readLineInt(&fileStream, &line, "health", &error);
	if(error)
	{
		fileStream.close();
		lm.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	int attack = readLineInt(&fileStream, &line, "attack", &error);
	if(error)
	{
		fileStream.close();
		lm.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	int reward = readLineInt(&fileStream, &line, "reward", &error);
	if(error)
	{
		fileStream.close();
		lm.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	string desc = readLineString(&fileStream, &line, "desc", &error);
	if(error)
	{
		fileStream.close();
		lm.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	Monster* mon = new Monster(name, health, attack, reward, desc);
	statisticsTable->set(label, mon);

	return true;
}

bool StatisticsManager::unloadStatistic(string label) {
	void* data = statisticsTable->get(label);
	if(!data)//if this sprite doesn't exist on our table then give an error
		return false;

	Monster* mon = static_cast<Monster*>(data);

	statisticsTable->remove(label);

	delete mon;

	return true;
}

Monster* StatisticsManager::getStatistic(string label) const {
	void* data = statisticsTable->get(label);
	if(!data)
		return NULL;

	Monster* mon = static_cast<Monster*>(data);
	return mon;
}
