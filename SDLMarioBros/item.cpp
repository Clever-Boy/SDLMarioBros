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
	this->m_texture = new Texture(graph->LoadTexture("sprites/tmp.png"));
}

Item::~Item() { }

void Item::Draw(Graphics* graph, int camX, int camY)
{
	SDL_Rect destRect = { this->m_x - camX, this->m_y - camY,this->m_texture->GetWidth(), this->m_texture->GetHeight() };
	this->m_texture->Draw(graph, &destRect);
}

int Item::PickUp()
{
	return this->m_id;
}

SDL_Rect Item::GetRect()
{
	SDL_Rect output = { this->m_x,this->m_y,this->GetWidth(),this->GetHeight() };
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
