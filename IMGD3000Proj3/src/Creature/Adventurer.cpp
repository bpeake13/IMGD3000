/*
 * Adventurer.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#include "Adventurer.h"

Adventurer::Adventurer() {}

Adventurer::Adventurer(string na, int h, int a, int m, string d){
	setName(na);
	setHealth(h);
	setAttack(a);
	setMagic(m);
	setDesc(d);
}

Adventurer::~Adventurer() {}

void Adventurer::magicAttack(AttackEvent* e) {
	e->setDamage(this->magic);
	e->setDamageType("magical");
	e->setSender(this);
}

int Adventurer::getMagic() const {
	return magic;
}

void Adventurer::setMagic(int magic) {
	this->magic = magic;
}
