#include "EntityFactory.h"
#include "Entity.h"
#include "World.h"

#include "SpatialComponent.h"
#include "TransformComponent.h"
#include "TurnFactorComponent.h"

EntityFactory::EntityFactory()
{

}

void EntityFactory::createUnit( World* world, Vector2 position )
{
	Entity& e = world->createEntity();

	e.addComponent(new SpatialComponent("UnitSprite.png"));
	e.addComponent(new TransformComponent(position));
	e.addComponent(new TurnFactorComponent());

	e.refresh();
}