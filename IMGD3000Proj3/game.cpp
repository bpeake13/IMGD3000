// Engine includes

#include <stdio.h>

#include "Utility.h"
#include "IVector.h"
#include "Clock.h"

#include "WorldManager.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "ResourceManager.h"

#include "LogManager.h"

#include "GameManager.h"

#include "TesterObject.h"
#include "TestObjectSolid.h"
#include "TestObjectSoft.h"

#include "DynamicPtrArray.h"

#include "HashTable.h"

#include "ViewObjectTest.h"

int main(int argc, char *argv[])
{
	LogManager& log = LogManager::getInstance();
	log.setFlush();

	WorldManager& world = WorldManager::getInstance();

	GameManager& gm = GameManager::getInstance();
	if(gm.startUp())
	{
		gm.shutDown();
		return 0;
	}

	ResourceManager& rm = ResourceManager::getInstance();
	rm.loadSprite("sprites/test.txt", "test");

	if(Sprite* spr = rm.getSprite("test"))
	{
		log.writeLog("%d %d %d", spr->getWidth(), spr->getHeight(), spr->getFrameCount());
		log.writeLog("%s", spr->getFrame(1)->getString().c_str());
	}

	new ViewObjectTest("Press r", TOP_CENTER, 0, true);
	new ViewObjectTest("Borderless", CENTER_CENTER, 0, false);
	new ViewObjectTest("Press q", BOTTOM_RIGHT, 0, false);

	Sprite* spr = rm.getSprite("test");
	TesterObject* o = new TesterObject(IVector(0, 0));
	TestObjectSolid* p = new TestObjectSolid();
	o->setCentered(true);
	o->setSprite(spr);
	o->setSlowdown(30);
	o->setColor(COLOR_RED);

	p->setCentered(true);
	p->setSprite(spr);
	p->setSlowdown(30);

	Box bounds = o->getBounds();
	IVector corner = bounds.getCorner();
	log.writeLog("%d %d", bounds.getHorizontal(), bounds.getVertical());
	log.writeLog("%d %d", corner.getX(), corner.getY());

	gm.run();

	gm.shutDown();

	return 1;

	/*int* x = new int(0);
	int* y = new int(1);
	int* z = new int(2);

	HashTable* lookup = new HashTable();

	lookup->set("Apple", x);
	lookup->set("Pair", y);
	lookup->set("Blub", z);

	if(lookup->contains("Blub"))
		printf("Contains blub\n");

	int* t = static_cast<int*>(lookup->get("Apple"));
	printf("%d\n", *t);

	t = static_cast<int*>(lookup->get("Pair"));
	printf("%d\n", *t);

	t = static_cast<int*>(lookup->get("Blub"));
	printf("%d\n", *t);

	lookup->remove("Apple");

	if(!lookup->get("Apple"))
		printf("Apple removed\n");*/
}
