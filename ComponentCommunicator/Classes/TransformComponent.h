#ifndef Transform_h__
#define Transform_h__

#include "Component.h"
#include "ComponentCommunicator.h"
#include "Vector2.h"

class TransformComponent : public Component, public ComponentCommunicator
{
private:
	Vector2 position;
public:
	TransformComponent(Vector2 position);
	void setPosition(Vector2 position);
	void addDeltaPosition(Vector2 position);
	Vector2 getPosition();
};
#endif // Transform_h__