#pragma once

#include <stdio.h>

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>

const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 240;

class Graphics
{
public:
	Graphics();
	~Graphics();
	
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};