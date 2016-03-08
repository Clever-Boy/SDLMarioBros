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
			SDL_SetRenderDrawColor(this->m_renderer, 104, 140, 255, 255);
		}
		else
			printf("ERROR : Cannot create renderer SDL_Error : %s", SDL_GetError());
	}
	else
		printf("ERROR : Cannot create window SDL_Error : %s", SDL_GetError());
	this->m_font = TTF_OpenFont("fonts/Pixel Emulator.otf", 8);
	if (this->m_font == NULL)
		printf("ERROR : Cannot load global font");
	
}

Graphics::~Graphics()
{
	printf("DEBUG : Destroying instance of Graphics\n");
	SDL_DestroyRenderer(this->m_renderer);
	SDL_DestroyWindow(this->m_window);
}

SDL_Renderer* Graphics::GetRenderer() { return this->m_renderer; }

SDL_Texture * Graphics::LoadTexture(std::string filePath)
{
	SDL_Texture* outputTexture = NULL;

	// If the image was previously load then
	if (this->m_atlas.count(filePath) == 0)
	{
		SDL_Surface* tmpSurface = NULL;
		tmpSurface = IMG_Load(filePath.c_str());
		if (tmpSurface == NULL)
			printf("ERROR : Cannot load image %s into surface SDL_Error : %s\n", filePath, SDL_GetError());
		else
		{
			outputTexture = SDL_CreateTextureFromSurface(this->m_renderer, tmpSurface);
			if (outputTexture == NULL)
				printf("ERROR : Cannot create texture from surface SDL_Error : %s\n", SDL_GetError());
			SDL_FreeSurface(tmpSurface);
			this->m_atlas[filePath] = outputTexture;
			tmpSurface = NULL;
			return this->m_atlas[filePath];
		}
	}
	else
		return this->m_atlas[filePath];
}

SDL_Texture * Graphics::LoadTextureFromText(std::string text)
{
	SDL_Color color = { 255,255,255};
	SDL_Surface* tmpSurface = TTF_RenderText_Solid(this->m_font, text.c_str(), color);
	SDL_Texture* output = NULL;
	if (tmpSurface == NULL)
	{
		printf("ERROR : Cannot create surface from text SDL_Error : %s", SDL_GetError());
	}
	else
	{
		output = SDL_CreateTextureFromSurface(this->m_renderer, tmpSurface);
		if (output == NULL)
			printf("ERROR : Cannot create texture from surface SDL_Error : %s", SDL_GetError());
	}
	return output;
}

void Graphics::Clear() { SDL_RenderClear(this->m_renderer); }

void Graphics::RenderPresent() { SDL_RenderPresent(this->m_renderer); }

void Graphics::BlitTexture(SDL_Texture* texture, SDL_Rect* destRect)
{
	if (SDL_RenderCopy(this->m_renderer, texture, NULL, destRect) < 0)
		printf("ERROR : Cannot render texture SDL_Error : %s",SDL_GetError());
}

void Graphics::BlitTexture(SDL_Texture * texture, SDL_Rect * destRect, SDL_RendererFlip flip)
{
	if (SDL_RenderCopyEx(this->m_renderer,texture,NULL,destRect,NULL,NULL,flip) < 0)
		printf("ERROR : Cannot render texture SDL_Error : %s", SDL_GetError());
}

void Graphics::BlitTexture(SDL_Texture* texture, SDL_Rect* destRect,SDL_Rect* sourceRect)
{
	if (SDL_RenderCopy(this->m_renderer, texture, sourceRect, destRect) < 0)
		printf("ERROR : Cannot render texture SDL_Error : %s", SDL_GetError());
}

void Graphics::BlitTexture(SDL_Texture * texture, SDL_Rect * destRect, SDL_Rect * sourceRect, SDL_RendererFlip flip)
{
	if (SDL_RenderCopyEx(this->m_renderer, texture, sourceRect, destRect, NULL, NULL, flip) < 0)
		printf("ERROR : Cannot render texture SDL_Error : %s", SDL_GetError());
}
