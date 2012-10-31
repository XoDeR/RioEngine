#ifndef Vector2_h__
#define Vector2_h__

// 2D vector class

#include "Common.h"
#include "Math.h"

class Vector2 
{
private:
	float _x;
	float _y;
public:

	// Constructors
	
	Vector2():_x(0), _y(0) {}

	Vector2(const float x0, const float y0):_x(x0), _y(y0) {}

	Vector2(const Vector2& v): _x(v._x), _y(v._y) {}

	void operator ()(const float x0, const float y0)
	{
		_x = x0; _y= y0;
	}

	bool operator==(const Vector2 &v)
	{
		return _x== v._x && _y == v._y;
	}

	//inequality
	bool operator !=(const Vector2 &v)
	{
		return _x != v._x || _y != v._y;
	}

	//assignment
	const Vector2 &operator = (const Vector2 &v)
	{
		_x = v._x; _y = v._y;
		return *this;
	}

	//negation
	const Vector2 operator -(void) const
	{
		return Vector2 (-_x,-_y);
	}

	// Creates an exact copy of this Vector2
	Vector2 cloneVector() 
	{
		return Vector2(_x, _y);
	}

	// Makes x and y zero.
	Vector2 zeroVector() 
	{
		_x = 0;
		_y = 0;
		return *this;
	}

	// Is this vector zeroed?
	bool isZero()
	{
		return _x == 0 && _y == 0;
	}

	
	// Is the vector's length == 1?
	bool isNormalized()
	{
		return fabs(getLength() - 1) < 0.00000001f;
	}

	/**
	* Does this vector have the same location as another?
	* @param vector2 The vector to test.
	* @return bool True if equal, false if not.
	*/
	bool equals(Vector2 vector2)
	{
		return _x == vector2._x && _y == vector2._y;
	}

	// Sets the length which will change x and y, but not the angle.
	void setLength(float length)
	{
		float _angle = getAngle();
		_x = cos(_angle) * length;
		_y = sin(_angle) * length;
		if(fabs(_x) < 0.00000001f) _x = 0;
		if(fabs(_y) < 0.00000001f) _y = 0;
	}

	// Returns the length of the vector.
	float getLength() const
	{
		return (float)sqrtf((*this) * (*this));
	}

	// Returns the length of this vector, before square root. Allows for a faster check.
	float getLengthSquared() const
	{
		return (float)((*this) * (*this));
	}

	// Changes the angle of the vector. X and Y will change, length stays the same.
	void setAngle(float angle)
	{
		float len = getLength();
		_x = cos(angle) * len;
		_y = sin(angle) * len;
	}

	// Get the angle of this vector.
	float getAngle()
	{
		return atan2(_y, _x);
	}

	// Sets the vector's length to 1.
	Vector2 normalize()
	{
		if(getLength() < 0.00001f)
		{
			_x = 1;
			return *this;
		}
		float len = getLength();
		_x /= len;
		_y /= len;
		return *this;
	}

	//void normalize()
	//{
	//	float d = getLength();
	//	if(d < 0.00001f)
	//	{	
	//		d = 1;
	//	}
	//	d = 1/d;
	//	*this *= d;
	//}

	/**
	* Sets the vector's length to len.
	* @param len The length to set it to.
	* @return Vector2 This vector.
	*/
	Vector2 normalcate(float len) 
	{
		setLength(len);
		return *this;
	}

	/**
	* Sets the length under the given value. Nothing is done if the vector is already shorter.
	* @param max The max length this vector can be.
	* @return Vector2 This vector.
	*/

//#ifndef min
//#define min(a,b)            (((a) < (b)) ? (a) : (b))
//#endif
	Vector2 truncate(float max)
	{
		setLength(min(max, getLength()));
		return *this;
	}

	// Makes the vector face the opposite way.
	Vector2 reverse()
	{
		_x = -_x;
		_y = -_y;
		return *this;
	}

	/**
	* Calculate the dot product of this vector and another.
	* @param vector2 Another vector2D.
	* @return float The dot product.
	*/
	float dotProduct(Vector2 vector2)
	{
		return _x * vector2._x + _y * vector2._y;
	}

