#include "Battle.h"
#include "BattlePhase.h"
#include "EventStep.h"
#include "SceneManager.h"
#include "AdventurerSelectPhase.h"

Battle::Battle()
{
	this->currentPhase = new AdventurerSelectPhase(this);

	this->enemyList = new DynamicPtrArray();

	this->endReason = "";
	this->endInfo = "";
}

Battle::~Battle()
{
}

void Battle::addMonster(Monster* monster)
{
	this->enemyList->add(monster);
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
	int r = currentPhase->eventHandler(e);

	string eventType = e->getType();
	if(eventType == DF_EVENT_STEP)
	{
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
	SceneManager::pop();
}
