#include "input.h"
#include "SDL2/SDL.h"

void Input::beginNewFrame()
{
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

void Input::KeyDownEvent(const SDL_Event &event)
{
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

void Input::KeyUpEvent(const SDL_Event &event)
{
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

bool Input::wasKeyPressed(SDL_Scancode scancode)
{
	return this->_pressedKeys[scancode];
}

bool Input::isKeyHeld(SDL_Scancode scancode)
{
	return this->_heldKeys[scancode];
}

bool Input::wasKeyReleased(SDL_Scancode scancode)
{
	return this->_releasedKeys[scancode];
}