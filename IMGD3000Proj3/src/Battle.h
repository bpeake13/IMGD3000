/*
 * Battle.h
 *
 *  Created on: Oct 7, 2014
 *      Author: Eric
 */

#ifndef BATTLE_H_
#define BATTLE_H_

#include "Scene.h"
#include <string>

class Battle: public Scene {
public:
	Battle();
	virtual ~Battle();
	void setEnemy(std::string name);
};

#endif /* BATTLE_H_ */
