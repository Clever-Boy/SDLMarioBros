#pragma once

#include "texture.h"

class Text
{
public:
	Text(std::string text, Graphics* graph, int x, int y);
	
	void Draw(Graphics* graph);
	void EditText(std::string newText);
	void Update(Graphics* graph);

	// Accessors
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();

	SDL_Rect GetRect();

private:
	int m_x;
	int m_y;
	Texture* m_texture;
	std::string m_text;
	bool textUpdated = false;

};