#pragma once

#include "GameObject.h"


class Plane : public GameObject
{
//A basic cube class derived from a game object
	public:
		// -- variables --
		float size;

		// -- constructors/destructors --
		Plane(); //default constructor - aka no values passed in (position at 0,0,0 - colour magenta - size 1)
		Plane(float _x, float _y, float _z, float _size);  //pass in a position and size
		Plane(float _x, float _y, float _z,
			float _r, float _g, float _b,
			float _size); //pass in a position, colour and size
		~Plane() {}; //default destructor

		// -- functions -- 
		//Need to give definions to GameObject's pure virtual functions
		virtual void Draw();
		virtual void Update(float deltaTime);
};

