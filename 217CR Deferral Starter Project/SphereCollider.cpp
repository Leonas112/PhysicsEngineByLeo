#include "SphereCollider.h"

SphereCollider::SphereCollider(float r, Vec3 pos)
{
	radius = r;
	position = pos;
	colour = Vec3(1.f, 0.f, 1.f); // Colour of the collider
	type = "Sphere";
}

SphereCollider::~SphereCollider()
{
}

void SphereCollider::Draw()
{
	//Draw the collider
	glPushMatrix();
	glColor3f(colour.x, colour.y, colour.z); //Magenta is the best debug colour!
	glTranslatef(position.x, position.y, position.z);
	glutWireSphere(radius, 10, 10);
	glPopMatrix();
}