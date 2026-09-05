#pragma once

class Float2
{
public:
	float x = 0.0f;
	float y = 0.0f;

	Float2();									//	コンストラクタ
	Float2(float x, float y);


	Float2& operator = (const Float2& f2);	//	= 演算子のオーバーロード

	Float2& operator += (const Float2& f2);	//	+= 演算子のオーバーロード
	Float2& operator -= (const Float2& f2);	//	-= 演算子のオーバーロード
	Float2& operator *= (const float f);	//	*= 演算子のオーバーロード
	Float2& operator /= (const float f);	//	/= 演算子のオーバーロード
};

//	+ 演算子のオーバーロード
Float2 operator + (const Float2& f2_1, const Float2& f2_2);
//	- 演算子のオーバーロード
Float2 operator - (const Float2& f2_1, const Float2& f2_2);
//	* 演算子のオーバーロード
Float2 operator * (const Float2& f2, const float f);
//	/ 演算子のオーバーロード
Float2 operator / (const Float2& f2, const float f);