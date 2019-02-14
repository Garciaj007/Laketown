#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "Scene.h"
#include <memory>
#include <vector>

class TestScene : public Scene
{
private:
	//Members
	SDL_Window* window;

public:

	//Constructor
	TestScene(SDL_Window* window_) { window = window_; }
	~TestScene() { }

	//Member Methods
	bool OnCreate() { return true; }
	void OnDestroy() { } 
	void Update(const float time) { }
	void HandleEvents(const SDL_Event &e) { }
	void Render() { } 
};
#endif
