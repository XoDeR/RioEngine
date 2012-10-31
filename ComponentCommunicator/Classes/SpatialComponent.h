#ifndef SpatialComponent_h__
#define SpatialComponent_h__

#include "Component.h"
#include "ComponentCommunicator.h"

class Entity;

class SpatialComponent : public Component, public ComponentCommunicator
{
private:
	string spriteFrameName;
	CCSprite* root;
public:
	CCSprite* getRoot();
	void setRoot(CCSprite* root);
public:
	SpatialComponent(string spriteFrameName);
	virtual ~SpatialComponent();
	string getSpatialFormFile();
private:
public:
	void processMessageFromTransformComponent(CCObject* object);
	void processMessageFromTransformComponent2(CCObject* object);

	bool isTurnFactorSetToRemove;
	bool needToRemoveTurnFactor;
	bool isTurnFactorRemoved;

	bool needToSetToAddTurnFactor;
	bool needToAddTurnFactor;
};
#endif // SpatialComponent_h__
