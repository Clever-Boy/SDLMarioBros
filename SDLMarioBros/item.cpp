#include "item.h"

Item::Item() { }

Item::Item(int x, int y, int id,Texture* tex)
{
	this->m_x = x;
	this->m_y = y;
	this->m_texture = tex;
	this->m_id = id;
}

Item::Item(int x, int y, int id)
{
	this->m_x = x;
	this->m_y = y;	
	this->m_id = id;
	// this->m_texture = yolo;
}

Item::~Item() { }

void Item::Draw(Graphics* graph)
{
	SDL_Rect destRect = { this->m_x, this->m_y, this->m_texture->GetWidth(),this->m_texture->GetHeight() };
	this->m_texture->Draw(graph, &destRect);
}

int Item::PickUp()
{
	return this->m_id;
}
