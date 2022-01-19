#include "Sphere.h"

Sphere::Sphere(float m, Vec3 position, Vec3 colour) :
	GameObject(position, colour)
{
	mass = m;
	velocity = Vec3(0, 0, 0);
	acceleration = Vec3(0, 0, 0);
	totalForce = Vec3(0, 0, 0);
	radius = 1.0f;
	moveSpeed = 1.0f;
	collider = new SphereCollider(radius, position);
	collider->mass = mass;
	restitution = 0.7f;
}

void Sphere::Draw()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glColor3f(colour.x, colour.y, colour.z);
	glutSolidSphere(radius, 10, 10); //if you'd rather it shows solid
	//glutWireSphere(radius, 10, 10);
	glBegin(GL_LINES);
	glVertex3f(position.x, position.y, position.z);
	glEnd();
	glPopMatrix();
	collider->Draw();
}

void Sphere::CalculateDrag(double c)
{
	totalForce += -1.0f * c * velocity * velocity * normalize(velocity);
}

void Sphere::CalculateForces()
{
	totalForce = Vec3(0, 0, 0);
	totalForce += Vec3(0, -9.8f, 0) * mass;
}

void Sphere::CalculateGravity(float deltaTime)
{
	totalForce += Vec3(0, -9.8f, 0) * mass;
}

SphereCollider* Sphere::GetCollider()
{
	return collider;
}

void Sphere::Update(float deltaTime)
{
	totalForce = Vec3(0, 0, 0);
	//CalculateDrag(0.47);
	//CalculateGravity(deltaTime);
	collider->position = position;
	last_acceleration = acceleration;
	new_acceleration = totalForce / mass;
	avg_acceleration = (last_acceleration + new_acceleration) / 2;
	velocity += avg_acceleration * deltaTime - velocity * 0.00047;
	position += velocity * deltaTime + (5 * last_acceleration * deltaTime * deltaTime);
	NewVelocity = velocity + acceleration * deltaTime;

	collider->velocity = NewVelocity;
}