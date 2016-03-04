#pragma once

#include "graphics.h"
#include "texture.h"
#include "timer.h"
#include "tile.h"
#include "util.h"
#include "sound.h"


const int PLAYER_SPEED = 1;
const int JUMP_STRENGTH = -2;

enum Player_PowerUpStates
{
	PLAYER_SMALL,
	PLAYER_GRAND,
	PLAYER_FIRE,
	PLAYER_STAR
};

class Player
{
public:
	// Basic functions (Construct/Destructors + Draw/Update)
	Player();
	Player(Graphics* graph,int x, int y);
	~Player();
	void Update(LevelContent &content, Graphics* graphics);
	void Draw(Graphics* graph, int camX, int camY);
	//void CheckCollision(Tile* tilemap[]);

	// Player's mouvements
	void Idle();
	void MoveLeft();
	void MoveRight();
	void Jump(Sound* sound);

	// Player's States
	bool isOnGround();
	bool isJumping();

	// Accessors
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	int GetScore();
	SDL_Rect GetRect();

	SDL_Rect GetOffset(int pwrup);

private:
	int m_x;
	int m_y;
	int m_velx;
	int m_vely;
	bool m_jumping;
	bool m_onGround;
	int m_pwrupState;
	Texture* m_sprite;
	Timer m_timer;
	int m_score = 0;
};