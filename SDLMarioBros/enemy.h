#pragma once

#include "texture.h"
#include "tile.h"

class Enemy
{
public:
	Enemy();
	Enemy(int x, int y,Texture* tex);
	Enemy(int x, int y, Graphics* graph);
	~Enemy();
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	SDL_Rect GetRect();
	void Draw(Graphics* graph, int camX, int camY);
	void Update(Tile* tileMap[]);

private:
	int m_x;
	int m_y;
	int m_velx = -1;
	int m_vely = 0;
	Texture* m_sprite;
};