	float operator *(const Vector2 &v) const
	{
		return _x*v._x + _y*v._y;
	}

	static float Dot(const Vector2 &a, const Vector2 &b)
	{
		return a._x* b._x + a._y * b._y;
	}	

	/**
	* Calculate the cross product of this and another vector.
	* @param vector2 Another Vector2.
	* @return float The cross product.
	*/
	float crossProd(Vector2 vector2) 
	{
		return _x * vector2._y - _y * vector2._x;
	}

	// Calculate angle between any two vectors.
	static float angleBetween(Vector2 vector1, Vector2 vector2)
	{
		if(!vector1.isNormalized()) vector1 = vector1.cloneVector().normalize();
		if(!vector2.isNormalized()) vector2 = vector2.cloneVector().normalize();
		return acos(vector1.dotProduct(vector2));
	}

	// Is the vector to the right or left of this one?
	// @param vector2 The vector to test.
	// @return bool If left, returns true, if right, false.
	bool sign(Vector2 vector2)
	{
		bool result = false;
		int s = getPerpendicular().dotProduct(vector2) < 0 ? -1 : 1;
		if (s == -1) result = false;
		else result = true;
		return result;
	}

	// Get the vector that is perpendicular.
	Vector2 getPerpendicular()
	{
		return Vector2(-_y, _x);
	}

	// Calculate distance to another vector
	float distance(Vector2 vector2) 
	{
		return (float)sqrtf(distSQ(vector2));
	}

	// Calculate squared distance between vectors. Faster than distance.
	float distSQ(Vector2 vector2)
	{
		float dx = vector2._x - _x;
		float dy = vector2._y - _y;
		return dx * dx + dy * dy;
	}

	/**
	* Add a vector to this vector.
	* @param vector2 The vector to add to this one.
	* @return Vector2 This vector.
	*/
	Vector2 add(Vector2 vector2)
	{
		_x += vector2._x;
		_y += vector2._y;
		return *this;
	}

	const Vector2 operator +(const Vector2 &v) const
	{
		return Vector2(_x+v._x,_y+v._y);
	}

	const Vector2 &operator +=(const Vector2 &v)
	{
		_x += v._x;
		_y += v._y;
		return *this;
	}

	/**
	* Subtract a vector from this one.
	* @param vector2 The vector to subtract.
	* @return Vector2 This vector.
	*/
	Vector2 subtract(Vector2 vector2) 
	{
		_x -= vector2._x;
		_y -= vector2._y;
		return *this;
	}

	const Vector2 operator -(const Vector2 &v)const
	{
		return Vector2(_x-v._x,_y-v._y);
	}

	const Vector2 &operator -=(const Vector2 &v)
	{
		_x -= v._x;
		_y -= v._y;
		return *this;
	}

	/**
	* Mutiplies this vector by another one.
	* @param scalar The scalar to multiply by.
	* @return Vector2 This vector, multiplied.
	*/
	Vector2 multiply(float scalar)
	{
		_x *= scalar;
		_y *= scalar;
		return *this;
	}

	const Vector2 operator *(const float num)const
	{
		return Vector2(_x*num,_y*num);
	}

	const Vector2 &operator *=(const float num)
	{
		_x *= num;
		_y *= num;
		return *this;
	}

	/**
	* Divide this vector by a scalar.
	* @param scalar The scalar to divide by.
	* @return Vector2 This vector.
	*/
	Vector2 divide(float scalar)
	{
		_x /= scalar;
		_y /= scalar;
		return *this;
	}

	const Vector2 operator /(const float num) const
	{
		return Vector2(_x/num,_y/num);
	}

	const Vector2 &operator /=(const float num)
	{
		_x /= num;
		_y /= num;
		return *this;
	}

	// Set and get y component.
	void setY(float y)
	{
		_y = y;
	}

	float getY() 
	{
		return _y;
	}

	// Set and get x component.
	void setX(float x)
	{
		_x = x;
	}

	float getX()
	{
		return _x;
	}
};
#endif // Vector2_h__