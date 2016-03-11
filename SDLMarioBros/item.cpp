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
	if (id == 1)
		this->m_velx = 1;
}

Item::~Item() { }

void Item::Draw(Graphics* graph, int camX, int camY)
{
	SDL_Rect sourceRect = { this->m_id * ITEM_WIDTH,0,ITEM_WIDTH,ITEM_HEIGHT };
	SDL_Rect destRect = { this->m_x - camX, this->m_y - camY,ITEM_WIDTH, ITEM_HEIGHT};
	this->m_texture->Draw(graph, &destRect, &sourceRect);
}

void Item::Update(Tile* tileMap[])
{
	if (this->m_id == ITEM_MUSHROOM)
	{
		SDL_Rect leftHitBox = this->GetRect();
		leftHitBox.x = leftHitBox.x - 1;
		leftHitBox.y = leftHitBox.y;

		SDL_Rect rightHitBox = this->GetRect();
		rightHitBox.x = rightHitBox.x + 1;
		rightHitBox.y = rightHitBox.y;		
		
		SDL_Rect groundHitBox = { this->m_x,this->m_y+1, ITEM_WIDTH, ITEM_HEIGHT };
		bool onGround = false;

		for (int i = 0; i < TOTAL_TILES; i++)
		{
			if (tileMap[i]->CheckCollision(groundHitBox) && tileMap[i]->GetValue() != 0)
			{
				onGround = true;
				break;
			}
			else
				onGround = false;
		}
		if (!onGround)
			m_vely = 1;
		else
			m_vely = 0;

		this->m_x += m_velx;
		this->m_y += m_vely;

	}		
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
