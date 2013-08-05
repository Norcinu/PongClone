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

const char *SPRITE_PATH = "~/Documents/code/Pong/Pong/bmp/";

bool sprite_load(const char *filename, struct sprite *spr, SDL_Renderer *r) {
	char * full_path = "";
	strcat(full_path, SPRITE_PATH);
	strcat(full_path, filename);
	SDL_Surface *surface = SDL_LoadBMP(full_path);
	if (!surface)
		return false;
	spr->texture = SDL_CreateTextureFromSurface(r, surface);
	SDL_FreeSurface(surface);
	return true;
}

void sprite_draw(struct vector2 * pos, SDL_Renderer *r, SDL_Texture *t) {
	SDL_RenderCopy(r, t, NULL, NULL);
}

void sprite_delete() {
	
}