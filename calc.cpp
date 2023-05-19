#include "calc.h"
#include <math.h>

float Calc::MakeLength(const MyVector2& v) {
	float result = static_cast<float>(sqrt(powf(v.x, 2) + powf(v.y, 2)));
	return result;
}
float Calc::MakeLength(const MyVector3& v) {
	float result = static_cast<float>(sqrt(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2)));
	return result;
}
float Calc::MakeLength(const MyVector2& v1, const MyVector2& v2) {
	float result = static_cast<float>(sqrt(powf(v1.x - v2.x, 2) + powf(v1.y - v2.y, 2)));
	return result;
}
float Calc::MakeLength(const MyVector3& v1, const MyVector3& v2) {
	float result = static_cast<float>(sqrt(powf(v1.x - v2.x, 2) + powf(v1.y - v2.y, 2) + powf(v1.z - v2.z, 2)));
	return result;
}

MyVector2 Calc::Normalize(const MyVector2& v) {
	float len = MakeLength(v);

	MyVector2 result = {};

	if (len != 0) {
		result = { v.x / len,v.y / len };
	}

	return result;
}

MyVector3 Calc::Normalize(const MyVector3& v) {
	float len = MakeLength(v);

	MyVector3 result = {};

	if (len != 0) {
		result = { v.x / len, v.y / len, v.z / len };
	}

	return result;
}

float Calc::Dot(const MyVector2& v1, const MyVector2& v2) {
	float dot = v1.x * v2.x + v1.y * v2.y;
	return dot;
}

float Calc::Dot(const MyVector3& v1, const MyVector3& v2) {
	float dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return dot;
}

float Calc::Outer(const MyVector2& v1, const MyVector2& v2) {
	float outer = v1.x * v2.y - v1.y * v2.x;
	return outer;
}

MyVector3 Calc::Cross(const MyVector3& v1, const MyVector3& v2) {
	MyVector3 result = { v1.y * v2.z - v1.z * v2.y,v1.z * v2.x - v1.x * v2.z ,v1.x * v2.y - v1.y * v2.x };
	return result;
}
