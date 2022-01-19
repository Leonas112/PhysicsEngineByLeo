#include "Cube.h"

Cube::Cube(Vec3 position,
	Vec3 colour,
	float _size, float _mass) :
	GameObject(position, colour)
{
	//Initialize and assign all the variables for the cube
	mass = _mass;
	size = _size;
	restitution = 0.1f;
	velocity = Vec3(0, 0, 0);
	acceleration = Vec3(0, 0, 0);
	totalForce = Vec3(0, 0, 0);
	collider = new AabbCollider(size, position); // Adding collider to the Cube
	collider->mass = mass; // assigning colliders mass to the cubes mass
	collider->size = mass;// assigning colliders size to the cubes size
}

//Position and colour a cube in the scene
void Cube::Draw()
{
	//Drawing the cube
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glColor3f(colour.x, colour.y, colour.z);
	glutSolidCube(size); // Drawing a solid Cube
	glPopMatrix();
	collider->Draw();// Drawing the Collider on the cube
}

AabbCollider* Cube::GetCollider() // Function to take the collider for the collision detection adn response functions
{
	return collider;
}

void Cube::Update(float deltaTime)
{
	totalForce = Vec3(0, 0, 0);
	collider->position = position;//assigning colliders position to the cubes position
	//Velocity Verlet Movemnt method
	last_acceleration = acceleration;
	new_acceleration = totalForce / mass;
	avg_acceleration = (last_acceleration + new_acceleration) / 2;
	velocity += avg_acceleration * deltaTime - velocity * 0.00047;
	position += velocity * deltaTime + (5 * last_acceleration * deltaTime * deltaTime);
	NewVelocity = velocity + acceleration * deltaTime;

	collider->velocity = NewVelocity;// Assigning colliders velocity to the cubes New Velocity
}