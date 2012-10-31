#include "GameScene.h"

// Layers
#include "GameLayer.h"

GameScene::GameScene()
	:gameLayer(NULL)
{

}

// GameScene
bool GameScene::init()
{
	if (CCScene::init())
	{
		return true;
	}
	else
	{
		return false;
	}
}

GameScene::~GameScene()
{
}

void GameScene::onEnter()
{
	gameLayer = GameLayer::node();
	addChild(gameLayer, GAME_LAYER_Z_ORDER);

	CCScene::onEnter();
}

void GameScene::onExit()
{
	removeAllChildrenWithCleanup(true);
	CCScene::onExit();
}