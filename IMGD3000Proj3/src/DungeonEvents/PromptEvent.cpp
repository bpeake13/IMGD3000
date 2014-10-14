/*
 * PromptEvent.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#include "PromptEvent.h"
#include "PartyManager.h"
#include "EventKeyboard.h"
#include "MathExt.h"
#include "SceneManager.h"
#include "Battle.h"
#include "ObjectListIterator.h"

PromptEvent::PromptEvent() : DungeonEvent(PROBABILITY){
}

void PromptEvent::start(){
	DungeonEvent::start();


	goldlost = Math::randomRange(1,100);
	int partymember = Math::randomRange(0, MAXPARTYSIZE);
	promptnumber = Math::randomRange(1,5);
	switch(promptnumber){
	case 1:
		prompt = "You come across a chasm. Jump the chasm or try to find a way around?";
		accept = "1) Jump";
		reject = "2) Find a way around";
		break;
	case 2:
		prompt = "You come across an old beggar. Do you give him a gold?";
		accept = "1) Give a gold";
		reject = "2) Ignore the beggar";
		break;
	case 3:
		adv = PartyManager::getInstance().getPartyMember("rogue");
		prompt = adv->getName() + " has become lost in the dungeon, do you go back to search for them?";
		accept = "1) Search for them";
		reject = "2) Leave them behind";
		break;
	case 4:
		prompt = "An imp has stolen some of your gold! Chase after him?";
		accept = "1) Search for it";
		reject = "2) Oh well";
		PartyManager::getInstance().addTreasure(-goldlost);
		break;
	case 5:
		prompt = "Do you want to do a thing?";
		accept = "1) Do a thing!";
		reject = "2) Don't do a thing.";
		break;
	default:
		prompt = "Oh no!";
		break;
	}
}

int PromptEvent::eventHandler(Event* e)
{
	string typeName = e->getType();
	if(typeName == DF_EVENT_KEYBOARD)
	{
		EventKeyboard* ek = static_cast<EventKeyboard*>(e);

		if(ek->getKey() == '1' && !madechoice)
		{
			madechoice =true;
			hasAccepted();
			return 1;
		}else if(ek->getKey() == '2' && !madechoice){
			madechoice =true;
			hasRejected();
			return 1;
		}else if(ek->getKey() == ' ' && madechoice){
			setKeyPressed(true);
		}
	}

	return 0;
}

void PromptEvent::hasAccepted(){

	string response;
	int randchance = Math::randomRange(1,100);
	switch(promptnumber){
	case 1:{

		if(randchance <= 10){
			PartyManager &pm = PartyManager::getInstance();
			Adventurer* lost = pm.getPartyMember("rogue");
			response = lost->getName() + " has fallen into the chasm in your jump across";
			pm.removePartyMember(lost);
		}else{
			response = "You successfully jumped the chasm";
		}

		break;
	}
	case 2:{
		if(randchance <= 10){
			response = "He sees that you have more gold, and attacks!";
			Battle* nb = new Battle();
			Monster* nm = new Monster("Old Man", 1,1,1,"A haggard old man, with worn clothes");
			nb->addMonster(nm);
			SceneManager::getInstance().push(nb);
		}else{
			response = "He thanks you and walks off";
		}

		break;
	}
	case 3:
		if(randchance <=20){
			response = "You find them having tea with a delightful fairy.";
		}else if(randchance <=40){
			response = "You find them, only a little bruised";
			adv->setHealth((int)(adv->getHealth() * .75));
		}else if(randchance <=60){
			response = "You find them, hurt and confused.";
			adv->setHealth((int)(adv->getHealth() * .5));
		}else if(randchance <= 70){
			response = "You find them dead.";
			PartyManager &pm = PartyManager::getInstance();
			pm.removePartyMember(adv);
		}else if(randchance <=80){
			response = "The entire party falls into a trap, where you find your companion hurt.";
			PartyManager &pm = PartyManager::getInstance();
			ObjectListIterator oli(pm.getParty());

			for(oli.first(); oli.isDone(); oli.next()){
				Adventurer* tadv = (Adventurer *)oli.getCurrent();
				tadv->setHealth((int)(tadv->getHealth()*.7));
			}
		}
		break;
	case 4:
		if(randchance <= 30){
			response = "You find the imp, and he gives up the gold without a fight";
		}else if(randchance <=60){
			response = "You find the imp but he wont give up the gold!";
			Battle *nb = new Battle();
			Monster *nm = new Monster("Greedy Imp", 50,50,goldlost+10, "A greedy little imp that holds your bag of gold!");
			nb->addMonster(nm);
			SceneManager::getInstance().push(nb);
		}
		break;
	}
}

void PromptEvent::hasRejected(){
	string response;

	switch(promptnumber){
	case 1: {
		int monsterchance = Math::randomRange(1,100);
		if(monsterchance <= 20){
			response = "In your searching, you came across a monster blocking the exit!";
			Battle* nb = new Battle();
			Monster* nm = new Monster("centaur", 100,100,100,"A smelly centaur");
			nb->addMonster(nm);
			SceneManager::getInstance().push(nb);
		}else{
			response = "You found a way around the chasm.";
		}
		break;
	}
	case 2:
		if(Math::randomRange(1,100) <= 30){
			response = "He shouts that you are lying, and attacks!";
			Battle* nb = new Battle();
			Monster* nm = new Monster("Old Man", 100,100,100, "A haggard looking old man");
			nb->addMonster(nm);
			SceneManager::getInstance().push(nb);
		}
			break;
	case 3:
		response = "You leave them behind";
		PartyManager::getInstance().removePartyMember(adv);
		break;
	case 4:
		response = "You forget about the gold and continue on.";
		break;
	}
}
