#include "player.h"

Player::Player()
{
	this->m_x = 0;
	this->m_y = 0;
	this->m_sprite = NULL;
}

Player::~Player()
{
	//this->m_sprite->Free();
}

void Player::Draw(Graphics graph)
{

}