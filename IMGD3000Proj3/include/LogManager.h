/*
 * LogManager.h
 *
 *  Created on: Sep 14, 2014
 *      Author: Benny
 */

#ifndef LOGMANAGER_H_
#define LOGMANAGER_H_

#define LOG_FILE "dragonlog.log"

#include <stdio.h>

#include "Manager.h"
#include "Utility.h"

/**
 * Manager for writing info out to the log file
 */
class LogManager : public Manager {
private:
	//overload these to prevent more than one instance being created
	LogManager();
	LogManager (LogManager const&);
	LogManager& operator=(const LogManager& other);

	FILE* file;//the internal system file
	bool flush;//when this is true then the stream will be flushed to file after each write
	int logLevel;//the level of messages to log

public:
	virtual ~LogManager();

	/**
	 * Gets the singleton instance of this object
	 * @return A reference to the log manager
	 */
	static LogManager& getInstance();

	/**
	 * Called when the log manager is started
	 * @return 0 on success, a negative number when there is an error
	 */
	int startUp();

	/**
	 * Called to shutdown the log manager
	 */
	void shutDown();

	/**
	 * Writes a formatted string to the log
	 * @param fmt The string format to use
	 * @return the number of bytes written to the log
	 */
	int writeLog(const char* fmt, ...) const;

	/**
	 * Writes a formatted string to the log if we are at or above the current log level
	 * @param logLevel The log level of this message
	 * @param fmt The string format to use
	 * @return The number of bytes written to the log
	 */
	int writeLog(int logLevel, const char* fmt, ...) const;

	/**
	 * Sets the log level for our logger
	 * @param newLogLevel The new log level to use
	 */
	void setLogLevel(int newLogLevel);

	/**
	 * Gets the current log level of our logger
	 * @return The current log level
	 */
	int getLogLevel() const;

	/**
	 * Sets if this logger should flush to file after each write
	 * @param flush Indicates if we should flush, by default this is true
	 */
	void setFlush(bool flush = true);
};

#endif /* LOGMANAGER_H_ */
