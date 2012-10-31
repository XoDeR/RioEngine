#include "TransformComponent.h"

TransformComponent::TransformComponent(Vector2 position)
	:position(position)
{
}

void TransformComponent::setPosition( Vector2 position )
{
	this->position = position;
}

void TransformComponent::addDeltaPosition( Vector2 position )
{
	this->position.add(position);
}

Vector2 TransformComponent::getPosition()
{
	return position;
}
