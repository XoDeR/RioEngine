#include "AppDelegate.h"

#include "cocos2d.h"
using namespace cocos2d;

#include "GameScene.h"

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::initInstance()
{
    bool bRet = false;
    do 
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
        CCEGLView * pMainWnd = new CCEGLView();
        CC_BREAK_IF(! pMainWnd
            || ! pMainWnd->Create(TEXT("Component Communicator"), 768, 1024));
#endif  // CC_PLATFORM_WIN32

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        CCFileUtils::setiPadSuffix("");
#endif  // CC_PLATFORM_IOS

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#endif  // CC_PLATFORM_ANDROID

        bRet = true;
    } while (0);
    return bRet;
}

bool AppDelegate::applicationDidFinishLaunching()
{
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(&CCEGLView::sharedOpenGLView());

	pDirector->enableRetinaDisplay(false);

    pDirector->setDeviceOrientation(kCCDeviceOrientationLandscapeLeft);
    pDirector->setDisplayFPS(false);
	pDirector->setAnimationInterval(1.0 / 60);
	pDirector->setDepthTest(false);

	CCScene *pScene = GameScene::node();
	CCDirector::sharedDirector()->runWithScene(pScene);

    return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();
	CCDirector::sharedDirector()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
	CCDirector::sharedDirector()->startAnimation();
}