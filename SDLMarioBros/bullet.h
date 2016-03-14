#pragma once

#include "texture.h"
#include "timer.h"
#include "tile.h"

class Bullet
{
public:
	Bullet();
	Bullet(Graphics* graph, int x, int y, int id);
	void Draw(Graphics* graph, int camX, int camY);
	void Update(Tile* tilemap[]);
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	SDL_Rect GetRect();
	bool isEnd();

private:
	int m_x;
	int m_y;
	int m_velx;
	int m_vely;
	int m_id;
	bool m_end = false;
	Texture* m_texture;
	Timer m_timer;
};