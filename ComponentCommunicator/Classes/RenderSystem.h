#ifndef RenderSystem_h__
#define RenderSystem_h__

#include "Common.h"
#include "EntityProcessingSystem.h"
#include "ComponentMapper.h"
#include "SpatialComponent.h"
#include "TransformComponent.h"
#include "TurnFactorComponent.h"

class Entity;

class RenderSystem : public EntityProcessingSystem 
{
private:
	CCLayer* container;
	ComponentMapper<SpatialComponent> spatialComponentMapper;
	ComponentMapper<TransformComponent> transformComponentMapper;
	ComponentMapper<TurnFactorComponent> turnFactorComponentMapper;

public:
	RenderSystem(CCLayer* container);
	void initialize();

protected:
	void added(Entity& e);
	void begin();
	void processEntity(Entity& e);
	void end();
	void removed(Entity& e);
};
#endif // RenderSystem_h__
