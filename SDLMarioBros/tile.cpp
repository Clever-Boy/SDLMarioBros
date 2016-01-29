#include "tile.h"

Tile::Tile()
{
	this->m_value = 0;
	this->m_setTexture = NULL;
}

Tile::~Tile() { }

Tile::Tile(int x, int y, Texture* tex,int value)
{
	this->m_value = value;
	this->m_setTexture = tex;
	this->m_x = x;
	this->m_y = y;
}


void Tile::Draw(Graphics* graph)
{
	SDL_Rect destRect = { this->m_x*TILE_WIDTH,this->m_y*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT };
	SDL_Rect sourceRect = this->GetOffsetFromValue(this->m_value);
	m_setTexture->Draw(graph,&destRect,&sourceRect);
}

SDL_Rect Tile::GetOffsetFromValue(int value)
{
	SDL_Rect output;
	if (value == 0)
		output = { 0,0,0,0 };
	else {
		int maxX = this->m_setTexture->GetWidth() / TILE_WIDTH;
		int maxY = this->m_setTexture->GetHeight() / TILE_HEIGHT;

		output.w = TILE_WIDTH;
		output.h = TILE_HEIGHT;
		output.x = (value-1)%maxX * TILE_WIDTH;
		output.y = (value-1) / maxX * TILE_HEIGHT;
	}

	return output;

}
