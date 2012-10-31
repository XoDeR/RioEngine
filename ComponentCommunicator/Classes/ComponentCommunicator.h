#ifndef ComponentCommunicator_h__
#define ComponentCommunicator_h__

#include "Common.h"

class Entity;
class Globals;

class ComponentCommunicator : public CCObject
{
public:
	ComponentCommunicator();
	virtual ~ComponentCommunicator();
	void sendMessage(float delay, CCObject* recipient, SEL_CallFuncO selector);
	void checkRecipient(CCObject* object);
protected:
	CCNode* messageSender;
	Globals& globals;
};
#endif // ComponentCommunicator_h__
