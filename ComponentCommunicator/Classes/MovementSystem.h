#ifndef MovementSystem_h__
#define MovementSystem_h__

#include "Common.h"
#include "EntityProcessingSystem.h"
#include "ComponentMapper.h"
#include "TurnFactorComponent.h"
#include "TransformComponent.h"
#include "SpatialComponent.h"

class Entity;

class MovementSystem : public EntityProcessingSystem 
{
private:
	ComponentMapper<TurnFactorComponent> turnFactorComponentMapper;
	ComponentMapper<TransformComponent> transformComponentMapper;
	ComponentMapper<SpatialComponent> spatialComponentMapper;

public:
	MovementSystem();
	void initialize();

protected:
	void added(Entity& e);
	void begin();
	void processEntity(Entity& e);
	void end();
	void removed(Entity& e);
};
#endif // MovementSystem_h__
