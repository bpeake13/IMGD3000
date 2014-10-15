// Engine includes

#include <stdio.h>

#include "LogManager.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "DungeonScene.h"
#include "MonsterManager.h"

int main(int argc, char *argv[])
{
	LogManager& log = LogManager::getInstance();
	log.startUp();
	log.setFlush();

	MonsterManager &mm = MonsterManager::getInstance();
	mm.startUp();
	mm.loadMonster("monsters\\stat-centaur.txt", "sprites\\mon-centaur-spr.txt", "centaur");
	Monster* mon = mm.getMonster("centaur");

	GameManager& gm = GameManager::getInstance();

	if(gm.startUp())
	{
		log.writeLog("Failed to start game manager");
		gm.shutDown();
		return -1;
	}

	SceneManager& sm = SceneManager::getInstance();
	sm.startUp();

	DungeonScene* mainScene = new DungeonScene(15);
	SceneManager::push(mainScene);

	gm.run(30);

	gm.shutDown();

	log.writeLog("Game shutting down");

	return 0;
}
