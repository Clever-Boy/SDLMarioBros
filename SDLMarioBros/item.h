#pragma once

#include "texture.h"
#include "tile.h"

const int ITEM_WIDTH = 16;
const int ITEM_HEIGHT = 16;

enum Item_ID
{
	ITEM_COIN,
	ITEM_MUSHROOM,
	ITEM_FLOWER,
	ITEM_STAR,	
};

class Item
{
public:
	Item();
	Item(int x, int y, int id,Texture* tex);
	Item(int x, int y, int id,Graphics* graph);
	~Item();
	void Draw(Graphics* graph, int camX, int camY);
	void Update(Tile* tilemap[]);
	int PickUp();	// Return the ID of the item picked
	SDL_Rect GetRect();
	int GetWidth();
	int GetHeight();

private:
	Texture* m_texture;
	int m_x;
	int m_y;
	int m_id;
};