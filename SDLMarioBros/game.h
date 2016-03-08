#pragma once

#include <stdio.h>

#include <fstream>

#include <SDL2\SDL.h>
#include <SDL2\SDL_mixer.h>

#include "graphics.h"
#include "player.h"
#include "tile.h"
#include "enemy.h"
#include "item.h"
#include "util.h"
#include "levelcontent.h"
#include "uimanager.h"
#include "sound.h"


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
	void UIInit();
	void SoundInit();

private:
	Graphics* m_graphics;
	Sound* m_sound;
	Player* m_player;
	SDL_Rect camera;
	LevelContent m_content;
	UIManager m_uimanager;
	Timer m_leveltimer;
};
