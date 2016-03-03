#pragma once

#include <vector>
#include <map>

#include <SDL2\SDL_mixer.h>

//aka Sound Manager
class Sound
{
public:
	Sound();
	void AddSound(std::string filePath, std::string label);
	void RemoveSound(std::string label);
	void LoadMusic(std::string filePath);
	void PlaySound(std::string label);
	void PlayMusic();

private:
	Mix_Music* m_music;
	std::vector<Mix_Chunk*> m_sounds;
	std::map < std::string, int> m_labelSounds;
};