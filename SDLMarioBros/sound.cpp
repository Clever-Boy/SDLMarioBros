#include "sound.h"

Sound::Sound()
{
}

void Sound::AddSound(std::string filePath, std::string label)
{
	this->m_sounds.push_back(Mix_LoadWAV(filePath.c_str()));
	this->m_labelSounds[label] = m_sounds.size() - 1;
}

void Sound::RemoveSound(std::string label)
{
	this->m_sounds.erase(m_sounds.begin() + this->m_labelSounds.at(label));
}

void Sound::LoadMusic(std::string filePath)
{
	this->m_music = Mix_LoadMUS(filePath.c_str());
}

void Sound::PlaySound(std::string label)
{
	Mix_Chunk* tmp = m_sounds.at(m_labelSounds.at(label));
	if (tmp != NULL)
		Mix_PlayChannel(-1, tmp, 0);
}

void Sound::PlayMusic()
{
	if (this->m_music != NULL)
		Mix_PlayMusic(this->m_music, -1);
}
