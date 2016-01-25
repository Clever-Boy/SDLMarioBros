#pragma once

#include <stdio.h>

#include <SDL2\SDL.h>

#include "graphics.h"
#include "player.h"

class Game
{
public:
	Game();
	~Game();
	int SDLInit();
	void GameLoop();
	void Draw();		// Draw call for the graphics objet to render
	void Update();		// Update call for the game logic 
	void HandleInput(const Uint8 *keystate);

private:
	Graphics* m_graphics;
	Player* m_player;
	SDL_Rect camera;
};
