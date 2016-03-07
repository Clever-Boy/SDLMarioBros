#pragma once

#include <string>
#include <vector>

#include "graphics.h"
#include "texture.h"

class AnimatedSprite : public Texture
{
public:
	AnimatedSprite();
	AnimatedSprite(Graphics* graph, std::string filePath);
	void AddAnimation(int frames, int x, int y, int width, int height, std::string name);
	void PlayAnimation(std::string name);
	void ResetAnimations();
	void Draw(Graphics* graph, SDL_Rect* destRect);	
	void Update();


private:
	std::string m_currentAnimation = " ";
	int m_frameIndex = 0;
	std::map<std::string, std::vector<SDL_Rect>> m_animations;


};
