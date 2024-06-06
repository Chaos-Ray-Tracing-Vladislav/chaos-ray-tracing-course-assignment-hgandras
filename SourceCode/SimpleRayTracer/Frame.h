#pragma once
#include "Vector.h"

class Frame
{
	//The unit vectors in world space
	Vector3 x;
	Vector3 y;
	Vector3 z;

	Vector3 ToWorld(Vector3 vec)
	{

	}

	Vector3 ToLocal(Vector3 vec)
	{

	}

	//Generate local coordinate frame from normal in world space
	static Frame FromNormal(Vector3 n)
	{

	}
};