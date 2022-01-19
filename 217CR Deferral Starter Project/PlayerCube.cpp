#include "PlayerCube.h"

PlayerCube::PlayerCube(Vec3 position, Vec3 colour,
	float _size, float _mass) : GameObject(position, colour)
{
	//Variables definition , initialization
	mass = _mass;
	size = _size;
	restitution = 0.1f;
	velocity = Vec3(0, 0, 0);
	acceleration = Vec3(0, 0, 0);
	totalForce = Vec3(0, 0, 0);
	collider = new AabbCollider(size, position); // Add the collider to player cube
	collider->mass = mass; // Assign the colliders mass to the player cube mass
	collider->size = size; // Assign the colliders size to the player cube size
}

PlayerCube::~PlayerCube()
{
}

void PlayerCube::CheckForInput(double c)
{
	if (GameObject::specialKeys[GLUT_KEY_UP] == true) // Go forwards
		totalForce += Vec3(0, 0, -5);
	if (GameObject::specialKeys[GLUT_KEY_DOWN] == true) //Go backwards
		totalForce += Vec3(0, 0, 5);
	if (GameObject::specialKeys[GLUT_KEY_LEFT] == true) //Go left
		totalForce += Vec3(-5, 0, 0);
	if (GameObject::specialKeys[GLUT_KEY_RIGHT] == true) // Go right
		totalForce += Vec3(5, 0, 0);
	if (GameObject::keys['o'] == true) // Go up
		totalForce += Vec3(0, 5, 0);
	if (GameObject::keys['p'] == true) // Go down
		totalForce += Vec3(0, -5, 0);
}

void PlayerCube::Draw()
{
	//Draw the player cube
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glColor3f(colour.x, colour.y, colour.z);
	glutSolidCube(size); // SOLID cube
	glPopMatrix();
	collider->Draw(); // Draw the collider
}

AabbCollider* PlayerCube::GetCollider() // Provide acces to player cube's collider for the collider calculations
{
	return collider;
}

void PlayerCube::Update(float deltaTime)
{
	totalForce = Vec3(0, 0, 0);
	CheckForInput(0.47); //Movement update
	collider->position = position; // Assign collider's position to player cubes position
	last_acceleration = acceleration;
	new_acceleration = totalForce / mass;
	avg_acceleration = (last_acceleration + new_acceleration) / 2;
	velocity += avg_acceleration * deltaTime - velocity * 0.00047;
	position += velocity * deltaTime + (5 * last_acceleration * deltaTime * deltaTime);
	NewVelocity = velocity + acceleration * deltaTime;

	collider->velocity = NewVelocity;
}