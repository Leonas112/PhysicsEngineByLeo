#pragma once
#include "GameObject.h"
#include "AabbCollider.h"
class PlayerCube : public GameObject
{
	//Variables
public:
	Vec3 velocity;
	Vec3 acceleration;
	Vec3 totalForce;
	Vec3 avg_acceleration;
	Vec3 last_acceleration;
	Vec3 new_acceleration;
	Vec3 NewVelocity;
	float size, mass, restitution;
	AabbCollider* collider; // Collider AABB

	//Constructor, Destructor
	PlayerCube(Vec3 position, Vec3 colour,
		float _size, float _mass); //pass in a position, colour and size, mass
	~PlayerCube(); //default destructor

	//Functions
	void CheckForInput(double c); // Keyboard controlls
	void Draw();
	AabbCollider* GetCollider();
	void Update(float deltaTime);
};
