#pragma once

class IVector {
public:

	//Elementwise operations
	virtual IVector& operator+(const IVector&) = 0;
	virtual IVector& operator-(const IVector&) = 0;
	virtual IVector& operator*(const IVector&) = 0;
	virtual IVector& operator/(const IVector&) = 0;

	//Properites
	virtual float length() = 0;
	virtual IVector normed() = 0;
	virtual IVector reflect() = 0;
	virtual IVector zero() = 0;
};
