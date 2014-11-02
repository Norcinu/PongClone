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
#include "world.h"

const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH  = 800;

const char * DATA_DIR = "~/Documents/code/PongClone/Pong/bmp/";

int main(int argc, const char * argv[])
{
    int id = 0;
	int running = 1;
	struct vector2 position;
	SDL_Event event;
	
	graphics_init("Pong", 640, 800);
	if (!graphics_add_sprite(SPRITE_BACKGROUND, &id))
		goto shutdown;
	if (!graphics_add_sprite(SPRITE_BALL, &id))
		goto shutdown;
	if (!graphics_add_sprite(SPRITE_PADDLE, &id))
		goto shutdown;
	if (!graphics_add_sprite(SPRITE_WALL, &id))
		goto shutdown;
	
	set_vector2(&position, 0, 0);
	world_init();
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT ||
				event.key.keysym.sym == SDLK_ESCAPE) {
				running = 0;
			}
		}
        
        world_update();
        world_render();
	}
	
shutdown:
    world_shutdown();
    return 0;
}

