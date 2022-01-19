#include "Particle.h"

//CONSTRUCTORS, DESTRUCTORS
Particle::Particle(float m, Vec3 position) : GameObject(position, colour)
{
	mass = m;
	velocity = Vec3(0, 0, 0);
	acceleration = Vec3(0, 0, 0);
	totalForce = Vec3(0, 0, 0);
	radius = 1.f;
	colour = Vec3(1.f, 0.f, 1.f);
}

Particle::~Particle()
{
}

//FUNCTIONS

void Particle::CalculateGravity(float deltaTime)
{
	//Gravity Calculation
	totalForce += Vec3(0, -9.8f, 0) * mass;
}

void Particle::CalculateDrag(float  c)
{
	//Drag force Calculation
	totalForce += -1 * c * velocity * velocity * position;
}

void Particle::Draw()
{
	//Drawing the particle
	glPushMatrix();
	glColor3f(colour.x, colour.y, colour.z);
	glBegin(GL_LINES);
	glVertex3f(position.x, position.y, position.z);
	glVertex3f(position.x + velocity.x, position.y + velocity.y, position.z + velocity.z);
	glEnd();
	glPopMatrix();
	//glutWireSphere(0.5f, 10, 10); //- if you'd rather see through it
}

void Particle::Update(float deltaTime)
{
	totalForce = Vec3(0, 0, 0);
	//CalculateGravity(deltaTime); //Gravity application
	CalculateDrag(0.47);//Applying drag force to the particle

	//Velocity Verlet Movemnt method
	last_acceleration = acceleration;
	position += velocity * deltaTime + (5 * last_acceleration * deltaTime * deltaTime);
	new_acceleration = totalForce / mass;
	avg_acceleration = (last_acceleration + new_acceleration) / 2;
	velocity += avg_acceleration * deltaTime - velocity * 0.00047;
}