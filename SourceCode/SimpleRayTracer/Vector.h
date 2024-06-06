#pragma once
#include <vector>

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

//Matrices to respresent transformations
//TODO: Write set row/col functions
class Matrix3 {
private:
	std::vector<float> data; //Row major storage
public:
	
	Matrix3()
	{
		for (int i = 0; i < 9; i++)
			data.push_back(0);
	}

	Matrix3(Vector3& c1, Vector3& c2, Vector3& c3)
	{
		//row1
		data.push_back(c1.x);
		data.push_back(c2.x);
		data.push_back(c3.x);
		//row2
		data.push_back(c1.y);
		data.push_back(c2.y);
		data.push_back(c3.y);
		//row3
		data.push_back(c1.z);
		data.push_back(c2.z);
		data.push_back(c3.z);

	}

	Vector3 row1() { return Vector3(data[0],data[1],data[2]); }
	Vector3 row2() { return Vector3(data[3], data[4], data[5]); }
	Vector3 row3() { return Vector3(data[6], data[7], data[8]); }

	Vector3 col1() { return Vector3(data[0], data[3], data[6]); }
	Vector3 col2() { return Vector3(data[1], data[4], data[7]); }
	Vector3 col3() { return Vector3(data[2], data[5], data[8]); }

	Matrix3 T() {
		Vector3 r1 = row1();
		Vector3 r2 = row2();
		Vector3 r3 = row3();		
		return Matrix3(r1, r2, r3);
	}

	//Rotation in radians
	static Matrix3 CreateRotation(float x,float y, float z)
	{
		//X rotation
		Vector3 xr1(0, 0, 1);
		Vector3 xr2(0, cosf(x), -sinf(x)); 
		Vector3 xr3(0, sin(x), cos(x));
		Matrix3 rotX(xr1,xr2,xr3);
		
		//Y rotation
		Vector3 yr1(cosf(y),0, sinf(y));
		Vector3 yr2(0,1,0);
		Vector3 yr3(-sinf(y),0,cosf(y));
		Matrix3 rotY(yr1, yr2, yr3);

		//Z rotation
		Vector3 zr1(cosf(z), -sinf(z), 0);
		Vector3 zr2(sinf(z), cos(z), 0);
		Vector3 zr3(0, 0, 1);
		Matrix3 rotZ(zr1, zr2, zr3);

		return rotZ * rotY * rotX;
	}

	static Matrix3 Identity()
	{
		Vector3 r1(1, 0, 0);
		Vector3 r2(0, 1, 0);
		Vector3 r3(0, 0, 1);
		return Matrix3(r1, r2, r3);
	}

	//Matrix multiplication
	Matrix3 operator*(Matrix3& other){
		Vector3 r1 = row1();
		Vector3 r2 = row2();
		Vector3 r3 = row3();

		Vector3 c1 = other.col1();
		Vector3 c2 = other.col2();
		Vector3 c3 = other.col3();

		Vector3 r1new(Dot(r1, c1), Dot(r1, c2), Dot(r1, c3));
		Vector3 r2new(Dot(r2, c1), Dot(r2, c2), Dot(r2, c3));
		Vector3 r3new(Dot(r3, c1), Dot(r3, c2), Dot(r3, c3));
		return Matrix3(r1new,r2new,r3new).T();
	}

	//Scalar multiplication
	Matrix3 operator*(float a)
	{
		Vector3 c1 = col1() * a;
		Vector3 c2 = col2() * a;
		Vector3 c3 = col3() * a;
		return Matrix3(c1, c2, c3);
	}
};

class Matrix4 {
private:
	std::vector<float> data; //Row major storage
public:

	Matrix4()
	{
		for (int i = 0; i < 16; i++)
			data.push_back(0);
	}

	//Constructor takes columns 
	Matrix4(Vector4& c1, Vector4& c2, Vector4& c3,Vector4& c4)
	{
		//row1
		data.push_back(c1.x);
		data.push_back(c2.x);
		data.push_back(c3.x);
		data.push_back(c4.x);
		//row2
		data.push_back(c1.y);
		data.push_back(c2.y);
		data.push_back(c3.y);
		data.push_back(c4.y);
		//row3
		data.push_back(c1.z);
		data.push_back(c2.z);
		data.push_back(c3.z);
		data.push_back(c4.z);
		//row4
		data.push_back(c1.w);
		data.push_back(c2.w);
		data.push_back(c3.w);
		data.push_back(c4.w);

	}

	Matrix4(Matrix3& mat)
	{
		Vector4 r1 = Vector4(mat.row1());
		Vector4 r2 = Vector4(mat.row2());
		Vector4 r3 = Vector4(mat.row3());
		Vector4 r4 = Vector4(0, 0, 0, 1);

		r1.w = 0;
		r2.w = 0;
		r3.w = 0;

		data.push_back(r1.x);
		data.push_back(r1.y);
		data.push_back(r1.z);
		data.push_back(r1.w);

		data.push_back(r2.x);
		data.push_back(r2.y);
		data.push_back(r2.z);
		data.push_back(r2.w);

		data.push_back(r3.x);
		data.push_back(r3.y);
		data.push_back(r3.z);
		data.push_back(r3.w);

		data.push_back(r4.x);
		data.push_back(r4.y);
		data.push_back(r4.z);
		data.push_back(r4.w);
	}

	//Useful when wanting to define translation
	Matrix4(Matrix3 mat, Vector3 vec) : Matrix4(mat)
	{
		data[3] = vec.x;
		data[7] = vec.y;
		data[11] = vec.z;
	}

	Vector4 row1() { return Vector4(data[0], data[1], data[2], data[3]); }
	Vector4 row2() { return Vector4(data[4], data[5], data[6],data[7]); }
	Vector4 row3() { return Vector4(data[8], data[9], data[10],data[11]); }
	Vector4 row4() { return Vector4(data[12], data[13], data[14], data[15]); }

	Vector4 row1() { return Vector4(data[0], data[4], data[8], data[12]); }
	Vector4 row2() { return Vector4(data[1], data[5], data[9], data[13]); }
	Vector4 row3() { return Vector4(data[2], data[6], data[10], data[14]); }
	Vector4 row4() { return Vector4(data[3], data[7], data[11], data[15]); }

	static Matrix4 CreateTranslation(Vector3 delta)
	{	
		Matrix3 id = Matrix3::Identity();
		return Matrix4(id,delta);
	}

	static Matrix4 CreateRotation(float x, float y, float z)
	{
		Matrix3 rot = Matrix3::CreateRotation(x, y, z);
		return Matrix4(rot);
	}

	static Matrix4 Identity()
	{
		Vector4 c1(1, 0, 0,0);
		Vector4 c2(0, 1, 0,0);
		Vector4 c3(0, 0, 1,0);
		Vector4 c4(0, 0, 0, 1);
		return Matrix4(c1, c2, c3,c4);
	}

	Matrix4 T() {
		Vector4 r1 = row1();
		Vector4 r2 = row2();
		Vector4 r3 = row3();
		Vector4 r4 = row4();
		return Matrix4(r1, r2, r3,r4);
	}
};