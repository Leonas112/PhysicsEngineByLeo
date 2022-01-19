#pragma once
#include "GameObject.h"

class GroundCube : public GameObject
{
public:
	//Variables
	float size, mass;

	//Constructor, Destructor
	GroundCube(Vec3 position,
		Vec3 colour,
		float _size, float _mass);  //pass in a position, colour,  mass, size
	~GroundCube() {}; //default destructor

	//Functions
	void Draw();
	void Update(float deltaTime);
};
