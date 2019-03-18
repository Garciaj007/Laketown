#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SDL.h>
#include <memory>
#include "Window.h"
#include "Timer.h"
#include "Scene.h"

class GameManager {
private:
	//Members
	const unsigned int FPS = 60; //Frames Per Second

	bool isRunning;///If Game is running

	std::unique_ptr<Window> windowPtr;
	std::unique_ptr<Timer> timer;
	std::unique_ptr<Scene> currentScene;///Curent Scene Attached

	bool isHost;
public:
	//Defining Static members 
	static SDL_Renderer* renderer;

	//Events & Input
	SDL_Event event;

	//Constructor
	GameManager();
	~GameManager();

	//Member Methods
	bool OnCreate();
	bool OnInit();
	void OnDestroy();
	void Run();
};



#endif // !GAMEMANAGER_H

