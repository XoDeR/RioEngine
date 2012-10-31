#ifndef D_E_PROCESSING_SYSTEM_H
#define D_E_PROCESSING_SYSTEM_H

#include "DelayedEntitySystem.h"

class DelayedEntityProcessingSystem : public DelayedEntitySystem
{
protected:
	virtual void processEntities(ImmutableBag<Entity*>& bag, float accumulatedDelta);
	virtual void processEntity(Entity& e, float accumulatedDelta) = 0;
};

#endif // D_E_PROCESSING_SYSTEM_H
