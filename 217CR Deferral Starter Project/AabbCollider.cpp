#include "AabbCollider.h"

AabbCollider::AabbCollider(float _size, Vec3 pos)
{
	position = pos; // position
	size = _size; // Size
	colour = Vec3(1.f, 0.f, 1.0f); // Colour of the collider
	type = "Cube"; //Cube type notation
}

AabbCollider::~AabbCollider()
{
}

void AabbCollider::Draw()
{
	//Drawing the cube collider
	glPushMatrix();
	glColor3f(colour.x, colour.y, colour.z); // Colour
	glTranslatef(position.x, position.y, position.z);//Position
	glutWireCube(size);//Wire form cube instead of solid
	glPopMatrix();
}