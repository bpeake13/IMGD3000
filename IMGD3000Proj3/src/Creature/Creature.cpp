/*
 * Creature.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: Eric
 */

#include "Creature.h"
#include "MathExt.h"


Creature::Creature(bool addToWorld) : SpriteObject(addToWorld) {
	//Default values, always remember to set them
	this->name = "Error";
	this->desc = "A confusing, blurry creature with no real definition.";
	this->health = 1;
	this->attack = 1;
	this->maxhealth = 1;
}

Creature::Creature(string na, int h, int a, string d){
	this->name = na;
	this->health = h;
	this->attack = a;
	this->desc = d;
	this->maxhealth = h;
}

Creature::~Creature() {
	// TODO Auto-generated destructor stub
}

int Creature::getAttack() const {
	return attack;
}

void Creature::setAttack(int attack) {
	this->attack = attack;
}

int Creature::getHealth() const {
	return health;
}

void Creature::setHealth(int health) {
	this->health = health;
}

int Creature::getMaxHealth() const{
	return maxhealth;
}

void Creature::setMaxHealth(int newmax){
	this->maxhealth = newmax;
}

const string Creature::getDesc() const {
	return desc;
}

void Creature::setDesc(string desc) {
	this->desc = desc;
}

const string Creature::getName() const {
	return name;
}

void Creature::setName(string name) {
	this->name = name;
}

int Creature::doAttack()
{
	int r = Math::randomRange(attack / 2, attack + 1);
	return Math::clamp(r, 1, attack);
}

void Creature::damage(int damage)
{
	health -= damage;
	if(health <=0){
		health=0;
	}
}

bool Creature::isDead(){
	if(health <= 0){
		return true;
	}

	return false;
}
