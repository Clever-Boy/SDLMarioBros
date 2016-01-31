#pragma once

#include "texture.h"

const int TILE_HEIGHT = 16;
const int TILE_WIDTH = 16;

const int TOTAL_TILES = (LEVEL_WIDTH / TILE_WIDTH) * (LEVEL_HEIGHT / TILE_HEIGHT);

class Tile
{
public:
	Tile();
	Tile(int x, int y, Texture* tex,int value);
	~Tile();
	void Draw(Graphics* graph);
	void Draw(Graphics* graph, int camX, int camY);
	SDL_Rect GetOffsetFromValue(int value);

private:
	Texture* m_setTexture;
	int m_value;
	int m_x;
	int m_y;
};