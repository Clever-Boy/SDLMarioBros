#include "timer.h"

Timer::Timer()
{
	this->m_enabled = false;
	this->m_timeStart = 0;
	this->m_timeEnd = 0;
}

Timer::~Timer() {}

void Timer::Start(int ms)
{
	this->m_enabled = true;
	this->m_timeStart = SDL_GetTicks();
	this->m_timeEnd = this->m_timeStart + ms;
}

void Timer::Pause()
{
	if (!this->isDone()) {
		this->m_enabled = false;
		this->m_timeStart = SDL_GetTicks();
	}
}

void Timer::UnPause()
{
	if (!this->isDone()) {
		this->m_timeEnd = SDL_GetTicks() + (this->m_timeEnd - this->m_timeStart);
		this->m_timeStart = SDL_GetTicks();
		this->m_enabled = true;
	}
}

void Timer::Stop()
{
	this->m_enabled = false;
	this->m_timeStart = 0;
	this->m_timeEnd = 0;
}

bool Timer::isDone()
{
	if (this->m_enabled) {
		if (SDL_GetTicks() >= this->m_timeEnd)
			return true;
		else
			return false;
	}
	else
		return false;
}

int Timer::GetCurrentTime()
{
	return (int) (this->m_timeEnd - SDL_GetTicks()) / 1000;
}
