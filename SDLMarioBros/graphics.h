#pragma once

#include <stdio.h>

#include <string>

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>


const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 240;

const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 720;

class Graphics
{
public:
	Graphics();
	~Graphics();
	SDL_Renderer* GetRenderer();
	SDL_Texture* LoadTexture(std::string filePath);	
	void RenderPresent();
	void Clear();
	void BlitTexture(SDL_Texture* texture, SDL_Rect* destRect);
	
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};