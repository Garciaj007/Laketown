#include "GameManager.h"
#include "TestScene.h"
#include <iostream>
#include <SDL_net.h>

//Declaring Static Members
SDL_Renderer* GameManager::renderer; ///An instance of the SDL_Renderer

//Constructor
GameManager::GameManager() {
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;
}

// When Game is created
bool GameManager::OnCreate() {
	//Dimensions of Window
	const SDL_Point SCREENSIZE{ 1280, 720 };
	const SDL_Point SCREENPOS{ SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED };

	//Creating Window
	windowPtr = std::make_unique<Window>("Laketown", SCREENSIZE, SCREENPOS);

	//Default Library Check Statements
	if (OnInit() == false) {
		OnDestroy();
		return false;
	}

	//Check if Window ptr was Sucessful
	if (windowPtr == nullptr) {
		OnDestroy();
		return false;
	}

	//Check if Window Creation was Sucessful
	if (windowPtr->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	//Create Renderer
	renderer = SDL_CreateRenderer(windowPtr->GetSDL_Window(), -1, 0);

	//Check if Render ptr was Sucessful
	if (renderer == nullptr) {
		OnDestroy();
		return false;
	}

	//Check if Timer ptr was Sucessful
	timer = std::make_unique<Timer>();
	if (timer == nullptr) {
		OnDestroy();
		return false;
	}

	//Check if Scene ptr was Sucessful
	currentScene = std::make_unique<TestScene>(windowPtr->GetSDL_Window());
	if (currentScene == nullptr) {
		OnDestroy();
		return false;
	}

	//Check if Scene Creation was Sucessful
	if (currentScene->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}

bool GameManager::OnInit() {
	//Check if libraries are functioning conrrectly...
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	if (SDLNet_Init() < 0) {
		std::cerr << "SDLNet_Error" << SDLNet_GetError() << std::endl;
		return false;
	}

	//Add SDL_IMG SDL_Video SDL_TTF SDL_Mixer etc...

	return true;
}

/// Here's the whole game
void GameManager::Run() {
	timer->Start();
	while (isRunning) {
		if (SDL_PollEvent(&event) != 0) {

			///Close Application if Exit Button Pressed 
			if (event.type == SDL_QUIT)
				isRunning = false;

			currentScene->HandleEvents(event);
		}

		timer->UpdateFrameTicks();
		currentScene->Update(timer->GetDeltaTime());
		currentScene->Render();

		/// Keep the event loop running at a proper rate
		SDL_Delay(timer->GetSleepTime(FPS));
	}
}

GameManager::~GameManager() {}

void GameManager::OnDestroy() {
	SDL_DestroyRenderer(renderer);
	//Destroy Window
	windowPtr->OnDestroy();

	//Close Subsystems
	SDLNet_Quit();
	SDL_Quit();
}

