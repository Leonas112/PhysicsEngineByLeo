#include <GL/glew.h>
#include <GL/freeglut.h>
#pragma comment(lib, "glew32.lib")

#include <iostream>
#include <vector>
#include <algorithm>

#include "GameEngine.h"

using namespace std;

// -- global variables --
GameEngine engine;

//Cube constructor - position, colour, size, mass
GameObject* cube1 = new Cube(Vec3(5, 0, 0), Vec3(2, 0, 0), 1.f, 1.f);
//Cube constructor - position, colour, size, mass
GameObject* cube2 = new Cube(Vec3(0, 1, -5), Vec3(2, 0, 0), 1.f, 1.f);
//Cube constructor - position, colour, size, mass
GameObject* cube3 = new Cube(Vec3(2, 2, -2), Vec3(0, 1, 0), 1.f, 1.f);
//Sphere constructor - mass, position, colour
GameObject* sphere2 = new Sphere(1.0f, Vec3(4, 4, 4), Vec3(5, 1, 2));
//GroundCube constructor - position, colour, size, mass
GameObject* Groundcube1 = new GroundCube(Vec3(5, 0, 0), Vec3(1, 1, 1), 100, 1.f);
//Particle constructor - mass, position
GameObject* particle = new Particle(1.0f, Vec3(1, 0, 1));
//Player constructor - mass, position
GameObject* player = new Player(1.0f, Vec3(-1, 3, 4));
//Player Cube constructor - position, colour, mass, size
GameObject* Pcube = new PlayerCube(Vec3(0, 0, 0), Vec3(1, 1, 1), 1.f, 1.f);

//Entry point into the program
int main(int argc, char** argv)
{
	//Initialaizing
	engine.InitEngine(argc, argv, "Yeti Engine", 800, 800);

	//Adding objects to the scene
	engine.AddGameObject(cube1);
	engine.AddGameObject(cube2);
	engine.AddGameObject(cube3);
	engine.AddGameObject(sphere2);
	engine.AddGameObject(Groundcube1);
	engine.AddGameObject(particle);
	engine.AddGameObject(player);
	engine.AddGameObject(Pcube);
	// Starting the engine
	engine.StartEngine();

	return 0;
}