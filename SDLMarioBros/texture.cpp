#include "texture.h"

Texture::Texture()
{
	this->m_texture = NULL;
	this->m_height = 0;
	this->m_width = 0;
}

Texture::Texture(Graphics* graph, std::string filePath)
{
	Texture();
	this->LoadTexture(graph, filePath);
}

Texture::Texture(SDL_Texture* sdlTexture)
{
	this->m_texture = sdlTexture;
	SDL_QueryTexture(this->m_texture, (Uint32*)SDL_PIXELFORMAT_UNKNOWN, (int*)SDL_TEXTUREACCESS_STATIC, &this->m_width, &this->m_height);
}

Texture::~Texture()
{
	this->Free();
}

int Texture::GetWidth()
{
	return this->m_width;
}

int Texture::GetHeight()
{
	return this->m_height;
}

void Texture::Free()
{
	SDL_DestroyTexture(this->m_texture);
	this->m_texture = NULL;
}

void Texture::LoadTexture(Graphics* graph, std::string filePath)
{
	this->m_texture = graph->LoadTexture(filePath);
	SDL_QueryTexture(this->m_texture, (Uint32*)SDL_PIXELFORMAT_UNKNOWN, (int*)SDL_TEXTUREACCESS_STATIC, &this->m_width, &this->m_height);
}

void Texture::Draw(Graphics* graph,SDL_Rect* destRect)
{
	graph->BlitTexture(this->m_texture, destRect);
}

void Texture::Draw(Graphics * graph, SDL_Rect * destRect, SDL_Rect * sourceRect)
{
	graph->BlitTexture(this->m_texture, destRect, sourceRect);
}
