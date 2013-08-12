//
//  sprite.c
//  Pong
//
//  Created by Steven Gleed on 03/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#include <stdio.h>
#include "sprite.h"
#include "math.h"

#ifdef _WIN32
const char *SPRITE_PATH = "./bmp/";
#else
const char *SPRITE_PATH = "~/Documents/code/Pong/Pong/bmp/";
#endif

void sprite_init(struct sprite *s) {
	s->texture = NULL;
	s->name = "";
	s->height = 0;
	s->width = 0;
}

int sprite_load(const char *filename, struct sprite *spr, SDL_Renderer *r) {
	char * full_path = "";
	SDL_Surface *surface = NULL;
	strcat(full_path, SPRITE_PATH);
	strcat(full_path, filename);
	surface = SDL_LoadBMP(full_path);
	if (!surface)
		return 0;
	spr->texture = SDL_CreateTextureFromSurface(r, surface);
	SDL_FreeSurface(surface);
	return 1;
}

void sprite_draw(struct vector2 * pos, SDL_Renderer *r, SDL_Texture *t) {
	SDL_RenderCopy(r, t, NULL, NULL);
}

void sprite_delete(struct sprite *s) {
	if (s) {
		SDL_DestroyTexture(s->texture);
		free(s);
	}
}