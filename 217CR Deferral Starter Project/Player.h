#pragma once
#include "GameObject.h"
#include "Collider.h"
#include "SphereCollider.h"
#include <iostream>
//Playr class
class Player : public GameObject
{
private:
	//Variables
	float mass, radius;
	Vec3 acceleration;
	Vec3 velocity;
	Vec3 totalForce;
	Vec3 NewVelocity;
	Vec3 position1;
	Vec3 last_acceleration;
	Vec3 new_acceleration;
	Vec3 avg_acceleration;
	SphereCollider* collider;

public:

	//Constructors
	Player(float m, Vec3 position);
	~Player();

	//Functions
	void Draw();
	void CheckforInput(); //Keyboard controlls
	void MovementMethod(float deltaTime);
	void CalculateDrag(double c);// Drag force
	void Update(float deltaTime);

	SphereCollider* GetCollider(); // Collider SPHERE
};
