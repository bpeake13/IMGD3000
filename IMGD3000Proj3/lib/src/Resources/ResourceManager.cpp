/*
 * ResourceManager.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: Benny
 */

#include <iostream>
#include <fstream>
#include <typeinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "ResourceManager.h"
#include "LogManager.h"
#include "Utility.h"

#define BUCKET_COUNT 128

using namespace std;

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

Frame* readFrame(ifstream* file, int* lineNumber, int width, int height, int* error = NULL)
{
	string line, frame;

	for(int i = 0; i < height; i++)
	{
		getline(*file, line);//read the line from file
		line = line.substr(0, line.length() - 1);

		if(line.length() != width)
		{
			if(error)
				*error = 1;
			return NULL;
		}

		frame += line;
		*lineNumber += 1;
	}

	getline(*file, line);
	line = line.substr(0, line.length() - 1);
	if(line != "end")
	{
		if(error)
			*error = 1;
		return NULL;
	}

	Frame* newFrame = new Frame(width, height, frame);

	if(error)
		*error = 0;

	return newFrame;
}

ResourceManager::ResourceManager()
{
	this->resourceTable = NULL;
}

ResourceManager::ResourceManager(const ResourceManager&)
{
	this->resourceTable = NULL;
}

ResourceManager& ResourceManager::operator =(const ResourceManager& other)
{
	this->resourceTable = NULL;

	return *this;
}

ResourceManager& ResourceManager::getInstance()
{
	static ResourceManager instance;
	return instance;
}

int ResourceManager::startUp()
{
	if(hasStarted())
		return 0;

	Manager::startUp();

	this->resourceTable = new HashTable(BUCKET_COUNT);

	return 0;
}

void ResourceManager::shutDown()
{
	if(!hasStarted())
		return;

	Manager::shutDown();

	delete resourceTable;
}

bool ResourceManager::loadSprite(string file, string label)
{
	if(resourceTable->contains(label))
		return false;

	ifstream fileStream(file.c_str());

	int error = 0;
	int line = 0;

	LogManager& log = LogManager::getInstance();

	int frameCount = readLineInt(&fileStream, &line, "frames", &error);
	if(error)
	{
		fileStream.close();
		log.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	int width = readLineInt(&fileStream, &line, "width", &error);
	if(error)
	{
		fileStream.close();
		log.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	int height = readLineInt(&fileStream, &line, "height", &error);
	if(error)
	{
		fileStream.close();
		log.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	string color = readLineString(&fileStream, &line, "color", &error);
	if(error)
	{
		fileStream.close();
		log.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
		return false;
	}

	Sprite* newSprite = new Sprite(label, frameCount);
	newSprite->setWidth(width);
	newSprite->setHeight(height);
	for(int i = 0; i < frameCount; i++)//read every frame into file
	{
		Frame* f = readFrame(&fileStream, &line, width, height, &error);

		if(error)//if we encounter an error then cleanup and write out to the log
		{
			fileStream.close();
			delete f;
			delete newSprite;
			log.writeLog("ERROR: Could not load %s. Error at line %d", file.c_str(), line);
			return false;
		}

		newSprite->addFrame(f);
	}

	string eofLine;
	getline(fileStream, eofLine);
	eofLine = eofLine.substr(0, eofLine.length() - 1);
	if(eofLine != "eof")
	{
		delete newSprite;
		log.writeLog("ERROR: No eof");
		return false;
	}

	resourceTable->set(label, newSprite);

	return true;
}

bool ResourceManager::unloadSprite(string label)
{
	void* data = resourceTable->get(label);
	if(!data)//if this sprite doesn't exist on our table then give an error
		return false;

	Sprite* sprite = static_cast<Sprite*>(data);

	resourceTable->remove(label);

	delete sprite;

	return true;
}

Sprite* ResourceManager::getSprite(string label) const
{
	void* data = resourceTable->get(label);
	if(!data)
		return NULL;

	Sprite* sprite = static_cast<Sprite*>(data);
	return sprite;
}
