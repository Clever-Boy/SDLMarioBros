#pragma once

#include <stdio.h>

#include <SDL2\SDL.h>

#include "graphics.h"

class Game
{
public:
	Game();
	~Game();
	int SDLInit();
	void GameLoop();

private:
	Graphics* m_graphics;
};