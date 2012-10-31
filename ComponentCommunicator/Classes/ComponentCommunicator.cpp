#include "ComponentCommunicator.h"
#include "Entity.h"
#include "Globals.h"

ComponentCommunicator::ComponentCommunicator()
	:messageSender(new CCNode())
	,globals(Globals::sharedGlobals())
{
	messageSender->setIsVisible(false);
	globals.getRootNode()->addChild(messageSender);
	// not to use not needed functional of CCNode
}

ComponentCommunicator::~ComponentCommunicator()
{
	globals.getRootNode()->removeChild(messageSender, true);
	delete messageSender;
	messageSender = NULL;
}

void ComponentCommunicator::sendMessage( float delay, CCObject* recipient, SEL_CallFuncO selector )
{
	CCActionInterval* delayTime = CCDelayTime::actionWithDuration(delay);
	CCCallFunc* check = CCCallFuncO::actionWithTarget(this, callfuncO_selector(ComponentCommunicator::checkRecipient), recipient);
	CCCallFunc* callback = CCCallFuncO::actionWithTarget(recipient, selector, recipient);
	CCFiniteTimeAction*  sequence = CCSequence::actions(delayTime, check, callback, NULL);
	messageSender->runAction((CCActionInterval*)sequence);
}

void ComponentCommunicator::checkRecipient( CCObject* object )
{
	if (object == NULL)
	{
		messageSender->stopAllActions();
	}
}
