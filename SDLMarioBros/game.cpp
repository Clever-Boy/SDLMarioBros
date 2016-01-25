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
	this->m_player = new Player(this->m_graphics, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
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
		Update();
		Draw();
	}
}

void Game::Draw()
{
	this->m_graphics->Clear();
	
	if (this->m_player != NULL)
		this->m_player->Draw(this->m_graphics);

	this->m_graphics->RenderPresent();
}

void Game::Update()
{

}