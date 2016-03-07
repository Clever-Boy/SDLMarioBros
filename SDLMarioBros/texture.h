#pragma once

#include <stdio.h>

#include <string>

#include <SDL2\SDL.h>

#include "graphics.h"

class Texture
{
public:
	Texture();
	Texture(Graphics* graph, std::string filePath);
	Texture(SDL_Texture* sdlTexture);
	~Texture();
	int GetWidth();
	int GetHeight();
	void Free();
	void LoadTexture(Graphics* graph, std::string filePath);
	void LoadTextureFromText(Graphics* graph, std::string text);
	void SetColor(int r, int g, int b);
	void Draw(Graphics* graph, SDL_Rect* destRect);
	void Draw(Graphics* graph, SDL_Rect* destRect, SDL_Rect* sourceRect);
	
protected:
	SDL_Texture* m_texture;
	int m_width;
	int m_height;
};