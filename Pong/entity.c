//
//  entity.c
//  Pong
//
//  Created by Steven Gleed on 06/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "entity.h"
#include <seg_math.h>
#include "graphics.h"

#define MAX_NAME_LENGTH	256
#define MAX_ENTITY_COUNT 64 //get rid and set something sensible. 

static int entity_count = 0;
const char *BASE_NAME = "Entity \0";

//add a linked list/queue of behaviours that each entity can update

struct entity* entity_init()
{
	char buffer[3] = { '\0' };
	struct entity *ent = (struct entity*)malloc(sizeof(struct entity));
	entity_count++;
//	sprintf_s(buffer, 2, "%d", entity_count);
	//sprintf(buffer, "%d", entity_count);
	memset(ent->name, 0, sizeof(ent->name));
	strcat_s(ent->name, 8, BASE_NAME);
	//strcat_s(ent->name, sizeof(buffer) + 1, buffer);
	//strcat(ent->name, BASE_NAME);
	//strcat(ent->name, buffer);
	ent->gid = 0;
	ent->active = 0;
	ent->position = (struct vector2*)malloc(sizeof(struct vector2));
	set_vector2(ent->position, 0, 0);
	ent->prev_position = ent->position;
	ent->dimension = (struct vector2*)malloc(sizeof(struct vector2));
	set_vector2(ent->dimension, 0, 0);
	return ent;
}

void entity_update(struct entity *ent, const double dt)
{
	if (ent->active) {
		//ent->position = ent->position + vector2(0, 0, 0) * dt;
	}
}

int entity_check_collision(struct entity *one, struct entity *two)
{
	return NOT_COLLIDED;
}

void entity_set_position(struct entity *ent, int x, int y)
{
	ent->prev_position = ent->position;
	ent->position->x = x;
	ent->position->y = y;
}

void entity_render(struct entity *ent, double dt)
{
	if (ent->active) {
		graphics_draw_sprite(ent->gid, ent->position, ent->dimension);
	}
}

void entity_free(struct entity *ent)
{

}