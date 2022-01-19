#pragma once
#include <cmath>


class Vec3
{
public:
	float x, y, z;

	Vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	};

	Vec3(const float x, const float y, const float z) :
		x(x), y(y), z(z)
	{};

	Vec3 operator+=(const Vec3& a);
	Vec3 operator*=(const Vec3& a);
	Vec3 operator-=(const Vec3& a);
	Vec3 operator*(const Vec3& a);

	~Vec3() {};
};

inline Vec3 operator+(const Vec3& a, const Vec3& b)
{
	return Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
	return Vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline Vec3 operator*(const Vec3& a, float s)
{
	return Vec3(a.x * s, a.y * s, a.z * s);
}

inline Vec3 operator*(float s, const Vec3& a)
{
	return Vec3(s * a.x, s * a.y, s * a.z);
}

inline Vec3 operator^(const Vec3& a, float v)
{}

inline Vec3 Vec3::operator-=(const Vec3& a)
{
	this->x -= a.x;
	this->y -= a.y;
	this->z -= a.z;

	return *this;
}

inline Vec3 operator/(const Vec3& a, float s)
{
	return Vec3(a.x / s, a.y / s, a.z / s);
}
inline Vec3 operator/(const Vec3& a, const Vec3& b)
{
	return Vec3(a.x / b.x, a.y / b.y, a.z / b.z);
}

inline Vec3 operator+=(const Vec3& a, float s)
{
	return Vec3(a.x + (a.x + s), a.y + (a.y + s), a.z + (a.z + s));
}

inline Vec3 Vec3::operator+=(const Vec3& a)
{
	this->x += a.x;
	this->y += a.y;
	this->z += a.z;

	return *this;
}

inline Vec3 operator*=(const Vec3& a, float s)
{
	return Vec3(a.x * (a.x * s), a.y * (a.y * s), a.z * (a.z * s));
}

inline Vec3 Vec3::operator*=(const Vec3& a)
{
	this->x *= a.x;
	this->y *= a.y;
	this->z *= a.z;

	return *this;
}

inline Vec3 operator-=(const Vec3& a, float s)
{
	return Vec3(a.x - (a.x - s), a.y - (a.y - s), a.z - (a.z - s));
}

inline Vec3 Vec3::operator*(const Vec3& a)
{
	this->x* a.x;
	this->y* a.y;
	this->z* a.z;

	return *this;
}

inline double size(const Vec3& a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

inline Vec3 normalize(const Vec3& a)
{
	float b = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return Vec3(a.x / b, a.y / b, a.z / b);
}

inline float dotproduct(const Vec3& a, const Vec3& b)
{
	return float(a.x * b.x + a.y * b.y + a.z * b.z);
}

inline double len(const Vec3& a)
{
	return sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

inline float length(const Vec3& a)
{
	return sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

//inline float dist(Vec3& a, Vec3& b)
//{
//	return sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)) +
//		((b.z - a.z) * (b.z - a.z)));
//}

inline Vec3 cross(const Vec3& a, const Vec3& b)
{
	return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
