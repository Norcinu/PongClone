//
//  world.c
//  Pong
//
//  Created by Steven Gleed on 07/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "world.h"
#include "entity.h"
#include "graphics.h"

struct entity *entities[MAX_ENTITIES];

void world_init() {
	int i = 0;
	FILE *file;
	for (; i < MAX_ENTITIES; i++) {
		entities[i] = (struct entity *)malloc(sizeof(struct entity));
	}
	
	file = fopen("entities.txt", "r");
	
	// read entity loading from file.
	// entity name, graphic, start x, start y
}

void world_update() {
	int i = 0;
	for (; i < MAX_ENTITIES; i++) {
		entity_update(entities[i], 0.0);
	}
}

void world_render() {
	
}