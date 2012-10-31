#include "TurnFactorComponent.h"

TurnFactorComponent::TurnFactorComponent()
	:angle(0.0f)
	,angleInDegrees(0.0f)
{

}

void TurnFactorComponent::setAngleInDegrees( float angleInDegrees )
{
	this->angleInDegrees = angleInDegrees;
}

float TurnFactorComponent::getAngleInDegrees()
{
	return angleInDegrees;
}