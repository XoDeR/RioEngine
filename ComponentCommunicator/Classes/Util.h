#include "Common.h"
#include "Vector2.h"

ccColor3B getColor3BFromString(string str);
void getColorRGBFromString(string str, float& r, float& g, float& b);
// helper to parse "10,10" string to CCPoint(10,10)
CCPoint getPointFromString(string str); 
CCPoint anchorPointConvertToRelative(CCPoint point, CCRect rect);
CCRect getChildSpriteBoundingRect(CCSprite* child);
CCPoint getPointFromVector(Vector2 vector2);
Vector2 getVectorFromPoint(CCPoint point);
CCRect getBoundingRect(CCSprite* sprite);
string intToString(int number);
float randomFloat(float a, float b);
bool getRandomBoolean();
Vector2 getNormalPoint( const Vector2& p, const Vector2& a, const Vector2& b );
vector<int> getListFromCommaSeparatedString(string str);
vector<string> getListOfStringsFromCommaSeparatedString(string str);