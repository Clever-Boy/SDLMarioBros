#pragma once

#include "graphics.h"
#include "texture.h"

class Player
{
public:
	Player();
	~Player();
	void Draw(Graphics graph);

private:
	int m_x;
	int m_y;
	Texture* m_sprite;
};