#pragma once

#include "Cube.h"
#include "Sphere.h"
#include "GroundCube.h"
#include "Particle.h"
#include "Player.h"
#include "PlayerCube.h"
#include "CollisionHandler.h"
#include "GameObject.h"
#include "Collider.h"
#include "CollisionInformation.h"

#include <vector>
//GameEngine class holding all the includes and the functions to run the engine
class GameEngine
{
private:
	//Varibles
	static std::vector<GameObject*> objects;
	static std::vector<CollisionInformation> CollisionOccured;
	static int oldTimeSinceStart;
	static int newTimeSinceStart;
	//Functions
	static void UpdateGame(void);
	static void DrawGame(void);
	static void CleanupEngine(void);
	static void ResizeWindow(int w, int h);

public:
	static void InitEngine(int argc, char** argv, const char* windowTitle, int width, int height);
	static void AddGameObject(GameObject*);
	static void StartEngine(void);
};
