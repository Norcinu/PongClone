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
#include <direct.h>

const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH  = 800;

const char * DATA_DIR = "~/Documents/code/Pong/Pong/bmp/";

int main(int argc, const char * argv[])
{
	int id = 0;
	int running = 1;
	struct vector2 position;
	SDL_Event event;
	char buffer[1024];
	const char *current_dir = _getcwd(buffer,1024);

	graphics_init("Pong", 640, 800);
	if (!graphics_add_sprite(SPRITE_BACKGROUND, &id))
		goto shutdown;
	if (!graphics_add_sprite(SPRITE_BALL, &id))
		goto shutdown;
	if (!graphics_add_sprite(SPRITE_PADDLE, &id))
		goto shutdown;
	if (!graphics_add_sprite(SPRITE_WALL, &id))
		goto shutdown;
	
	set_vector2(&position, 3, 150);

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT ||
				event.key.keysym.sym == SDLK_ESCAPE) {
				running = 0;
			}
		}
		graphics_begin_scene();
		graphics_draw_sprite(0, &position);
		graphics_end_scene();
	}
	
shutdown:
	graphics_shutdown();
	return 0;
}

