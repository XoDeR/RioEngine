#ifndef __Game_SCENE_H__
#define __Game_SCENE_H__

// Common includes
#include "Common.h"

// Layers
class GameLayer;

class GameScene : public CCScene
{
public:

	CC_SYNTHESIZE(GameLayer*, gameLayer, GameLayer);
	SCENE_NODE_FUNC(GameScene);

	static const int GAME_LAYER_Z_ORDER = 10;

	GameScene();
	bool init();
	void onEnter();
	void onExit();
	~GameScene();
};

#endif  // __Game_SCENE_H__