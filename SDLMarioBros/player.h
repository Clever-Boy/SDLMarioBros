#pragma once

#include "graphics.h"
#include "texture.h"

const double PLAYER_SPEED = 1;

class Player
{
public:
	Player();
	Player(Graphics* graph,int x, int y);
	~Player();
	void Draw(Graphics* graph, int camX, int camY);
	void MoveLeft();
	void MoveRight();
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();

private:
	int m_x;
	int m_y;
	Texture* m_sprite;
};