#ifndef Common_h__
#define Common_h__

#include "cocos2d.h"
using namespace cocos2d;

#include <string>
#include <vector>
#include <deque>
using std::vector;
using std::string;
using std::deque;

enum Status
{
	StatusFailure,
	StatusSuccess,
	StatusRunning
};

#define BUILD_RELEASE_1
#ifndef BUILD_RELEASE_1
#define BUILD_WITHOUT_CHEATS
//#define DISABLED_SOUNDS_DIALOGS_TUTORIALS
#define BUILD_FOR_EXTERNAL_TESTING
#endif

#endif // Common_h__