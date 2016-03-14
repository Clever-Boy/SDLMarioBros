#include "util.h"

bool CheckCollision(SDL_Rect a, SDL_Rect b)
{
	int a_l = a.x;
	int a_r = a_l + a.w;
	int a_t = a.y;
	int a_b = a_t + a.h;

	int b_l = b.x;
	int b_r = b_l + b.w;
	int b_t = b.y;
	int b_b = b_t + b.h;

	if (b_b <= a_t)
	{
		return false;
	}

	if (b_t >= a_b)
	{
		return false;
	}

	if (b_r <= a_l)
	{
		return false;
	}

	if (b_l >= a_r)
	{
		return false;
	}

	return true;
}

bool isOutScreen(SDL_Rect camera, SDL_Rect object)
{
	if (object.x + object.w > camera.x + SCREEN_WIDTH || object.x + object.w < camera.x)
		return true;
	else
		return false;
}