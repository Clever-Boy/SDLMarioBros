#include "item.h"

Item::Item() { }

Item::Item(int x, int y, int id,Texture* tex)
{
	this->m_x = x;
	this->m_y = y;
	this->m_texture = tex;
	this->m_id = id;
}

Item::Item(int x, int y, int id, Graphics* graph)
{
	this->m_x = x;
	this->m_y = y;	
	this->m_id = id;
	this->m_texture = new Texture(graph->LoadTexture("sprites/items.png"));
}

Item::~Item() { }

void Item::Draw(Graphics* graph, int camX, int camY)
{
	SDL_Rect sourceRect = { this->m_id * ITEM_WIDTH,0,ITEM_WIDTH,ITEM_HEIGHT };
	SDL_Rect destRect = { this->m_x - camX, this->m_y - camY,ITEM_WIDTH, ITEM_HEIGHT};
	this->m_texture->Draw(graph, &destRect, &sourceRect);
}

int Item::PickUp()
{
	return this->m_id;
}

SDL_Rect Item::GetRect()
{
	SDL_Rect output = { this->m_x,this->m_y,16,16 };
	return output;
}

int Item::GetWidth()
{
	return this->m_texture->GetWidth();
}

int Item::GetHeight()
{
	return this->m_texture->GetHeight();
}
