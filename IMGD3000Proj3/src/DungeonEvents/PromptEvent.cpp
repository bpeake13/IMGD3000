/*
 * PromptEvent.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Eric
 */

#include "LogManager.h"
#include "MonsterManager.h"
#include "PromptEvent.h"
#include "PartyManager.h"
#include "EventKeyboard.h"
#include "MathExt.h"
#include "SceneManager.h"
#include "Battle.h"
#include "ObjectListIterator.h"

PromptEvent::PromptEvent() : DungeonEvent(0.4){
	promptnumber = 0;
	madechoice =false;
	goldlost = 0;
	advnum = 0;

	IVector npos(50, 50);
	acceptText.setPosition(npos);
	rejectText.setPosition(npos);
}

PromptEvent::~PromptEvent(){
	delete &rejectText;
	delete &acceptText;
}

void PromptEvent::start(){
	DungeonEvent::start();

	PartyManager &pm = PartyManager::getInstance();
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
		prompt = "You come across an old beggar that politely asks for some gold. Do you give him a gold?";
		accept = "1) Give a gold";
		reject = "2) Ignore the thing";
		break;
	case 3:
		advnum = Math::randomRange(0,4);
		prompt = pm.getPartyMember(advnum)->getName() + " has become lost in the dungeon, do you go back to search for them?";
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
		prompt = "You're bored, do you want to do a thing?";
		accept = "1) Do a thing!";
		reject = "2) Don't do a thing.";
		break;
	default:
		prompt = "Oh no!";
		accept = "1) OH NO!";
		reject = "2) OH YEAAAAH!";
		break;
	}

	setViewString(prompt);
	acceptText.setViewString(accept);
	IVector accpos(getPosition().getX(), getPosition().getY()+3);
	acceptText.setPosition(accpos);

	rejectText.setViewString(reject);
	IVector rejpos(accpos.getX(), accpos.getY()+3);
	acceptText.setPosition(rejpos);

	IVector promptPos = this->getPosition();
	IVector acceptPos(promptPos.getX(), promptPos.getY() +28);
	acceptText.setPosition(acceptPos);
	IVector rejectPos(acceptPos.getX(), acceptPos.getY()+10);
	rejectText.setPosition(rejectPos);
}



int PromptEvent::eventHandler(Event* e)
{
	DungeonEvent::eventHandler(e);

	string typeName = e->getType();
	if(typeName == DF_EVENT_KEYBOARD)
	{
		EventKeyboard* ek = static_cast<EventKeyboard*>(e);

		if(ek->getKey() == '1' && !madechoice)
		{
			madechoice =true;
			rejectText.setViewString("");
			acceptText.setViewString("");

			hasAccepted();
			return 1;
		}else if(ek->getKey() == '2' && !madechoice){
			madechoice =true;
			rejectText.setViewString("");
			acceptText.setViewString("");

			hasRejected();
			return 1;
		}else if(ek->getKey() == ' ' && madechoice){
			setKeyPressed(true);
		}
	}

	return 0;
}

