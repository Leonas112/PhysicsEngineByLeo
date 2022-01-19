#pragma once

#include "GameObject.h"
#include "AabbCollider.h"
#include "Mat3.h"

//A basic cube class derived from a game object
class Cube : public GameObject
{
public:
	//Variables
	Vec3 velocity;
	Vec3 acceleration;
	Vec3 totalForce;
	Vec3 avg_acceleration;
	Vec3 last_acceleration;
	Vec3 new_acceleration;
	Vec3 NewVelocity;
	float size, mass, restitution;
	AabbCollider* collider; // Collider AABB

	// Constructor, Destructor
	Cube(Vec3 position, Vec3 colour,
		float _size, float _mass); //pass in a position, colour, size, mass
	~Cube() {};

	//Functions --
	void Draw();
	AabbCollider* GetCollider();
	void Update(float deltaTime);
};