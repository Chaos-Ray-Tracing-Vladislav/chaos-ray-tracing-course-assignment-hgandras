#pragma once

class Vector2 {
public:
	float x, y;

	Vector2() : x(0), y(0)
	{

	}

	Vector2(float x, float y) : x(x), y(y)
	{

	}

	//Scalar operations
	Vector2 operator*(float a) const { return Vector2(a * x, a * y); }
	Vector2 operator/(float a) const { return Vector2(x / a, y / a); }

	//Elementwise operations
	Vector2 operator+(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
	Vector2 operator-(const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
	Vector2 operator*(const Vector2& v) const { return Vector2(x * v.x, y * v.y); }
	Vector2 operator/(const Vector2& v) const { return Vector2(x / v.x, y / v.y); }
	Vector2 operator-() const { return Vector2(-x, -y); }

	//Properties
	float length() { return sqrtf(x*x+y*y); }
	Vector2 norm() { return Vector2(x / length(), y / length()); }

	static Vector2 zero() { return Vector2(0, 0); }
};

inline Vector2 operator*(float a, Vector2& vec) { return Vector2(a * vec.x, a * vec.y); }
inline float Dot(Vector2& a, Vector2& b) { return a.x * b.x + a.y * b.y; }
inline Vector2 Reflect(Vector2& incoming, Vector2& n) { return incoming - 2 * Dot(incoming, n) * n; }

class Vector3 {
public:
	float x, y,z;

	Vector3() : x(0), y(0),z(0)
	{

	}

	Vector3(float x, float y,float z) : x(x), y(y),z(z)
	{

	}

	Vector3(Vector2 vec) : x(vec.x), y(vec.y), z(0)
	{

	}

	//Scalar operations
	Vector3 operator*(float a) const { return Vector3(a * x, a * y,a*z); }
	Vector3 operator/(float a) const { return Vector3(x / a, y / a,z/a); }

	//Elementwise operations
	Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y,z+v.z); }
	Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y,z - v.z); }
	Vector3 operator*(const Vector3& v) const { return Vector3(x * v.x, y * v.y,z * v.z); }
	Vector3 operator/(const Vector3& v) const { return Vector3(x / v.x, y / v.y,z/v.z); }
	Vector3 operator-() const { return Vector3(-x, -y,-z); }

	//Properties
	float length() { return sqrtf(x * x + y * y+z*z); }
	Vector3 norm() { return Vector3(x / length(), y / length(),z/length()); }

	static Vector3 zero() { return Vector3(0, 0, 0); }
	static Vector3 up() { return Vector3(0, 1, 0); }

};

inline Vector3 operator*(float a, Vector3& vec) { return Vector3(a * vec.x, a * vec.y,a*vec.z); }
inline float Dot(Vector3& a, Vector3& b) { return a.x * b.x + a.y * b.y+a.z*b.z; }
inline Vector3 Cross(Vector3& a, Vector3& b) {
	return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
inline Vector3 Reflect(Vector3& incoming, Vector3& n) { return incoming - 2 * Dot(incoming, n) * n; }

class Vector4 {
public:
	float x, y, z, w;

	Vector4() : x(0), y(0), z(0),w(0)
	{

	}

	Vector4(float x, float y, float z,float w) : x(x), y(y), z(z),w(w)
	{

	}

	Vector4(Vector3 vec) : x(vec.x), y(vec.y), z(vec.z), w(1)
	{

	}

	//Scalar operations
	Vector4 operator*(float a) const { return Vector4(a * x, a * y, a * z,a*w); }
	Vector4 operator/(float a) const { return Vector4(x / a, y / a, z / a,a/w); }

	//Elementwise operations
	Vector4 operator+(const Vector4& v) const { return Vector4(x + v.x, y + v.y, z + v.z,w+v.w); }
	Vector4 operator-(const Vector4& v) const { return Vector4(x - v.x, y - v.y, z - v.z,w-v.w); }
	Vector4 operator*(const Vector4& v) const { return Vector4(x * v.x, y * v.y, z * v.z,w-v.w); }
	Vector4 operator/(const Vector4& v) const { return Vector4(x / v.x, y / v.y, z / v.z,w/v.w); }
	Vector4 operator-() const { return Vector4(-x, -y, -z,-w); }

	//Properties
	float length() { return sqrtf(x * x + y * y+z*z+w*w); }
	Vector4 norm() { return Vector4(x / length(), y / length(), z / length(),w/length()); }

	static Vector4 zero() { return Vector4(0, 0, 0,0); }

};

inline Vector4 operator*(float a, Vector4& vec) { return Vector4(a * vec.x, a * vec.y, a * vec.z,a*vec.w); }
inline float Dot(Vector4& a, Vector4& b) { return a.x * b.x + a.y * b.y + a.z * b.z+a.w*b.w; }