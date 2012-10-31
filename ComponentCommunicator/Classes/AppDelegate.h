#ifndef __APP_DELEGATE_H__
#define __APP_DELEGATE_H__

#include "CCApplication.h"

class  AppDelegate : private cocos2d::CCApplication
{
public:
    AppDelegate();
    virtual ~AppDelegate();
	
    virtual bool initInstance();
    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();
};

#endif  // __APP_DELEGATE_H__

