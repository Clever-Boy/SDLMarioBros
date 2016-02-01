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
	this->m_player = new Player(this->m_graphics, 1, SCREEN_HEIGHT - TILE_HEIGHT*3);
	
	// Init the camera
	this->camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	camera.x = (m_player->GetX() + m_player->GetWidth() / 2) - SCREEN_WIDTH / 2;
	camera.y = (m_player->GetY() + m_player->GetHeight() / 2) - SCREEN_HEIGHT / 2;

	// FOR DEBUG ONLY : TO BE REMOVED
	Texture* testTex = new Texture(this->m_graphics, "tilesets/global.png");
	bool maploadSuccess = this->LoadTileMap(testTex);

	// If the map is load correctly, we launch the game loop
	if (maploadSuccess) {
		const Uint8* currentKeyState = NULL;
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
			currentKeyState = SDL_GetKeyboardState(NULL);
			this->HandleInput(currentKeyState);
			Update();
			Draw();
		}
	}
	else
		printf("FATAL ERROR : Loading of the map failed");
}

void Game::Draw()
{
	this->m_graphics->Clear();
	
	if (this->m_player != NULL)
		this->m_player->Draw(this->m_graphics,this->camera.x,this->camera.y);
	for (int i = 0; i < TOTAL_TILES; ++i) {
		if (this->m_tileMap[i]->CheckCollision(this->camera))
			this->m_tileMap[i]->Draw(this->m_graphics, this->camera.x, this->camera.y);
	}
	this->m_graphics->RenderPresent();
}

void Game::Update()
{
	// Update the camera
	this->camera.x = (m_player->GetX() + m_player->GetWidth() / 2) - SCREEN_WIDTH / 2;
	this->camera.y = (m_player->GetY() + m_player->GetHeight() / 2) - SCREEN_HEIGHT / 2;

	if (camera.x < 0) { camera.x = 0; }
	if (camera.y < 0) { camera.y = 0; }
	if (camera.x > LEVEL_WIDTH - camera.w)
	{
		camera.x = LEVEL_WIDTH - camera.w; 
	}
	if (camera.y > LEVEL_HEIGHT - camera.h){
		camera.y = LEVEL_HEIGHT - camera.h;
	}

	this->m_player->Update(this->m_tileMap);

}

void Game::HandleInput(const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_LEFT])
		this->m_player->MoveLeft();
	else if (keystate[SDL_SCANCODE_RIGHT])
		this->m_player->MoveRight();
	else
		this->m_player->Idle();
	if (keystate[SDL_SCANCODE_UP])
		this->m_player->Jump();

}

bool Game::LoadTileMap(Texture* tileset)
{
	bool success = true;

	std::ifstream map("1-1.map");
	
	if (!map)
	{
		printf("ERROR : Cannot read / open map file\n");
		success = false;
	}
	else
	{
		int x = 0;
		int y = 0;
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			int tile_value = 0;

			map >> tile_value;

			if (map.fail())
			{
				printf("Error loading map: Unexpected end of file!\n");
				success = false;
				break;
			}

			if (tile_value >= 0 && tile_value < 62)
				this->m_tileMap[i] = new Tile(x, y, tileset, tile_value);
			else
			{
				printf("Error loading map: Invalid tile type at %d!\n", i);
				success = false;
				break;
			}

			x++;

			if (x >= LEVEL_WIDTH / TILE_WIDTH) {
				x = 0;
				y++;
			}
		}
	}

	map.close();

	return success;
}
