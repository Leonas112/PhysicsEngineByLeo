#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Vec3.h"
#include <string>

//Class used to store all the variables required in Collision detection adn response phase
class Collider
{
public:
	//Variables
	float radius, size, mass, inertia, acceleration, restitution;
	float DepthOfCollision;
	std::string type;
	Vec3 position;
	Vec3 velocity;
	Vec3 NewVelocity;
	//Constructors,destructors
	Collider();
	~Collider();
};
