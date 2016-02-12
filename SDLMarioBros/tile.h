#pragma once

#include "texture.h"

const int TILE_HEIGHT = 16;
const int TILE_WIDTH = 16;
const int TOTAL_TILES = (LEVEL_WIDTH / TILE_WIDTH) * (LEVEL_HEIGHT / TILE_HEIGHT);

const int TILE_ITEM = 25;

class Tile
{
public:
	Tile();
	Tile(int x, int y, Texture* tex,int value);
	~Tile();
	int GetValue();
	int GetX();
	int GetY();
	void SetValue(int value);
	void Draw(Graphics* graph);
	void Draw(Graphics* graph, int camX, int camY);
	SDL_Rect GetOffsetFromValue(int value);
	bool CheckCollision(SDL_Rect sourceBox);

private:
	Texture* m_setTexture;
	int m_value;
	int m_x;
	int m_y;
};