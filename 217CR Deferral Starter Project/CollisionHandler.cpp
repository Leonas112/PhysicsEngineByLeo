#include "CollisionHandler.h"
#include "Sphere.h"
#include "Cube.h"

/*All The logic required to handle Collision Detectionand response for the objects are contained
inside of this class*/

//Constructor,Destructor
CollisionHandler::CollisionHandler()
{
}

CollisionHandler::~CollisionHandler()
{
}
//Function to check for collision between spheres and calculate the response
void CollisionHandler::SphereCollideCheck(GameObject* a,
	GameObject* b)
{
	Collider* x = a->GetCollider();//Add collider to GameObject a
	Collider* y = b->GetCollider();//Add collider to GameObject b

	if (y == nullptr || x == nullptr) { return; }//In case objects return nullptr
	float distance = sqrt(((y->position.x - x->position.x) * (y->position.x - x->position.x))   // Calculating the distance between objects
		+ ((y->position.y - x->position.y) * (y->position.y - x->position.y)) +
		((y->position.z - x->position.z) * (y->position.z - x->position.z)));
	float radii = x->radius + y->radius; // Calculating the sum of both objects radius

	if (distance <= radii) // if this condition is true collision is being detected
	{
		//Collision Response
		std::cout << distance << std::endl;
		Vec3 smth = (y->position - x->position);
		Vec3 normal = normalize(smth);
		float DepthOfCollision = radii - distance;
		Vec3 PointOfCollision = x->position + smth * x->radius / radii;
		float restitution = .7f;
		float impulse = -(dotproduct(y->velocity - x->velocity, normal * (1.0f * restitution)) // Calculating the impulse that happens upon collision of objects
			/
			(dotproduct(normal, normal) * ((1.0f / x->mass) + (1.0f / y->mass))));

		if (static_cast<Sphere*>(a) && static_cast<Sphere*>(b)) // Applying the impulse to the sphere objects when they collide
		{
			static_cast<Sphere*>(a)->velocity = x->velocity - impulse / x->mass * normal;
			static_cast<Sphere*>(b)->velocity = y->velocity + impulse / y->mass * normal;
		}

		return;
	}
	else
	{
		return;
	}
}

void CollisionHandler::BoxCollideCheck(GameObject* a, GameObject* b) // Collision Detection and Response between Cubes
{
	Collider* x = a->GetCollider(); // Taking the collider of the GameObject a
	Collider* y = b->GetCollider(); // Taking the collider of the GameObject b
	//initiating varibles
	Vec3 normal, smth;
	float restitution = 0.1f;
	smth = (b->position - a->position);
	normal = normalize(smth);
	if (y == nullptr || x == nullptr) { return; } //  in case both objects return null pointer

	//Checking for collision in X axis
	bool IsCollidingX = x->position.x + x->size >= y->position.x && y->position.x + y->size >= x->position.x;
	//Checking for collision in Y axis
	bool IsCollidingY = x->position.y + x->size >= y->position.y && y->position.y + y->size >= x->position.y;
	//Checking for collision in Z axis
	bool IsCollidingZ = x->position.z + x->size >= y->position.z && y->position.z + y->size >= x->position.z;

	if (IsCollidingX && IsCollidingY == true) // If Collision is true on all three axis (X,Y,Z) start collision response
	{
		if (IsCollidingX && IsCollidingZ == true)
		{
			if (IsCollidingY && IsCollidingZ == true)
			{
				std::cout << "Cubes are colliding" << std::endl; // Check that the collision is indeed happening
				float impulse = -(dotproduct(y->velocity - x->velocity, normal * (1.0f * restitution)) // Impulse calculation for collision response
					/
					(dotproduct(normal, normal) * ((1.0f / x->mass) + (1.0f / y->mass))));

				if (static_cast<Cube*>(a) && static_cast<Cube*>(b)) // If collision is true between two cubes apply impulse for those cubes
				{
					static_cast<Cube*>(a)->velocity = x->velocity - impulse / x->mass * normal;
					static_cast<Cube*>(b)->velocity = y->velocity + impulse / y->mass * normal;
				}
			}
			else { return; }
		}
		else { return; }
	}
}