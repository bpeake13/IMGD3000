/*
 * Adventurer.h
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#ifndef ADVENTURER_H_
#define ADVENTURER_H_

#include "Creature.h"

class Adventurer: public Creature {
private:
	void death();
	int magic; //Magical attack power

public:
	Adventurer();
	Adventurer(string name, int health, int atk, int mag, string desc);
	virtual ~Adventurer();
	void magicAttack();
	void physicalAttack();
	int getMagic() const;
	void setMagic(int magic);
};

#endif /* ADVENTURER_H_ */
