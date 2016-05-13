#pragma once

#include <SDL2\SDL.h>

class Timer
{
public:
	Timer();
	~Timer();
	void Start(int ms);
	void Pause();
	void UnPause();
	void Stop();
	bool isDone();
	bool isEnabled();
	int GetCurrentTime();

private:
	bool m_enabled;
	unsigned int m_timeStart;
	unsigned int m_timeEnd;	
};