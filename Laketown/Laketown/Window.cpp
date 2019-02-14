#include "Window.h"
#include <SDL.h>
#include <iostream>

Window::Window(const char* name_, SDL_Point size_, SDL_Point position_) {
	screenSurface = nullptr;
	window = nullptr;
	size = size_;
	position = position_;
	name = name_;
}

bool Window::OnCreate() {
	window = SDL_CreateWindow(name, position.x, position.y, size.x, size.y, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	screenSurface = SDL_GetWindowSurface(window);
	if (screenSurface == nullptr) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void Window::OnDestroy() {
	/// Kill the surface first
	if (screenSurface) {
		SDL_FreeSurface(screenSurface);
	}

	/// Now kill the window
	if (window) {
		SDL_DestroyWindow(window);
	}
}

Window::~Window() {}

SDL_Window* Window::GetSDL_Window() {
	return window;
}