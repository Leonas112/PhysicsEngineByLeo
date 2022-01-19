#pragma once

#include "GameObject.h"

struct PointsOfCollision
{
	float depth;
	Vec3 A;
	Vec3 B;
	Vec3 normal;
	bool IsColliding;
};

struct Transform
{
	Vec3 Position;
	Vec3 Scale;
	quaternion Rotation;
};
