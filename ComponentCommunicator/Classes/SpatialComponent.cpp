#include "SpatialComponent.h"

SpatialComponent::SpatialComponent( string spriteFrameName )
	:spriteFrameName(spriteFrameName)
	,isTurnFactorRemoved(false)
	,needToRemoveTurnFactor(false)
	,isTurnFactorSetToRemove(false)
	,needToSetToAddTurnFactor(false)
	,needToAddTurnFactor(false)
{
}

SpatialComponent::~SpatialComponent()
{
}

string SpatialComponent::getSpatialFormFile()
{
	return spriteFrameName;
}

CCSprite* SpatialComponent::getRoot()
{
	return root;
}

void SpatialComponent::setRoot(CCSprite* root)
{
	this->root = root;
}

void SpatialComponent::processMessageFromTransformComponent(CCObject* object)
{
	SpatialComponent* spatialComponent = (SpatialComponent*)(object);
	spatialComponent->needToRemoveTurnFactor = true;
}

void SpatialComponent::processMessageFromTransformComponent2( CCObject* object )
{
	SpatialComponent* spatialComponent = (SpatialComponent*)(object);
	spatialComponent->needToAddTurnFactor = true;
}
