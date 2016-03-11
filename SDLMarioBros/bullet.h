#pragma once

#include "texture.h"
#include "timer.h"

class Bullet
{
public:
	Bullet();
	Bullet(Graphics* graph, int x, int y, int id);
	void Draw(Graphics* graph, int camX, int camY);
	void Update();
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();

private:
	int m_x;
	int m_y;
	int m_velx;
	int m_vely;
	int m_id;
	Texture* m_texture;
	Timer m_timer;
};