#include "player.h"

Player::Player()
{
	this->m_x = 0;
	this->m_y = 0;
	this->m_sprite = NULL;
}

Player::Player(Graphics* graph,int x, int y)
{
	this->m_x = x;
	this->m_y = y;
	this->m_sprite = new Texture(graph, "sprites/mario.png");
}

Player::~Player()
{
	//this->m_sprite->Free();
}

void Player::Draw(Graphics* graph)
{
	if (m_sprite != NULL) {
		SDL_Rect destRect = { this->m_x, this->m_y,this->m_sprite->GetWidth(), this->m_sprite->GetHeight() };
		this->m_sprite->Draw(graph, &destRect);
	}
}