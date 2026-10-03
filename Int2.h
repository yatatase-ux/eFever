#pragma once

class Int2
{
public:
	int x = 0;
	int y = 0;

	Int2();									//	コンストラクタ
	Int2(int x, int y);

	Int2& operator = (const Int2& f2);	//	= 演算子のオーバーロード

	Int2& operator += (const Int2& f2);	//	+= 演算子のオーバーロード
	Int2& operator -= (const Int2& f2);	//	-= 演算子のオーバーロード
	Int2& operator *= (const int f);	//	*= 演算子のオーバーロード
	Int2& operator /= (const int f);	//	/= 演算子のオーバーロード
};

//	+ 演算子のオーバーロード
Int2 operator + (const Int2& f2_1, const Int2& f2_2);
//	- 演算子のオーバーロード
Int2 operator - (const Int2& f2_1, const Int2& f2_2);
//	* 演算子のオーバーロード
Int2 operator * (const Int2& f2, const int f);
//	/ 演算子のオーバーロード
Int2 operator / (const Int2& f2, const int f);