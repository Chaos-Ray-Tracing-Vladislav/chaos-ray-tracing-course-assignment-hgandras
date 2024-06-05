#include "Vector.h"

template<class T>
class Vector2 : Vector2
{
	T x, y;
	Vector2() : x(0), y(0)
	{

	}

	Vector2(T x,T,y):x(x),y(y)
	{

	}

	Vector2<T> zero()
	{
		return Vector2<T>(0, 0);
	}

	Vector2<T>& operator+(const Vector2<T>& other) override
	{
		Vector2<T> result = Vector2<T>.zero();
		result.x += (other.x + x);
		result.y += (other.y + y);
		return result;
	}

};