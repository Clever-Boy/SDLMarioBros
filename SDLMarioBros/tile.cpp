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
}

void Tile::Draw()
{

}