#pragma once

#include "texture.h"

enum Item_ID
{
	ITEM_MUSHROOM,
	ITEM_FLOWER,
	ITEM_STAR,
	ITEM_COIN
};

class Item
{
public:
	Item();
	Item(int x, int y, int id,Texture* tex);
	~Item();
	void Draw(Graphics* graph);
	int PickUp();	// Return the ID of the item picked

private:
	Texture* m_texture;
	int m_x;
	int m_y;
	int m_id;
};