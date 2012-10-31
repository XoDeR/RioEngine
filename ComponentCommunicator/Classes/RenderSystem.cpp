#include "RenderSystem.h"
#include "Entity.h"
#include "Util.h"

RenderSystem::RenderSystem( CCLayer* container ) :container(container)
{
	addComponentType<SpatialComponent>();
	addComponentType<TransformComponent>();
	addComponentType<TurnFactorComponent>();
}

void RenderSystem::initialize()
{
	spatialComponentMapper.init(*world);
	transformComponentMapper.init(*world);
	turnFactorComponentMapper.init(*world);
}

void RenderSystem::added(Entity& e)
{
	SpatialComponent* spatialComponent = spatialComponentMapper.get(e);
	spatialComponent->setRoot(CCSprite::spriteWithFile(spatialComponent->getSpatialFormFile().c_str()));
	container->addChild(spatialComponent->getRoot());
}

void RenderSystem::begin()
{

}

void RenderSystem::processEntity(Entity& e)
{
	SpatialComponent* spatialComponent = spatialComponentMapper.get(e);
	TransformComponent* transformComponent = transformComponentMapper.get(e);
	CCPoint position = getPointFromVector(transformComponent->getPosition());
	spatialComponent->getRoot()->setPosition(position);

	TurnFactorComponent* turnFactorComponent = turnFactorComponentMapper.get(e);
	if (turnFactorComponent != NULL)
	{
		spatialComponent->getRoot()->setRotation(turnFactorComponent->getAngleInDegrees());
	}
	else
	{
		//spatialComponent->getRoot()->setRotation(0.0f);
	}

	if (spatialComponent->isTurnFactorSetToRemove == false)
	{
		transformComponent->sendMessage(1.0f, spatialComponent, callfuncO_selector(SpatialComponent::processMessageFromTransformComponent));
		spatialComponent->isTurnFactorSetToRemove = true; // send this message once
	}

	if (spatialComponent->needToSetToAddTurnFactor == true)
	{
		transformComponent->sendMessage(1.0f, spatialComponent, callfuncO_selector(SpatialComponent::processMessageFromTransformComponent2));
		spatialComponent->needToSetToAddTurnFactor = false;
	}
}

void RenderSystem::end()
{

}

void RenderSystem::removed(Entity& e)
{
	SpatialComponent* spatialComponent = spatialComponentMapper.get(e);
	container->removeChild(spatialComponent->getRoot(), true);
}