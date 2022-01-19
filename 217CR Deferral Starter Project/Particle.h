#pragma once
#include "GameObject.h"
#include <iostream>

class Particle : public GameObject
{
	//Variables
private:
	float mass, radius;
	Vec3 acceleration;
	Vec3 velocity;
	Vec3 totalForce;
	Vec3 velocity1;
	Vec3 position1;
	Vec3 last_acceleration;
	Vec3 new_acceleration;
	Vec3 avg_acceleration;
public:

	//Constructors
	Particle(float m, Vec3 position);
	~Particle();

	//Functions
	void CalculateGravity(float deltaTime);
	void CalculateDrag(float  c);

	void Draw();
	void Update(float deltaTime);
};