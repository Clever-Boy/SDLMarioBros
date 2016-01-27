#pragma once

#include "texture.h"

const int TILE_HEIGHT = 16;
const int TILE_WIDTH = 16;

class Tile
{
public:
	Tile();
	Tile(int x, int y, Texture* tex,int value);
	~Tile();
	void Draw();

private:
	Texture* m_setTexture;
	int m_value;
};