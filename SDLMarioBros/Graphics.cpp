#include "graphics.h"

Graphics::Graphics()
{
	printf("DEBUG : Creating instance of Graphics\n");
	this->m_window = SDL_CreateWindow("Super Mario Bros", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (this->m_window != NULL) {
		this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED);
		if (this->m_renderer != NULL)
		{
			SDL_SetRenderDrawColor(this->m_renderer, 255, 255, 255, 255);
		}
		else
			printf("ERROR : Cannot create renderer SDL_Error : %s", SDL_GetError());
	}
	else
		printf("ERROR : Cannot create window SDL_Error : %s", SDL_GetError());
}

Graphics::~Graphics()
{
	printf("DEBUG : Destroying instance of Graphics\n");
	SDL_DestroyRenderer(this->m_renderer);
	SDL_DestroyWindow(this->m_window);
}