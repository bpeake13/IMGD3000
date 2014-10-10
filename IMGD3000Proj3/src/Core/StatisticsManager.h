/*
 * StatisticsManager.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Eric
 */

#ifndef STATISTICSMANAGER_H_
#define STATISTICSMANAGER_H_

#include "Manager.h"
#include "HashTable.h"
#include "Monster.h"

/**
 * Handles loading of monster statistics
 */
class StatisticsManager: public Manager {
private:
	StatisticsManager();
	StatisticsManager(StatisticsManager const& other);
	StatisticsManager& operator=(const StatisticsManager& other);
	HashTable* statisticsTable;

public:
	/**
	 * Gets the singleton instance of the statistics manager
	 * @return A reference to the statistics manager
	 */
	static StatisticsManager& getInstance();

	/**
	 * Called when the statistics manager is started
	 * @return 0 on ok, -1 otherwise
	 */
	int startUp();

	/**
	 * Called when the statistics manager is shut down
	 */
	void shutDown();

	/**
	 * Loads a monsters statistics
	 * @param file The file to load from
	 * @param label The label to assign to the statistics, generally the monsters name
	 * @return True if loaded, false otherwise
	 */
	bool loadStatistic(string file, string label);

	/**
	 * Unloads a statistics from memory
	 * @param label The label of the statistic
	 * @return True if unloaded, false otherwise
	 */
	bool unloadStatistic(string label);

	/**
	 * Gets a statistic from the table.
	 * The data in the returned monster class should be copied, not used directly.
	 * @param label The lable the statistic was assigned
	 * @return A pointer to a monster class filled with data
	 */
	Monster* getStatistic(string label) const;
};

#endif /* STATISTICSMANAGER_H_ */
