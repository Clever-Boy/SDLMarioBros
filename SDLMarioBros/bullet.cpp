#include "bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(Graphics * graph, int x, int y, int id)
{
	this->m_x = x;
	this->m_y = y;
	this->m_id = id;
	this->m_texture = new Texture(graph, "sprites/fireball.png");
	this->m_velx = 2;
	this->m_vely = 1;
}

void Bullet::Draw(Graphics* graph, int camX, int camY)
{
	SDL_Rect destRect = { this->m_x - camX,this->m_y - camY,this->GetWidth(),this->GetHeight() };
	this->m_texture->Draw(graph, &destRect);
}

void Bullet::Update(Tile* tilemap[])
{
	SDL_Rect groundHitBox = this->GetRect();
	groundHitBox.y += 1;

	for (int i = 0; i < TOTAL_TILES; i++)
	{
		if (tilemap[i]->CheckCollision(groundHitBox)  && tilemap[i]->GetValue() != 0 && this->m_vely == 1)
		{
			this->m_vely = -1;			
			break;
		}		
	}

	this->m_x += this->m_velx;
	this->m_y += this->m_vely;

}

int Bullet::GetX()
{
	return this->m_x;
}

int Bullet::GetY()
{
	return this->m_y;
}

int Bullet::GetWidth()
{
	return this->m_texture->GetWidth();
}

int Bullet::GetHeight()
{
	return this->m_texture->GetHeight();
}

SDL_Rect Bullet::GetRect()
{
	SDL_Rect output = { this->m_x, this->m_y, this->GetWidth(), this->GetHeight() };
	return output;
}

bool Bullet::isEnd()
{
	return this->end;
}
