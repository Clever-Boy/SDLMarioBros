#pragma once

#include <map>
#include <SDL2\SDL.h>

class Input {
public:

	/* void beginNewFrame
	* Function called at the begin of each frame to release keys not used anymore
	*/
	void beginNewFrame();

	/* void KeyUpEvent
	* Function called when a key is pressed
	*/
	void KeyUpEvent(const SDL_Event &event);

	/* void KeyUpEvent
	* Function called when a key is released
	*/
	void KeyDownEvent(const SDL_Event &event);

	/* bool isKeyHeld
	* Return if the key passed in parameter was pressed during the current frame
	*/
	bool isKeyHeld(SDL_Scancode key);

	/* bool wasKeyPressed
	* Return if the key passed in parameter is held during the current frame
	*/
	bool wasKeyPressed(SDL_Scancode key);

	/* void wasKeyReleased
	* Return if the key passed in parameter was released during the current frame
	*/
	bool wasKeyReleased(SDL_Scancode key);

private:
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;

};
