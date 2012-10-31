#include "Globals.h"
#include "Util.h"

#include <iomanip>
#include <sstream>

#include <iostream>

#include "GameScene.h"
#include "GameLayer.h"

std::string Globals::ZeroPadNumber(int num)
{
	std::ostringstream ss;
	ss << std::setw(2) << std::setfill('0') << num;
	std::string result = ss.str();
	if (result.length() > 2)
	{
		result.erase(0, result.length() - 7);
	}
	return result;
}

std::string Globals::ZeroPadNumberXX(int num)
{
	std::ostringstream ss;
	ss << std::setw(2) << std::setfill('0') << num;
	std::string result = ss.str();
	if (result.length() > 2)
	{
		result.erase(0, result.length() - 7);
	}
	return result;
}

std::string Globals::ZeroPadNumberXXXX(int num)
{
	std::ostringstream ss;
	ss << std::setw(4) << std::setfill('0') << num;
	std::string result = ss.str();
	if (result.length() > 4)
	{
		result.erase(0, result.length() - 7);
	}
	return result;
}

Globals::Globals()
	:root(NULL)
{
	initGlobals();
}


Globals::~Globals()
{

}

void Globals::initGlobals()
{
	winSize = CCDirector::sharedDirector()->getWinSize();
}

void Globals::updateTime()
{
	now = time(0);	
	current = localtime(&now);
}

string Globals::getFormattedCurrentTimeInHHMM()
{
	updateTime();
	return ZeroPadNumber(current->tm_hour) + ZeroPadNumber(current->tm_min);
}

string Globals::getFormattedCurrentTimeInHHMMSS()
{
	updateTime();
	return ZeroPadNumber(current->tm_hour) + ZeroPadNumber(current->tm_min) + ZeroPadNumber(current->tm_sec);
}

std::string Globals::getFormattedCurrentTimeInMMSS()
{
	updateTime();
	return ZeroPadNumber(current->tm_min) + std::string(":") + ZeroPadNumber(current->tm_sec);
}

unsigned int Globals::getCurrentTimeInSeconds()
{
	updateTime();
	return 3600 * current->tm_hour + 60 * current->tm_min + current->tm_sec;
}

void Globals::setRootNode( CCNode* root )
{
	this->root = root;
}

CCNode* Globals::getRootNode()
{
	return root;
}
