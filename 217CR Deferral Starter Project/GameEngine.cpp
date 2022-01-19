#include "GameEngine.h"

std::vector<GameObject*> GameEngine::objects;
std::vector<CollisionInformation> GameEngine::CollisionOccured;
int GameEngine::oldTimeSinceStart;
int GameEngine::newTimeSinceStart;
CollisionHandler x;

void GameEngine::UpdateGame(void)
{
	//Work out the delta time - the time between the last frame and this frame
	oldTimeSinceStart = newTimeSinceStart;
	newTimeSinceStart = glutGet(GLUT_ELAPSED_TIME);

	float deltaTime = (newTimeSinceStart - oldTimeSinceStart) / 1000.0f;

	// Collision detection
	for (int i = 0; i < objects.size(); ++i)
	{
		for (int j = i + 1; j < objects.size(); ++j)
		{
			if (static_cast<Sphere*>(objects[i]) && static_cast<Sphere*>(objects[j]))//Checking for sphere to sphere collision
			{
				x.SphereCollideCheck(objects[i], objects[j]);
			}
			if (static_cast<Cube*>(objects[i]) && static_cast<Cube*>(objects[j])) //Checking for AABB to AABB colision
			{
				x.BoxCollideCheck(objects[i], objects[j]);
			}
		}
	}

	//Update all our game objects
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Update(deltaTime);
	}
	glutPostRedisplay();
	GameEngine::CollisionOccured.clear();
}

void GameEngine::DrawGame(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// Position the objects for viewing
	gluLookAt(0.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//Draw all our game objects
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Draw();
	}

	glutSwapBuffers();
}

void GameEngine::CleanupEngine(void) // Clean up all the objects
{
	for (int i = objects.size() - 1; i >= 0; --i)
	{
		delete objects[i];
	}
	objects.clear();
}

void GameEngine::ResizeWindow(int w, int h) // Define the size of the window of the scene
{
	//OpenGL reshape
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0, (float)w / (float)h, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void GameEngine::InitEngine(int argc, char** argv, const char* windowTitle, int width, int height) // Initializing the engine
{
	//Setup for legacy OpenGL usage
	glutInit(&argc, argv);
	glutInitContextVersion(2, 0);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	//Window settings
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height); //800,800
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Yeti Engine");

	glewExperimental = GL_TRUE;
	glewInit();

	//Callbacks
	glutDisplayFunc(DrawGame);
	glutReshapeFunc(ResizeWindow);
	glutKeyboardFunc([](unsigned char key, int x, int y)
		{
			GameObject::keys[key] = true;
			//If you want to see keys pressed printed to the console
			//std::cout << "Key pressed: " << key << std::endl;

			switch (key)
			{
			case 27: // Esc key
				CleanupEngine();
				exit(0);
				break;
			default:
				break;
			}
		}
	);
	glutKeyboardUpFunc([](unsigned char key, int x, int y)
		{
			GameObject::keys[key] = false;
			//If you want to see keys pressed printed to the console
			//std::cout << "Key lifted: " << key << std::endl;
		}
	);
	glutSpecialFunc([](int key, int x, int y)
		{
			GameObject::specialKeys[key] = true;
			//If you want to see keys pressed printed to the console
			//std::cout << "Special Key pressed: " << key << std::endl;
		}
	);
	glutSpecialUpFunc([](int key, int x, int y)
		{
			GameObject::specialKeys[key] = false;
			//If you want to see keys pressed printed to the console
			//std::cout << "Special Key lifted: " << key << std::endl;
		}
	);
	glutIdleFunc(UpdateGame);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//setup();
}

void GameEngine::AddGameObject(GameObject* object) // Add objects
{
	objects.push_back(object);
}

void GameEngine::StartEngine(void)
{
	std::cout << "Press escape to exit the game. " << std::endl;
	std::cout << "To move player Sphere use WASD and Z,X to move up or down" << std::endl;
	std::cout << "To move player Cube use Arrows and O,P to move up or down" << std::endl;
	glutMainLoop();
}