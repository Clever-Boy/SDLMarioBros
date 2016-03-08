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
	this->StopCurrentAnimation();
	this->m_currentAnimation = name;
	this->m_frameIndex = 0;
}

void AnimatedSprite::ResetAnimations()
{
	this->m_animations.clear();
}

void AnimatedSprite::StopCurrentAnimation()
{
	this->m_timer.Stop();
	this->m_frameIndex = 0;
}

std::string AnimatedSprite::GetCurrentAnimation()
{
	return this->m_currentAnimation;
}

void AnimatedSprite::Draw(Graphics * graph, SDL_Rect* destRect)
{
	if (this->m_currentAnimation == " ")
	{
		SDL_Rect tmp = { 0,0,16,16 };
		Texture::Draw(graph, destRect, &tmp);
	}
	else
		Texture::Draw(graph, destRect,&this->m_animations[this->m_currentAnimation][this->m_frameIndex]);
}

void AnimatedSprite::Draw(Graphics * graph, SDL_Rect* destRect, SDL_RendererFlip flip)
{
	if (this->m_currentAnimation == " ")
	{
		SDL_Rect tmp = { 0,0,16,16 };
		Texture::Draw(graph, destRect, &tmp,flip);
	}
	else
		Texture::Draw(graph, destRect, &this->m_animations[this->m_currentAnimation][this->m_frameIndex],flip);
}

void AnimatedSprite::Update()
{	
	if (!this->m_timer.isEnabled())
	{
		this->m_timer.Start(100);
	}
	if (this->m_timer.isDone())
	{
		if (this->m_frameIndex < this->m_animations[this->m_currentAnimation].size() - 1)
		{
			this->m_frameIndex++;
		}
		else
		{
			this->m_frameIndex = 0;
		}
		this->m_timer.Stop();
		this->m_timer.Start(100);	
	}
}
