#include "util.h"

bool CheckCollision(SDL_Rect a, SDL_Rect b)
{
	int a_l = a.x * a.w;
	int a_r = a_l + a.w;
	int a_t = a.y*a.h;
	int a_b = a_t + a.h;

	int b_l = b.x * b.w;
	int b_r = b_l + b.w;
	int b_t = b.y * b.h;
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