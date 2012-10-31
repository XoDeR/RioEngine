#ifndef TurnFactorComponent_h__
#define TurnFactorComponent_h__

#include "Component.h"

// needed to  define what animation to render for soldiers warriors, soldier shooters and enemies
class TurnFactorComponent : public Component 
{
private:
	float angle;
	float angleInDegrees;
public:
	TurnFactorComponent();
	void setAngleInDegrees(float angleInDegrees);
	float getAngleInDegrees();
};
#endif // TurnFactorComponent_h__