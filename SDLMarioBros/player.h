#pragma once

#include "graphics.h"
#include "texture.h"

const int PLAYER_SPEED = 1;

class Player
{
public:
	Player();
	Player(Graphics* graph,int x, int y);
	~Player();
	void Update();
	void Draw(Graphics* graph, int camX, int camY);
	void Idle();
	void MoveLeft();
	void MoveRight();
	void Jump();
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();

private:
	int m_x;
	int m_y;
	int m_velx;
	int m_vely;
	Texture* m_sprite;
};