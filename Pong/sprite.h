//
//  sprite.h
//  Pong
//
//  Created by Steven Gleed on 03/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

struct vector2;

struct sprite {
	SDL_Texture *texture;
	char *name;
	int height;
	int width;
};

int sprite_load(const char *filename, struct sprite *spr, SDL_Renderer *r);
void sprite_draw(struct vector2 * pos, SDL_Renderer *r, SDL_Texture *t);
void sprite_delete(struct sprite *s);

#endif
