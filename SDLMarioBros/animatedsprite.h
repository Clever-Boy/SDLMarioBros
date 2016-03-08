#pragma once

#include <string>
#include <vector>

#include "graphics.h"
#include "texture.h"
#include "timer.h"

class AnimatedSprite : public Texture
{
public:
	AnimatedSprite();
	AnimatedSprite(Graphics* graph, std::string filePath);
	void AddAnimation(int frames, int x, int y, int width, int height, std::string name);
	void PlayAnimation(std::string name);
	void ResetAnimations();
	void StopCurrentAnimation();
	std::string GetCurrentAnimation();
	void Draw(Graphics* graph, SDL_Rect* destRect);
	void Draw(Graphics * graph, SDL_Rect * destRect, SDL_RendererFlip flip);
	void Update();


private:
	std::string m_currentAnimation = " ";
	int m_frameIndex = 0;
	std::map<std::string, std::vector<SDL_Rect>> m_animations;
	Timer m_timer;

};
