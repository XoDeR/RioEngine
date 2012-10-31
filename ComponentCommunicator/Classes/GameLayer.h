#ifndef __Game_LAYER_H__
#define __Game_LAYER_H__

#include "CommonProtocols.h"
#include "Vector2.h"

class GameScene;

class Globals;

class World;
class MovementSystem;
class RenderSystem;

class GameLayer : public CCLayer
{
public:
	LAYER_NODE_FUNC(GameLayer);
	GameLayer();
	bool init();
	void onEnterTransitionDidFinish();
private:
	void update(ccTime dt);
	void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	void checkInput(CCPoint touchedPoint);
public:
	virtual ~GameLayer();
	
private:
	CCSize winSize;
	GameScene* gameScene;
private:
	Globals& globals;
private:
	World* world;
	MovementSystem* movementSystem;
	RenderSystem* renderSystem;
};

#endif  // __Game_LAYER_H__