void PromptEvent::hasAccepted(){
	PartyManager &pm = PartyManager::getInstance();
	string response;
	int randchance = Math::randomRange(1,100);
	switch(promptnumber){
	case 1:{

		if(randchance <= 10){
			PartyManager &pm = PartyManager::getInstance();

			int pnum = Math::randomRange(0,4);

			response = pm.getPartyMember(pnum)->getName() + " has fallen into the chasm in your jump across";
			pm.removePartyMember(pm.getPartyMember(pnum));
		}else{
			response = "You successfully jumped the chasm";
		}

		break;
	}
	case 2:{
		if(randchance <= 10){
			response = "He sees that you have more gold, and transforms into a monster!";
			Battle* nb = new Battle();
			nb->addMonster(MonsterManager::getInstance().randomMonster());
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
			pm.getPartyMember(advnum)->setHealth((int)(pm.getPartyMember(advnum)->getHealth() * .75));
		}else if(randchance <=60){
			response = "You find them, hurt and confused.";
			pm.getPartyMember(advnum)->setHealth((int)(pm.getPartyMember(advnum)->getHealth() * .50));
		}else if(randchance <= 70){
			response = "You find them dead.";
			PartyManager &pm = PartyManager::getInstance();
			pm.removePartyMember(pm.getPartyMember(advnum));
		}else if(randchance <=80){
			response = "The entire party falls into a trap, where you find your companion hurt.";
			PartyManager &pm = PartyManager::getInstance();
			ObjectListIterator oli(pm.getParty());

			for(oli.first(); !oli.isDone(); oli.next()){
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
			Monster *nm = MonsterManager::getInstance().getMonster("imp");
			nm->setName("Greedy Imp");
			nm->setReward(goldlost+30);
			nm->setDesc("A greedy little imp that holds your bag of gold!");
			nb->addMonster(nm);
			SceneManager::getInstance().push(nb);
		}
		break;
	case 5:
		if(randchance <=20){
			response = "You whistle a nice tune. A monster hears! Its so impressed, it gives you some gold.";
			PartyManager::getInstance().addTreasure(Math::randomRange(1, 100));
		}else if(randchance <= 40){
			response = "You shout out of boredom, waking up a monster.";
			Battle *nb = new Battle();
			nb->addMonster(MonsterManager::getInstance().randomMonster());
			SceneManager::getInstance().push(nb);
		}else if(randchance <= 70){
			response = "You sit down and have a nice stew. Morale increases.";
			ObjectListIterator oli(PartyManager::getInstance().getParty());

			for(oli.first(); !oli.isDone(); oli.next()){
				Adventurer *tadv = ((Adventurer*)oli.getCurrent());
				int temp = tadv->getHealth() + (tadv->getMaxHealth()*.25);
				if(temp <= tadv->getMaxHealth()){
					tadv->setHealth(temp);
				}else{
					tadv->setHealth(tadv->getMaxHealth());
				}
			}
		}else if(randchance <= 71){
			response = "You wonder if life is just some game to amuse a greater being. You dismiss the notion";
		}else{
			response = "You have a nice conversation with your party";
			ObjectListIterator oli(PartyManager::getInstance().getParty());

			for(oli.first(); !oli.isDone(); oli.next()){
				Adventurer *tadv = ((Adventurer*)oli.getCurrent());
				int temp = tadv->getHealth() + (tadv->getMaxHealth()*.1);
				if(temp <= tadv->getMaxHealth()){
					tadv->setHealth(temp);
				}else{
					tadv->setHealth(tadv->getMaxHealth());
				}
			}
		}
	}

	this->setViewString(response);
}

void PromptEvent::hasRejected(){
	string response;

	PartyManager &pm = PartyManager::getInstance();

	switch(promptnumber){
	case 1: {
		int monsterchance = Math::randomRange(1,100);
		if(monsterchance <= 20){
			response = "In your searching, you came across a monster blocking the exit!";
			Battle* nb = new Battle();
			nb->addMonster(MonsterManager::getInstance().randomMonster());
			SceneManager::getInstance().push(nb);
		}else{
			response = "You found a way around the chasm.";
		}
		break;
	}
	case 2:
		if(Math::randomRange(1,100) <= 30){
			response = "He shouts that you are lying, and transforms into a monster!";
			Battle* nb = new Battle();
			nb->addMonster(MonsterManager::getInstance().randomMonster());
			SceneManager::getInstance().push(nb);
		}
		break;
	case 3:
		response = "You leave them behind";
		pm.removePartyMember(pm.getPartyMember(advnum));
		break;
	case 4:
		response = "You forget about the gold and continue on.";
		break;
	case 5:
		response = "You continue on. Morale decreases.";
		ObjectListIterator oli(PartyManager::getInstance().getParty());
		for(oli.first(); !oli.isDone(); oli.next()){
			Adventurer *tadv = ((Adventurer*)oli.getCurrent());
			int temp = tadv->getHealth() - (tadv->getMaxHealth()*.15);
			if(temp <= 0){
				PartyManager::getInstance().removePartyMember(tadv);
			}else{
				tadv->setHealth(temp);
			}
		}
	}

	this->setViewString(response);
}
