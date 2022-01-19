#pragma once
#include "Collider.h"
//AABB collider class used to draw the collider
class AabbCollider : public Collider
{
public:
	//Variables
	Vec3 colour;
	//Constructors
	AabbCollider(float size, Vec3 position);
	~AabbCollider();

	//Functions

	void Draw();
};