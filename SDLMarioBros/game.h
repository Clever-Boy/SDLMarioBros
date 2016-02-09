#pragma once

#include <stdio.h>

#include <fstream>

#include <SDL2\SDL.h>

#include "graphics.h"
#include "player.h"
#include "tile.h"
#include "enemy.h"
#include "item.h"
#include "util.h"

const int MAX_ENEMIES = 24;
const int MAX_ITEMS = 24;

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
	bool LoadLevel(Texture* tileset,Texture* enemyTexture);

private:
	Graphics* m_graphics;
	Player* m_player;
	SDL_Rect camera;
	LevelContent m_content;
	Tile* m_tileMap[TOTAL_TILES];	
	Enemy* m_enemies[MAX_ENEMIES];
	Item* m_items[MAX_ITEMS];
};
