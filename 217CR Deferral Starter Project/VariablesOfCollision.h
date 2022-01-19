#pragma once
#include "Collider.h"
#include "Vec3.h"
#include "GameObject.h"

struct VariablesOfCollision
{
	Vec3 point, normal;
	float DepthOfCollision;
};