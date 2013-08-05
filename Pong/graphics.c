//
//  graphics.c
//  Pong
//
//  Created by Steven Gleed on 03/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#include <stdio.h>
#include "graphics.h"
#include "sprite.h"
#include "common.h"

struct sprite sprite_list[MAX_SPRITES];
static int sprite_count = 0;

int graphics_init(const char *title, int h, int w) {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return 0;

	gfx_settings = (struct gfx_context *)malloc(sizeof(struct gfx_context));
	if (gfx_settings == NULL) {
		return 0;
	}
	
	SDL_Rect screen_dimensions;
	SDL_GetDisplayBounds(0, &screen_dimensions);
	int mid_x = (screen_dimensions.w / 2) - (w / 2);
	int mid_y = (screen_dimensions.h / 2) - (h / 2);

	Uint32 render_ops = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
	gfx_settings->screen_height = h;
	gfx_settings->screen_width = w;
	gfx_settings->clear_colour = 0;
	gfx_settings->window = SDL_CreateWindow(title, mid_x, mid_y, w, h,
						SDL_WINDOW_OPENGL);
	gfx_settings->renderer = SDL_CreateRenderer(gfx_settings->window, -1,
						    render_ops);
	SDL_SetRenderDrawColor(gfx_settings->renderer, 128, 129, 8, 0);
	
	return 1;
}

void graphics_begin_scene() {
	SDL_RenderClear(gfx_settings->renderer);
}

void graphics_draw_sprites() { //(const int id) {
	SDL_Rect pos;
	pos.x = 0;
	pos.y = 0;
	SDL_QueryTexture(sprite_list[0].texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(gfx_settings->renderer, sprite_list[0].texture, NULL, &pos);
	
	pos.x = 15;
	pos.y = 15;
	SDL_QueryTexture(sprite_list[3].texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(gfx_settings->renderer, sprite_list[1].texture, NULL, &pos);
	
	pos.x = 15;
	pos.y = 600;
	SDL_QueryTexture(sprite_list[3].texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(gfx_settings->renderer, sprite_list[1].texture, NULL, &pos);
}

void graphics_end_scene() {
	SDL_RenderPresent(gfx_settings->renderer);}

bool graphics_add_sprite(const char *filename, int *id) {
	if (sprite_count < MAX_SPRITES) {
		struct sprite s;
		SDL_Surface * surf = SDL_LoadBMP(filename);
		if (!surf)
			return false;
		s.texture = SDL_CreateTextureFromSurface(gfx_settings->renderer,
							 surf);
		SDL_FreeSurface(surf);
		sprite_list[sprite_count] = s;
		sprite_count++;
		return true;
	} else {
		printf ("Sprite container full. Delete for more space\n");
		printf ("MAX_SPRITES = %d\n", MAX_SPRITES);
		return false;
	}
}

void graphics_remove_sprite(const int id) {

}

void graphics_set_screen_size(const int h, const int w) {
	
}

void graphics_set_screen_clear_colour(int r, int g, int b, int a) {
	
}

void graphics_shutdown() {
	SDL_DestroyRenderer(gfx_settings->renderer);
	SDL_DestroyWindow(gfx_settings->window);
	// loop through and clear SDL_Textures
	free(gfx_settings);
}
