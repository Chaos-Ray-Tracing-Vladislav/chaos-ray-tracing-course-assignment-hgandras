#pragma once
#include "Vector.h"

namespace Geometry
{
	struct Triangle
	{
	
		Vector3 v1, v2, v3; //Positions of the vertices
	
		Triangle(Vector3 v1,Vector3 v2,Vector3 v3) : v1(v1),v2(v2),v3(v3)
		{

		}

		Vector3 normal()
		{
			return Cross(v2-v1, v3-v1).norm();
		}

		float area()
		{
			return Cross(v2 - v1, v3 - v1).length() / 2;
		}

	};
}
