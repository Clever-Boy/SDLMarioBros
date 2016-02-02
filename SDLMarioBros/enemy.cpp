#include "enemy.h"

Enemy::Enemy() {}

Enemy::Enemy(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

Enemy::~Enemy() {}

int Enemy::GetWidth()
{
	return this->m_sprite->GetWidth();
}

int Enemy::GetHeight()
{
	return this->m_sprite->GetHeight();
}

void Enemy::Update(Tile * tileMap[])
{
	this->m_x += this->m_velx;
	this->m_y += this->m_vely;

	SDL_Rect hitbox;

	if (this->m_velx > 0)
	{
		hitbox = { this->m_x + 1, this->m_y-2, this->GetWidth(), this->GetHeight() };
		for (int i = 0; i < TOTAL_TILES; i++)
		{
			if (tileMap[i]->CheckCollision(hitbox))
				this->m_velx = -(this->m_velx);
		}
	}
	else if (this->m_velx < 0)
	{
		hitbox = { this->m_x - 1, this->m_y - 2, this->GetWidth(), this->GetHeight() };
		for (int i = 0; i < TOTAL_TILES; i++)
		{
			if (tileMap[i]->CheckCollision(hitbox))
				this->m_velx = -(this->m_velx);
		}
	}
}
