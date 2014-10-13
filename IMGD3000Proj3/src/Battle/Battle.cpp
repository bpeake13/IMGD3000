#include "Battle.h"
#include "BattlePhase.h"
#include "EventStep.h"
#include "SceneManager.h"

Battle::Battle()
{
	this->currentPhase = NULL;

	this->enemyList = new DynamicPtrArray();
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

void Battle::endBattle(string reason, string info)
{
	SceneManager::popKill();
}
