//
//  entity.c
//  Pong
//
//  Created by Steven Gleed on 06/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#include <stdio.h>
#include "entity.h"
#include "math.h"
#include "graphics.h"

void entity_init(struct entity *ent) {
	ent->gid = 0;
	ent->active = 0;
	ent->position = (struct vector2*)malloc(sizeof(struct vector2));
	ent->position->x = 0;
	ent->position->y = 0;
	ent->prev_position = ent->position;
}

void entity_update(struct entity *ent, const double dt) {
	if (ent->active) {
		
	}
}

int entity_check_collision(struct entity *one, struct entity *two) {
	return NOT_COLLIDED;
}

void entity_set_position(struct entity *ent, int x, int y) {
	ent->prev_position = ent->position;
	ent->position->x = x;
	ent->position->y = y;
}

void entity_render(struct entity *ent, double dt) {
	if (ent->active) {
		graphics_draw_sprite(ent->gid, ent->position);
	}
}