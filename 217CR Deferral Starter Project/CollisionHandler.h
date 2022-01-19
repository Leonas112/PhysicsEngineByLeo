#pragma once

#include "GameObject.h"
#include "Collider.h"
#include "VariablesOfCollision.h"

#include <iostream>
#include <cmath>
//Clas which handles all the collision detection and response
class CollisionHandler
{
public:
	//Variables
	Vec3 colour;
	//COnstructors, Destructors
	CollisionHandler();
	~CollisionHandler();
	//Functions
	void SphereCollideCheck(GameObject* a, GameObject* b);
	void BoxCollideCheck(GameObject* a, GameObject* b);
};
