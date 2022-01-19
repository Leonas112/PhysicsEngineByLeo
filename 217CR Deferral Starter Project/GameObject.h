#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>
#include "Vec3.h"
#include "Collider.h"

#include <map>

class GameObject
{
public:
	//Variables
	Vec3 position;
	Vec3 colour;

	static std::map<char, bool> keys; //save key presses and let game objects access them
	static std::map<int, bool> specialKeys; //static = one instance of these variables for the whole class (top of .cpp)

	//Constructors, Destructors
	GameObject(Vec3 _position, Vec3 _colour); //pass in a position, colour
	~GameObject(); //default destructor

	// Functions
	//pure virtual so all classes that derive from this one need to include a definion for these
	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual Collider* GetCollider();
};