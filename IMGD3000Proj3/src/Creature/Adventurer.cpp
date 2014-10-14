/*
 * Adventurer.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#include "Adventurer.h"
#include "MathExt.h"

Adventurer::Adventurer() {
	this->magic = 0;
}

Adventurer::Adventurer(string na, int h, int a, int m, string d){
	setName(na);
	setHealth(h);
	setMaxHealth(h);
	setAttack(a);
	this->magic = m;
	setDesc(d);
}

Adventurer::~Adventurer() {}

void Adventurer::magicAttack(AttackEvent* e) {
	e->setDamage(this->magic);
	e->setDamageType("magical");
	e->setSender((Creature *) this);
}

int Adventurer::getMagic() const {
	return magic;
}

void Adventurer::setMagic(int magic) {
	this->magic = magic;
}

int Adventurer::doAttack()
{
	int v = Creature::doAttack();

	if(!Math::randomRange(0, magic + 1))
		damage(health / 10);

	return v;
}
