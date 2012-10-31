#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "CommonProtocols.h"


#include <stdio.h>
#include <time.h>

class GameScene;
class GameLayer;

class Globals
{
	// singleton stuff
public:
	static Globals& sharedGlobals()
	{
		static Globals s_instance;
		return s_instance;
	}

	// Other non-static member functions
private:
	Globals();                            // constructor

public:
	// now don't prevent these
	Globals(const Globals&);                 // Prevent copy-construction
	Globals& operator=(const Globals&);      // Prevent assignment
	//-- singleton stuff

public:


	CCSize winSize;

	~Globals();

	void initGlobals();
	string getFormattedCurrentTimeInHHMM();
	string getFormattedCurrentTimeInHHMMSS();

	unsigned int getCurrentTimeInSeconds();

private:
	
	void updateTime();
	time_t now; //time_t should be declared in time.h as long
	struct tm *current; //pointer to array holding the current time
public:
	string ZeroPadNumber(int num);
	string ZeroPadNumberXX(int num);
	string ZeroPadNumberXXXX(int num);
	string getFormattedCurrentTimeInMMSS();
private:
	CCNode* root;
public:
	void setRootNode(CCNode* root);
	CCNode* getRootNode();
};

#endif  //__GLOBALS_H__


