#pragma once
#include "Vector.h"

class Frame
{
private:
	Matrix4 transform;

public:
	Frame() : transform(Matrix4::Identity())
	{

	}

	Frame(Matrix3& orientation, Vector3& position) : transform(Matrix4(orientation,position))
	{
	
	}

	Frame(Matrix4& transform) : transform(transform)
	{

	}

	//Transforms a world point to the local frame
	Vector3 ToLocal(Vector3& p)
	{
		Vector4 point(p);
		Vector4 transformed = ToLocal(p);
		return Vector3(transformed.x, transformed.y, transformed.z);
	}

	Vector4 ToLocal(Vector4& p)
	{
		return transform * p;
	}

	//Transforms a local point to the world coordinate system
	Vector3 ToWorld(Vector3& p)
	{
		Vector4 point(p);
		Vector4 transformed = ToWorld(point);
		return Vector3(transformed.x, transformed.y, transformed.z);
	}

	Vector4 ToWorld(Vector4& p)
	{
		//Negate translation
		Vector4 t = -transform.col4();
		Vector3 t3(t.x, t.y, t.z);

		//Invert rotation
		Vector4 c1 = transform.col1();
		Vector4 c2 = transform.col2();
		Vector4 c3 = transform.col3();

		Vector3 rc1(c1.x, c1.y, c1.z);
		Vector3 rc2(c2.x, c2.y, c2.z);
		Vector3 rc3(c3.x, c3.y, c3.z);

		Matrix3 rot(rc1, rc2, rc3);
		Matrix3 rotT = rot.T();
		
		Matrix4 inverse(rotT, t3);
		return inverse * p;
		
	}

	//Generate local coordinate frame from normal in world space
	static Frame FromNormal(Vector3& n)
	{
		Vector3 up = Vector3::up();
		Vector3 z = Cross(n,up);
		Vector3 y = Cross(n, z);
		Vector3 x = Cross(y, z);

		Matrix3 rot(x, y, z);
		Matrix4 t(rot);
		return Frame(t);
	}
};