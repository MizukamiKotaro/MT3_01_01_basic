#pragma once
#include"MyVector2.h"
#include"MyVector3.h"

class Calc
{
public:
	//長さを出す
	static float MakeLength(const MyVector2& v);
	static float MakeLength(const MyVector3& v);
	static float MakeLength(const MyVector2& v1, const MyVector2& v2);
	static float MakeLength(const MyVector3& v1, const MyVector3& v2);

	//正規化
	static MyVector2 Normalize(const MyVector2& v);
	static MyVector3 Normalize(const MyVector3& v);

	//内積
	static float Dot(const MyVector2& v1, const MyVector2& v2);
	static float Dot(const MyVector3& v1, const MyVector3& v2);

	//外積
	static float Outer(const MyVector2& v1, const MyVector2& v2);

	//クロス積
	static MyVector3 Cross(const MyVector3& v1, const MyVector3& v2);
};

