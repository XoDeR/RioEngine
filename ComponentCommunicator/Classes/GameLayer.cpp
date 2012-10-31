#include "GameLayer.h"
#include "GameScene.h"
#include "Globals.h"

#include "World.h"
#include "Entity.h"
#include "EntityFactory.h"
#include "SystemManager.h"
#include "MovementSystem.h"
#include "RenderSystem.h"

#include "Util.h"
#include "Vector2.h"
#include "pugixml.hpp"
using namespace pugi;

GameLayer::GameLayer()
	:gameScene(NULL)
	,globals(Globals::sharedGlobals())
	,world(new World())
	,movementSystem(NULL)
	,renderSystem(NULL)
{
}

bool GameLayer::init()
{
	if (CCLayer::init())
	{
		setIsTouchEnabled(true);
		winSize = CCDirector::sharedDirector()->getWinSize();

		SystemManager* systemManager = world->getSystemManager();
		movementSystem = (MovementSystem*)systemManager->setSystem(new MovementSystem());
		renderSystem = (RenderSystem*)systemManager->setSystem(new RenderSystem(this));
		systemManager->initializeAll();

		return true;        
	}
	else
	{
		return false;
	}
}

// Entry point
void GameLayer::onEnterTransitionDidFinish()
{
	CCLayer::onEnterTransitionDidFinish();
	gameScene = (GameScene*)(getParent());
	globals.setRootNode(this);
	EntityFactory* entityFactory = world->getEntityFactory();
	entityFactory->createUnit(world, Vector2(100,100));
	scheduleUpdate();
}

void GameLayer::update(ccTime dt)
{
	world->loopStart();
	world->setDelta(dt);
	movementSystem->process();
	renderSystem->process();
}

void GameLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);
	CCPoint location = convertTouchToNodeSpace(touch);
	checkInput(location);
}

void GameLayer::checkInput(CCPoint touchedPoint)
{
}

GameLayer::~GameLayer()
{
}