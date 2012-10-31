#ifndef EntityFactory_h__
#define EntityFactory_h__

#include "CommonProtocols.h"
#include "Vector2.h"

class Entity;
class World;
class GroupManager;

class SpatialComponent;
class TransformComponent;
class TurnFactorComponent;

class EntityFactory 
{
public:
	EntityFactory();
	void createUnit(World* world, Vector2 position);
};
#endif // EntityFactory_h__