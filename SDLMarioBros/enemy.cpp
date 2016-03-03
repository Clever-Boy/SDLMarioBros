#include "enemy.h"

Enemy::Enemy() {}

Enemy::Enemy(int x, int y,Texture* tex)
{
	this->m_x = x;
	this->m_y = y;
	this->m_sprite = tex;
}

Enemy::Enemy(int x, int y, Graphics * graph)
{
	this->m_x = x;
	this->m_y = y;
	this->m_sprite = new Texture(graph->LoadTexture("sprites/goomba.png"));
}

Enemy::~Enemy() {}

int Enemy::GetX()
{
	return this->m_x;
}

int Enemy::GetY()
{
	return this->m_y;
}

int Enemy::GetWidth()
{
	return this->m_sprite->GetWidth();
}

int Enemy::GetHeight()
{
	return this->m_sprite->GetHeight();
}

SDL_Rect Enemy::GetRect()
{
	SDL_Rect output = { this->GetX(), this->GetY(), this->GetWidth(), this->GetHeight() };
	return output;
}

void Enemy::Draw(Graphics* graph,int camX, int camY)
{
	SDL_Rect destRect = { this->m_x - camX, this->m_y - camY,this->m_sprite->GetWidth(), this->m_sprite->GetHeight() };
	this->m_sprite->Draw(graph, &destRect);
}

void Enemy::Update(Tile * tileMap[])
{
	this->m_x += this->m_velx;
	this->m_y += this->m_vely;

	SDL_Rect leftHitBox = this->GetRect();
	leftHitBox.x = leftHitBox.x - 1;
	leftHitBox.y = leftHitBox.y;

	SDL_Rect rightHitBox = this->GetRect();
	rightHitBox.x = rightHitBox.x + 1;
	rightHitBox.y = rightHitBox.y;

	for (int i = 0; i < TOTAL_TILES; ++i)
	{
		if (tileMap[i]->CheckCollision(leftHitBox) && tileMap[i]->GetValue()!= 0 ||
			leftHitBox.x < 0 )
		{
			printf("Ennemy : Left Collider Triggered\n");
			this->m_velx = 1;
		}

		else if (tileMap[i]->CheckCollision(rightHitBox) && tileMap[i]->GetValue() != 0 ||
			rightHitBox.x > LEVEL_WIDTH)
		{
			printf("Enemy : Right Collider Triggered\n");
			this->m_velx = -1;
		}		
	}	
}
