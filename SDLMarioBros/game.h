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
#include "input.h"


enum class GameState { PLAY, PAUSE, EXIT };

class Game
{
public:
	Game();
	~Game();	

private:
	int SDLInit();
	void GameLoop();
	void Draw();		// Draw call for the graphics objet to render
	void Update();		// Update call for the game logic 
	void HandleInput();
	bool LoadLevel(Texture* tileset, Texture* enemyTexture);
	void UIInit();
	void SoundInit();
	void Pause();
	void Reset();

	GameState m_gamestate;
	Graphics* m_graphics;
	Sound* m_sound;
	Player* m_player;
	SDL_Rect camera;
	LevelContent m_content;
	UIManager m_uimanager;
	Timer m_leveltimer;
	Input m_input;
};
