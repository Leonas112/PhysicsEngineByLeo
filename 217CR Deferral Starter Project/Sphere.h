#pragma once

#include "GameObject.h"
#include "SphereCollider.h"
#include "Mat3.h"
#include<iostream>

//Sphere class
class Sphere : public GameObject
{
	//Variables
public:
	float mass, inertia, restitution;
	Vec3 velocity;
	Vec3 acceleration;
	Vec3 totalForce;
	Vec3 avg_acceleration;
	Vec3 last_acceleration;
	Vec3 new_acceleration;
	Vec3 NewVelocity;

public:
	float radius;
	float moveSpeed;
	SphereCollider* collider;

	//Constructors, destructors

	Sphere(float m, Vec3 position, Vec3 colour); //or radius values);
	~Sphere() {}; //default destructor

	// Functions
	void Draw();
	void CalculateDrag(double  c);
	void CalculateGravity(float deltaTime);
	void Update(float deltaTime);
	void CalculateForces();
	SphereCollider* GetCollider();
};