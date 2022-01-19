#include "GroundCube.h"

//We can either hard code the values in GameObject (like in Cube())
//or
//We can use the GameEngine constructors to fill the values ( like in Cube(x, y, z, size))

GroundCube::GroundCube(Vec3 position,
	Vec3 colour,
	float _size, float _mass) :GameObject(position, colour)
{
	size = _size;
	mass = _mass;
}

//Position and colour a cube in the scene
void GroundCube::Draw()
{
	//Draw the Ground Cube
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glColor3f(colour.x, colour.y, colour.z);
	glutWireCube(size);
	glPopMatrix();
}

void GroundCube::Update(float deltaTime)
{
}