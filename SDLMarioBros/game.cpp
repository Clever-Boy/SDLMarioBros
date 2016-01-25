#include "game.h"

Game::Game()
{
	printf("DEBUG : Creating instance of Game\n");
	if (this->SDLInit() == 0)
	{
		m_graphics = new Graphics();
		this->GameLoop();
	}		
}

Game::~Game()
{
	SDL_Quit();
}

// Initialize all SDL Subsystems
int Game::SDLInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("Error : Cannot init SDL SDL_Error : %s", SDL_GetError());
		return -1;
	}
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		printf("Error : Cannot init SDL_image SDL_Error : %s", IMG_GetError());
		return -1;
	}
	return 0;
}

void Game::GameLoop()
{
	bool quit = false;
	while (!quit)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
}

void Game::Draw()
{

}

void Game::Update()
{

}