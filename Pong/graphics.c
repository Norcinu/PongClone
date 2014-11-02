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
#include "math.h"

struct sprite *sprites[MAX_SPRITES];
static int sprite_count = 0;

sbool graphics_init(const char *title, int h, int w)
{
	int i = 0;
	SDL_Rect screen_dimensions;
	int mid_x = 0;
	int mid_y = 0;
	Uint32 render_ops = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return 0;

	for (; i < MAX_SPRITES; i++) {
		sprites[i] = (struct sprite *)malloc(sizeof(struct sprite));
	}
	
	gfx_settings = (struct gfx_context *)malloc(sizeof(struct gfx_context));
	if (gfx_settings == NULL) {
		return sfalse;
	}
	
	SDL_GetDisplayBounds(0, &screen_dimensions);
	mid_x = (screen_dimensions.w / 2) - (w / 2);
	mid_y = (screen_dimensions.h / 2) - (h / 2);

	gfx_settings->screen_height = h;
	gfx_settings->screen_width = w;
	gfx_settings->clear_colour = 0;
	gfx_settings->window = SDL_CreateWindow(title, mid_x, mid_y, w, h,
                                            SDL_WINDOW_OPENGL);
	gfx_settings->renderer = SDL_CreateRenderer(gfx_settings->window, -1,
                                                render_ops);
	SDL_SetRenderDrawColor(gfx_settings->renderer, 128, 129, 8, 0);
	
	for (i = 0; i < MAX_SPRITES; i++) {
		
	}
	
	return sfalse;
}

void graphics_begin_scene()
{
	SDL_RenderClear(gfx_settings->renderer);
}

void graphics_draw_sprite(const int id, struct vector2 *pos, struct vector2 *dim)
{
	SDL_Rect r;
	r.x = pos->x;
	r.y = pos->y;
    r.h = dim->y;
    r.w = dim->x;
	SDL_RenderCopy(gfx_settings->renderer, sprites[id]->texture, NULL, &r);
}

void graphics_end_scene() {
	SDL_RenderPresent(gfx_settings->renderer);
}

sbool graphics_add_sprite(const char *filename, int *id)
{
	if (sprite_count < MAX_SPRITES) {
		SDL_Rect r;
		struct sprite *s=(struct sprite*)malloc(sizeof(struct sprite));
		SDL_Surface *surf = SDL_LoadBMP(filename);
		if (!surf)
			return sfalse;
		s->texture = SDL_CreateTextureFromSurface(gfx_settings->renderer, surf);
		SDL_QueryTexture(s->texture, NULL, NULL, &r.w, &r.h);
		s->width = r.w;
		s->height = r.h;
		
		SDL_FreeSurface(surf);
		sprites[sprite_count] = s;
		sprite_count++;
		return strue;
	} else {
		printf ("Sprite container full. Delete for more space\n");
		printf ("MAX_SPRITES = %d\n", MAX_SPRITES);
		return sfalse;
	}
}

void graphics_remove_sprite(const int id)
{

}

void graphics_set_screen_size(const int h, const int w)
{
	
}

void graphics_set_screen_clear_colour(int r, int g, int b, int a)
{
	
}

void graphics_shutdown()
{
	int i = 0;
	SDL_DestroyRenderer(gfx_settings->renderer);
	SDL_DestroyWindow(gfx_settings->window);
	// loop through and clear SDL_Textures
	for (; i < MAX_SPRITES; i++) {
		sprite_delete(sprites[i]);
		sprites[i] = NULL;
	}
	free(gfx_settings);
}

