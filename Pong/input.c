#include "input.h"
#include <SDL2/SDL.h>

void init()
{
}

void check_for_input(int *event_type)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
			*event_type = -1;
			break;
		}

		const Uint8* states = SDL_GetKeyboardState(NULL);
		if (states[SDL_SCANCODE_UP] || states[SDL_SCANCODE_W]) {
			*event_type = (1 << 16) | 40;
			break;
		}
	}
}