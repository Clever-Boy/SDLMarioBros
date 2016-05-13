#pragma once

#include <SDL2\SDL.h>

#include "graphics.h"

bool CheckCollision(SDL_Rect a, SDL_Rect b);
bool isOutScreen(SDL_Rect camera, SDL_Rect object);

struct Vector2
{
	int x;
	int y;
};
