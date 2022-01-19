#include "RigidBody.h"

RigidBody::RigidBody(float m, Vec3 position) : GameObject(position, colour)
{
	angularAcc = Vec3(0, 0, 0);
	angularVelocity = Vec3(0, 0, 0);
	radius = 1.f;
	colour = Vec3(1.f, 1.f, 1.f);
}

RigidBody::~RigidBody()
{
}

void RigidBody::Draw()
{
	glPushMatrix();
	glColor3f(colour.x, colour.y, colour.z);
	glTranslatef(position.x, position.y, position.z);
	glutSolidSphere(0.5f, 10, 10);
	glPopMatrix();
}

void RigidBody::CalculateForces()
{
	totalForce = Vec3(0, 0, 0);
	totalForce += Vec3(0, -9.8f, 0) * mass;
}

void RigidBody::Update(float deltaTime)
{
	totalForce = Vec3(0, 0, 0);
	CalculateForces();
}