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

private:
	bool m_enabled;
	int	 m_timeStart;
	int	 m_timeEnd;	
};