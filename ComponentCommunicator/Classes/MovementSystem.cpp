#include "MovementSystem.h"
#include "Entity.h"
#include "Util.h"

MovementSystem::MovementSystem()
{
	addComponentType<TurnFactorComponent>();
	addComponentType<TransformComponent>();
	addComponentType<SpatialComponent>();
}

void MovementSystem::initialize()
{
	turnFactorComponentMapper.init(*world);
	transformComponentMapper.init(*world);
	spatialComponentMapper.init(*world);
}

void MovementSystem::added( Entity& e )
{

}

void MovementSystem::begin()
{
}

void MovementSystem::processEntity( Entity& e )
{
	TurnFactorComponent* turnFactorComponent = turnFactorComponentMapper.get(e);
	TransformComponent* transformComponent = transformComponentMapper.get(e);

	float dt = world->getDelta();

	if (turnFactorComponent != NULL)
	{
		float previousAngle = turnFactorComponent->getAngleInDegrees();
		turnFactorComponent->setAngleInDegrees(previousAngle + dt * 100.0f);
	}

	Vector2 previousPosition = transformComponent->getPosition();
	Vector2 position = previousPosition.add(Vector2(dt*60.0f, dt*20.0f));
	if (position.getX() > 1024) position.setX(512);
	if (position.getX() < 0) position.setX(512);
	if (position.getY() < 0) position.setY(384);
	if (position.getY() > 768) position.setY(384);
	transformComponent->setPosition(position);

	SpatialComponent* spatialComponent = spatialComponentMapper.get(e);
	if ((spatialComponent->needToRemoveTurnFactor) == true)
	{
		e.removeComponent<TurnFactorComponent>();
		spatialComponent->needToRemoveTurnFactor = false;
		spatialComponent->isTurnFactorRemoved = true;
		spatialComponent->needToSetToAddTurnFactor = true;
	}
	if ((spatialComponent->needToAddTurnFactor) == true)
	{
		e.addComponent(new TurnFactorComponent());
		spatialComponent->needToAddTurnFactor = false;
		spatialComponent->isTurnFactorSetToRemove = false;
	}
}

void MovementSystem::end()
{
}

void MovementSystem::removed( Entity& e )
{
}