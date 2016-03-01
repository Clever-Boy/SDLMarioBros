#include "text.h"

Text::Text(std::string text, Graphics* graph, int x, int y)
{
	this->m_x = x;
	this->m_y = y;
	this->m_texture = new Texture(graph->LoadTextureFromText(text));
}

void Text::Draw(Graphics* graph)
{
	SDL_Rect destRect = { this->m_x, this->m_y,this->m_texture->GetWidth(), this->m_texture->GetHeight() };
	this->m_texture->Draw(graph, &destRect);
}

void Text::EditText(std::string newText)
{
	this->m_text = newText;
	textUpdated = true;			// Need to render a new texture at the next update call
}

void Text::Update(Graphics* graph)
{
	if (textUpdated)			// If text different then render a new texture with the new text and free the old one
	{
		this->m_texture->Free();
		this->m_texture = new Texture(graph->LoadTextureFromText(m_text));
		textUpdated = false;
	}
}

int Text::GetX()
{
	return this->m_x;
}

int Text::GetY()
{
	return this->m_y;
}

int Text::GetWidth()
{
	return this->m_texture->GetWidth();
}

int Text::GetHeight()
{
	return this->m_texture->GetHeight();
}

SDL_Rect Text::GetRect()
{
	SDL_Rect output = { this->m_x, this->m_y, this->GetWidth(), this->GetHeight() };
	return output;
}
