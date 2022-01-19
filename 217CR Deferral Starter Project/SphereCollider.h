#pragma once

#include "Collider.h"
//Sphere collider class used to draw the collider
class SphereCollider : public Collider
{
public:
	Vec3 colour;

	//Constructors
	SphereCollider(float r, Vec3 pos);
	~SphereCollider();

	//Functions

	void Draw();
};