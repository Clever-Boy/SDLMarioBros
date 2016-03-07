#include "animatedsprite.h"

AnimatedSprite::AnimatedSprite()
{

}

AnimatedSprite::AnimatedSprite(Graphics * graph, std::string filePath)
{
	this->LoadTexture(graph,filePath);
}

void AnimatedSprite::AddAnimation(int frames, int x, int y, int width, int height, std::string name)
{
	std::vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++)
	{
		SDL_Rect tmp;
		tmp.x = x + (i*width);
		tmp.y = y;
		tmp.w = width;
		tmp.h = height;
		rectangles.push_back(tmp);
	}
	this->m_animations.insert(std::pair < std::string, std::vector<SDL_Rect>>(name, rectangles));
}

void AnimatedSprite::PlayAnimation(std::string name)
{
	this->m_currentAnimation = name;
	this->m_frameIndex = 0;
}

void AnimatedSprite::ResetAnimations()
{
	this->m_animations.clear();
}

void AnimatedSprite::Draw(Graphics * graph, SDL_Rect* destRect)
{
	SDL_Rect yolo;
	if (this->m_currentAnimation == " ")
	{
		SDL_Rect tmp = { 0,0,16,16 };
		Texture::Draw(graph, destRect, &tmp);
	}
	else
		Texture::Draw(graph, destRect, &m_animations.at(this->m_currentAnimation).at(this->m_frameIndex));
}
