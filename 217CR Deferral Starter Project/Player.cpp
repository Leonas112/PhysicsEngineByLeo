#include "Player.h"

Player::Player(float m, Vec3 position) : GameObject(position, colour)
{
	mass = m;
	velocity = Vec3(0, 0, 0);
	acceleration = Vec3(0, 0, 0);
	totalForce = Vec3(0, 0, 0);
	radius = 1.f;
	collider = new SphereCollider(radius, position);
	collider->mass = mass;
	colour = Vec3(1.f, 1.f, 1.f);
}

Player::~Player()
{
}

void Player::Draw()
{
	//Drawing the player
	glPushMatrix();
	glColor3f(colour.x, colour.y, colour.z);
	glTranslatef(position.x, position.y, position.z);
	glutSolidSphere(radius, 10, 10);
	glPopMatrix();
	collider->Draw(); // Drawing the collider on the player
}

void Player::CheckforInput()
{
	if (GameObject::keys['w'] == true) // Go Forwards
		totalForce += Vec3(0, 0, -5);
	if (GameObject::keys['s'] == true) //Go Backwards
		totalForce += Vec3(0, 0, 5);
	if (GameObject::keys['a'] == true) //Go Left
		totalForce += Vec3(-5, 0, 0);
	if (GameObject::keys['d'] == true) //Go Right
		totalForce += Vec3(5, 0, 0);
	if (GameObject::keys['z'] == true) // Go Up
		totalForce += Vec3(0, 5, 0);
	if (GameObject::keys['x'] == true) // Go Down
		totalForce += Vec3(0, -5, 0);
}

void Player::MovementMethod(float deltaTime)
{
	//Velocity Verlet Movemnt method
	last_acceleration = acceleration;
	new_acceleration = totalForce / mass;
	avg_acceleration = (last_acceleration + new_acceleration) / 2;
	velocity += avg_acceleration * deltaTime - velocity * 0.00047;
	position += velocity * deltaTime + (5 * last_acceleration * deltaTime * deltaTime);
	NewVelocity = velocity + acceleration * deltaTime;
	collider->velocity = NewVelocity;
}

void Player::CalculateDrag(double c)
{
	//Gravity Calculation
	totalForce += -1.0f * c * velocity * velocity * normalize(velocity);
}

void Player::Update(float deltaTime)
{
	totalForce = Vec3(0, 0, 0);
	CheckforInput();
	MovementMethod(deltaTime);//Update Movement
	//CalculateDrag(0.47); // Apply drag force to the player
	collider->position = position;//Apply collider position to player position
}

SphereCollider* Player::GetCollider() // Function to provide access to the player collider for the collision calculation
{
	return collider;
}