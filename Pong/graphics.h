//
//  graphics.h
//  Pong
//
//  Created by Steven Gleed on 03/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "common.h"
#include <SDL2/SDL.h>

#define MAX_SPRITES	4

struct gfx_context {
	SDL_Window *window;
	SDL_Renderer *renderer;
	int fullscreen;
	int screen_height;
	int screen_width;
	float scaling_factor;
	Uint32 clear_colour;
};

struct vector2;

struct gfx_context *gfx_settings;

bool  graphics_init(const char *title, const int h, const int w);
void  graphics_begin_scene();
void  graphics_draw_sprite(const int id, struct vector2 *pos, struct vector2 *dim);
void  graphics_end_scene();

bool  graphics_add_sprite(const char *filname, int *id);
void  graphics_remove_sprite(const int id);
void  graphics_set_screen_size(const int h, const int w);
void  graphics_set_screen_clear_colour(int r, int g, int b, int a);
void  graphics_shutdown();

#endif
