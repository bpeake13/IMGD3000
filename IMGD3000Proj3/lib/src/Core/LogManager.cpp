/*
 * LogManager.cpp
 *
 *  Created on: Sep 14, 2014
 *      Author: Benny
 */

#include <stdarg.h>

#include "LogManager.h"

LogManager::LogManager()
{
	flush = false;
	logLevel = 0;
	file = NULL;

	startUp();//call startup right away for the log manager
}

LogManager& LogManager::getInstance()
{
	static LogManager log;
	return log;
}

LogManager::~LogManager()
{
	if(file)//if our file is still open then close it to free its resources, this should be done in shutdown though
		fclose(file);
}

int LogManager::startUp()
{
	if(hasStarted())
		return 0;

	Manager::startUp();

	file = fopen(LOG_FILE, "w");

	if(!file)
		return -1;

	writeLog("*Log Started*");

	return 0;
}

void LogManager::shutDown()
{
	if(!hasStarted())
		return;

	Manager::shutDown();

	writeLog("*Log Ended*");

	fclose(file);

	file = NULL;
}

void LogManager::setFlush(bool flush)
{
	this->flush = flush;

	if(flush)
		fflush(file);
}

int LogManager::getLogLevel() const
{
	return logLevel;
}

void LogManager::setLogLevel(int newLogLevel)
{
	logLevel = newLogLevel;
}

int LogManager::writeLog(const char* fmt, ...) const
{
	va_list args;
	va_start(args, fmt);

	int byteCount = 0;
	char* dateTime = getTimeString();
	byteCount = fprintf(file, dateTime);
	byteCount += fprintf(file, "\t");
	byteCount += vfprintf(file, fmt, args);//prints the arguments to the log
	byteCount += fprintf(file, "\n");//print a newline

	if(flush)
		fflush(file);

	va_end(args);

	//delete dateTime;//free the memory for the date time string

	return byteCount;
}

int LogManager::writeLog(int logLevel, const char* fmt, ...) const
{
	if(logLevel < this->logLevel)
		return 0;

	va_list args;
	va_start(args, fmt);

	char* dateTime = getTimeString();
	int byteCount = fprintf(file, dateTime);
	byteCount += fprintf(file, "\n\t");
	byteCount += fprintf(file, fmt, args);//prints the arguments to the log
	byteCount += fprintf(file, "\n");//print a newline

	if(flush)
		fflush(file);

	va_end(args);

	delete dateTime;//free the memory for the date time string

	return byteCount;
}
