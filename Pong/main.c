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
#include <seg_math.h>
#include <seg_state.h>
#include "world.h"
#include "input.h"

#define GAME_EXIT_CODE -1
#define GAME_RUNNING_CODE 1

int running = GAME_RUNNING_CODE;

static const unsigned char* SCREEN_MODES[] = {
	"640x480","800x600","1024x768","1280x1024","1366x768","1440x900","1600x900","1920x1080"
};

const int SCREEN_HEIGHT = 768;
const int SCREEN_WIDTH = 1366;

const char * DATA_DIR = "bmp/";

void parse_input(int input);

int main(int argc, char * argv[])
{
	state_init_system();
	//struct seg_state *current_state = (struct seg_state*)malloc(sizeof(struct seg_state));
	//state_enter(current_state);

	int id = 0;
	struct vector2 position;
	//SDL_Event event;

	graphics_init("Pong", SCREEN_HEIGHT, SCREEN_WIDTH);
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
		int event_code = 0;
		check_for_input(&event_code);
		parse_input(event_code);
		world_update();
		world_render();
	}

shutdown:
	world_shutdown();
	return 0;
}

void parse_input(int input)
{
	if (input == GAME_EXIT_CODE) {
		running = 0;
	}
}