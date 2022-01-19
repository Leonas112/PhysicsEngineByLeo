#pragma once

#include "GameObject.h"

class RigidBody : public GameObject
{
	float inertia, orientation, mass, radius;
	Vec3 angularAcc;
	Vec3 angularVelocity;
	Vec3 totalForce;
public:

	//Constructors
	RigidBody(float m, Vec3 position);
	~RigidBody();

	//Funkctions

	void Draw();
	void CalculateForces();
	void Update(float);
};
