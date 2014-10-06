/*
 * Creature.h
 *
 *  Created on: Oct 5, 2014
 *      Author: Eric
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include "Object.h"

class Creature: public Object {
private:
	int health; //How much damage the creature needs to take to be destroyed
	int attack; //The creature's physical attack
	Position pos; //The position on screen
	Sprite spr; //The sprite of the monster


public:
	Creature();
	virtual ~Creature();
};

#endif /* CREATURE_H_ */
