#include "Battle.h"
#include "BattlePhase.h"
#include "EventStep.h"
#include "SceneManager.h"
#include "AdventurerSelectPhase.h"
#include "GraphicsManager.h"
#include "WorldManager.h"

Battle::Battle()
{
	this->currentPhase = new AdventurerSelectPhase(this);

	this->enemyList = new DynamicPtrArray();

	this->endReason = "";
	this->endInfo = "";

	this->message = new TextObject;
	this->message->setViewObjectLocation(CENTER_CENTER);
	this->message->setPosition(IVector(0, 15));
	this->message->setColor(COLOR_BLUE);
	this->message->setAltitude(1);

	addObject(message);
}

Battle::~Battle()
{

}

void Battle::addMonster(Monster* monster)
{
	GraphicsManager& gm = GraphicsManager::getInstance();

	int heightCenter = gm.getVertical() / 2;
	int widthCenter = gm.getHorizontal() / 2;

	int totalWidth = 0;
	size_t mc = getMonsterCount();
	for(size_t i = 0; i < mc; i++)
	{
		totalWidth += getMonster(i)->getSprite()->getWidth();
		totalWidth += 2;
	}

	totalWidth += monster->getSprite()->getWidth();

	this->enemyList->add(monster);

	int offset = widthCenter - totalWidth / 2;

	for(size_t i = 0; i < mc + 1; i++)
	{
		Monster* m = getMonster(i);
		m->setPosition(IVector(offset, heightCenter));
		offset += m->getSprite()->getWidth();
	}
}

void Battle::removeMonster(Monster* monster)
{
	enemyList->remove(monster);

	WorldManager::getInstance().markForDelete(monster);
}

Monster* Battle::getMonster(int i)
{
	return (Monster *) enemyList->get(i);
}

size_t Battle::getMonsterCount()
{
	return enemyList->getSize();
}

int Battle::eventHandler(Event* e)
{
	if(Scene::eventHandler(e))
		return 1;

	int r = currentPhase->eventHandler(e);

	string eventType = e->getType();
	if(eventType == DF_EVENT_STEP)
	{
		message->setViewString(currentPhase->getMessage());

		BattlePhase* next = currentPhase->getNext();
		if(next)
		{
			delete currentPhase;
			currentPhase = next;
		}
		else
		{
			string reason = "";
			string info = "";

			if(currentPhase->endBattle(&reason, &info))//if we are told to end the battle then do so
			{
				endBattle(reason, info);
			}
		}
	}

	return r;
}

string Battle::getEndReason() const
{
	return endReason;
}

string Battle::getEndInfo() const
{
	return endInfo;
}

void Battle::endBattle(string reason, string info)
{
	endReason = reason;
	endInfo = info;
	delete currentPhase;
	SceneManager::popKill();
}
