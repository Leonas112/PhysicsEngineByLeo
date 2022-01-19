#pragma once
#include "Vec3.h"
//Matrix 3x3 class
class Mat3
{
public:
	float a, b, c, d, e, f, g, h, i;

	Mat3()
	{
		a = 1.0f; b = 0.0f; c = 0.0f;
		d = 0.0f; e = 1.0f; f = 0.0f;
		g = 0.0f; h = 0.0f; i = 1.0f;
	}

	Mat3(const float a, const float b, const float c,
		const float d, const float e, const float f,
		const float g, const float h, const float i) :

		a(a), b(b), c(c),
		d(d), e(e), f(f),
		g(g), h(h), i(i)
	{};

	//TRANSLATION MATRIX
	Mat3(const float x, const float y, const float z)
	{
		a = 1.0f; b = 0.0f; c = x;
		d = 0.0f; e = 1.0f; f = y;
		g = 0.0f; h = 0.0f; i = z;
	}

	~Mat3() {};
};
