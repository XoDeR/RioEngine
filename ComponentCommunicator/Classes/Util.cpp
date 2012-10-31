#include "Util.h"
#include <iostream> // for using stringstream
#include <sstream>

CCPoint getPointFromString(string str)
{
	// assume ints x,y are separated only with comma  
	CCPoint result;
	int commaPos = str.find(',');
	int len = str.size();
	string xStr = str.substr(0,commaPos);
	string yStr = str.substr(commaPos + 1,len - commaPos - 1);
	result.x = (int)strtol(xStr.c_str(), 0, 10);
	result.y = (int)strtol(yStr.c_str(), 0, 10);
	return result;
}

ccColor3B getColor3BFromString(string str)
{
	float r;
	float g;
	float b;
	getColorRGBFromString(str, r, g, b);
	ccColor3B color = ccc3((GLubyte)(r),(GLubyte)(g),(GLubyte)(b));
	return color;
}

void getColorRGBFromString(string str, float& r, float& g, float& b)
{
	// assume ints r,g,b are separated only with commas  
	CCPoint result;
	int commaPos = str.find(',');
	int len = str.size();
	string rStr = str.substr(0,commaPos);
	string gbStr = str.substr(commaPos + 1,len - commaPos - 1);
	int secondCommaPos = gbStr.find(',');
	int gbLen = gbStr.size();
	string gStr = gbStr.substr(0,secondCommaPos);
	string bStr = gbStr.substr(secondCommaPos + 1,gbLen - secondCommaPos - 1);

	r = (float)strtod(rStr.c_str(), 0);
	g = (float)strtod(gStr.c_str(), 0);
	b = (float)strtod(bStr.c_str(), 0);
}

CCPoint anchorPointConvertToRelative(CCPoint point, CCRect rect)
{
	float w = rect.size.width;
	float h = rect.size.height;
	float x = point.x;
	float y = point.y;
	return ccp(x/w,y/h);
}

CCRect getChildSpriteBoundingRect(CCSprite* child)
{
	CCPoint relativePosition = child->getPosition();
	CCPoint parentAnchorPoint = child->getParent()->getAnchorPointInPixels();
	CCPoint correctedPosition = ccpSub(relativePosition, parentAnchorPoint);
	CCPoint parentPosition = child->getParent()->getPosition();
	CCPoint absolutePosition = ccpAdd(parentPosition, correctedPosition);

	CCPoint anchorPoint = child->getAnchorPointInPixels();

	CCPoint topLeft = ccpSub(absolutePosition, anchorPoint);
	CCSize size = child->getContentSize();

	CCRect rect;
	rect.origin = topLeft;
	rect.size = size;

	return rect;
}

CCPoint getPointFromVector( Vector2 vector2 )
{
	CCPoint result;
	result.x = vector2.getX();
	result.y = vector2.getY();
	return result;
}

Vector2 getVectorFromPoint( CCPoint point )
{
	Vector2 result;
	result.setX(point.x);
	result.setY(point.y);
	return result;
}

CCRect getBoundingRect( CCSprite* sprite )
{
	CCRect rect = sprite->boundingBox();
	float x = sprite->getPosition().x;
	float y = sprite->getPosition().y;
	float w = rect.size.width;
	float h = rect.size.height;
	float apx = sprite->getAnchorPoint().x;
	float apy = sprite->getAnchorPoint().y;
	rect.origin.x = x - w*apx;
	rect.origin.y = y - h*apx;

	return rect;
}

string intToString(int number)
{
	char buffer[32];
	sprintf(buffer, "%d", number);
	string result = buffer;
	return result;
}

float randomFloat(float a, float b) 
{
	float random = ((float) rand()) / (float) RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

bool getRandomBoolean()
{
	int randomValue = rand() % 2;
	return randomValue == 1 ? true : false;
}

Vector2 getNormalPoint( const Vector2& p, const Vector2& a, const Vector2& b )
{
	Vector2 ap;
	ap = p - a;

	Vector2 ab;
	ab = b - a;
	ab.normalize();

	ab *= ap.dotProduct( ab );

	Vector2 normalPoint;
	normalPoint = a + ab;

	return normalPoint;
}

vector<int> getListFromCommaSeparatedString(string str)
{
	vector<int> vect;
	std::stringstream ss(str);
	int i;

	while (ss >> i)
	{
		vect.push_back(i);

		if (ss.peek() == ',')
			ss.ignore();
	}
	return vect;
}

vector<string> getListOfStringsFromCommaSeparatedString(string str)
{
	vector<string> vect;
	std::stringstream ss(str);
	string i;

	while (ss >> i)
	{
		vect.push_back(i);

		if (ss.peek() == ',')
			ss.ignore();
	}
	return vect;
}