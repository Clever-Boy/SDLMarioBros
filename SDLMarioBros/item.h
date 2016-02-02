#pragma once

#include "texture.h"

class Item
{
public:
	Item();
	Item(int x, int y, int id);
	~Item();
	void Draw(Graphics* graph);
	int PickUp();

private:
	Texture* m_texture;
	int m_x;
	int m_y;
	int m_id;
};