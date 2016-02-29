#include "player.h"

Player::Player()
{
	this->m_x = 0;
	this->m_y = 0;
	this->m_sprite = NULL;
	this->m_velx = 0;
	this->m_vely = 0;
	this->m_onGround = false;
	this->m_jumping = false;
	this->m_pwrupState = PLAYER_SMALL;
}

Player::Player(Graphics* graph,int x, int y)
{
	Player();
	this->m_x = x;
	this->m_y = y;
	this->m_sprite = new Texture(graph, "sprites/mario.png");
}

Player::~Player()
{
	//this->m_sprite->Free();
}

void Player::Update(LevelContent content)
{
	// Collision detection (to factorize into checkCollision function)
	SDL_Rect groundPlayerHitBox = { this->m_x,this->m_y + 1, this->GetWidth(), this->GetHeight() };
	for (int i = 0; i < TOTAL_TILES; ++i)
	{
		if (content.tileMap[i]->CheckCollision(groundPlayerHitBox) && content.tileMap[i]->GetValue() > 0) {
			this->m_onGround = true;
			break;
		}
		else
			this->m_onGround = false;
	}

	if (this->m_velx > 0) {
		groundPlayerHitBox = { this->m_x + 1,this->m_y - 2, this->GetWidth(), this->GetHeight() };
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			if (content.tileMap[i]->CheckCollision(groundPlayerHitBox) && content.tileMap[i]->GetValue() > 0) {
				this->m_velx = 0;
				break;
			}
		}
	}

	if (this->m_velx < 0) {
		groundPlayerHitBox = { this->m_x - 1,this->m_y-2, this->GetWidth(), this->GetHeight() };
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			if (content.tileMap[i]->CheckCollision(groundPlayerHitBox) && content.tileMap[i]->GetValue() > 0) {
				this->m_velx = 0;
				break;
			}
		}
	}

	if (this->isJumping() && !this->isOnGround())
	{
		groundPlayerHitBox = { this->m_x,this->m_y + JUMP_STRENGTH, this->GetWidth(), this->GetHeight() };
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			if (content.tileMap[i]->CheckCollision(groundPlayerHitBox) && content.tileMap[i]->GetValue() > 0) {
				this->m_jumping = false;
				this->m_timer.Stop();
				if (content.tileMap[i]->GetValue() == TILE_ITEM)
				{
					content.tileMap[i]->SetValue(28);
					content.items.push_back(Item(content.tileMap[i]->GetX()*TILE_WIDTH, content.tileMap[i]->GetY()+1*TILE_HEIGHT,
						this->m_pwrupState));
				}					
				break;
			}
		}
	}

	this->m_x += m_velx;
	this->m_y += m_vely;

	// Limit the mouvement of the player to the boundaries of the level
	if (this->m_x > LEVEL_WIDTH - this->GetWidth())
		this->m_x = LEVEL_WIDTH - this->GetWidth();
	if (this->m_x < 0)
		this->m_x = 0;
	
	if (this->m_y < 0)
		this->m_y = 0;

	if (this->m_timer.isDone()) {
		this->m_jumping = false;
		this->m_timer.Stop();
	}

	// Gravity
	if (!this->m_onGround && !this->m_jumping)
		this->m_vely = -JUMP_STRENGTH;
	else if (!this->m_jumping)
		this->m_vely = 0;

	SDL_Delay(8);			// Need to find another way to slow instead of delay
}

void Player::Draw(Graphics* graph, int camX, int camY)
{
	if (m_sprite != NULL) {
		SDL_Rect destRect = { this->m_x - camX, this->m_y - camY,this->m_sprite->GetWidth(), this->m_sprite->GetHeight() };
		this->m_sprite->Draw(graph, &destRect);
	}
}

void Player::Idle()
{
	this->m_velx = 0;
}

void Player::MoveLeft()
{
	this->m_velx = -PLAYER_SPEED;
}

void Player::MoveRight()
{
	this->m_velx = PLAYER_SPEED;
}

void Player::Jump()
{
	if (this->isOnGround() && !this->isJumping()) {
		this->m_vely += JUMP_STRENGTH;
		this->m_jumping = true;
		this->m_timer.Start(300);
	}
}

bool Player::isOnGround()
{
	return this->m_onGround;
}

bool Player::isJumping()
{
	return this->m_jumping;
}

int Player::GetX()
{
	return this->m_x;
}

int Player::GetY()
{
	return this->m_y;
}

int Player::GetWidth()
{
	return this->m_sprite->GetWidth();
}

int Player::GetHeight()
{
	return this->m_sprite->GetHeight();
}
