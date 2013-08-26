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

#include <json/json.h>

struct entity *entities[MAX_ENTITIES];

char* read_file(char* filename);

void world_init() {
	int i = 0;
	FILE *file;
	struct json_object *obj;
	
	for (; i < MAX_ENTITIES; i++) {
		entities[i] = (struct entity *)malloc(sizeof(struct entity));
	}
	
	file = fopen("entities.txt", "r");
	char *str = read_file("/Users/steven/Documents/code/Pong/Pong/data/config.json");
	if (str == NULL) {
		printf("NULL");
	}
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

char* read_file(char* filename)
{
	FILE* file = fopen(filename,"r");
	if(file == NULL)
	{
		return NULL;
	}
	
	fseek(file, 0, SEEK_END);
	long int size = ftell(file);
	rewind(file);
	
	char* content = calloc(size + 1, 1);
	
	fread(content,1,size,file);
	
	return content;
}