//
//  main.c
//  Pong
//
//  Created by Steven Gleed on 02/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#include <stdio.h>
#include "graphics.h"
#include "common.h"
#include "math.h"

const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH  = 800;

const char * DATA_DIR = "~/Documents/code/Pong/Pong/bmp/";

int main(int argc, const char * argv[])
{
	int id = 0;
	struct vector2 position;
	graphics_init("Pong", 640, 800);
	graphics_add_sprite(SPRITE_BACKGROUND, &id);
	graphics_add_sprite(SPRITE_BALL, &id);
	graphics_add_sprite(SPRITE_PADDLE, &id);
	graphics_add_sprite(SPRITE_WALL, &id);
	
	set_vector2(&position, 3, 150);
	bool running = true;
	SDL_Event event;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT ||
				event.key.keysym.sym == SDLK_ESCAPE) {
				running = false;
			}
		}
		graphics_begin_scene();
		graphics_draw_sprite(0, &position);
		graphics_end_scene();
	}
	
	graphics_shutdown();
	return 0;
}

