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
#include "math.h"
//#include <json/json.h>
#include <jansson.h>

struct entity *entities[MAX_ENTITIES];

char* read_file(char* filename);

void world_init() {
	size_t i = 0;
	char *text;
	json_t *root;
	json_error_t error;
	text = read_file("/Users/steven/Documents/code/Pong/Pong/data/config2.json");
	if (!text)
		return;
	root = json_loads(text, 0, &error);
	if (!root)
		fprintf(stderr, "error on line %d, %s\n", error.line, error.text);
	
	if (!json_is_array(root)) {
		fprintf(stderr, "error on line %d, %s\n", error.line, error.text);
	}
	json_t *ar = json_object_get(root, "entities");
	if (!json_is_array(ar)) {
		fprintf(stderr, "error: root is not an array\n");
		json_decref(root);
		return;
	}
	
	for (i = 0; i < json_array_size(ar); i++) {
		json_t *entity;
		json_t *name, *sprite, *x, *y;
		name = json_array_get(ar, i);
		if (!json_is_object(name)) {
			fprintf(stderr, "error: not object\n");
			return;
		}
	}
}

void world_update() {
	int i = 0;
	for (; i < MAX_ENTITIES; i++) {
		entity_update(entities[i], 0.0);
	}
}

void world_render() {
	int i = 0;
	for (; i < MAX_ENTITIES; i++) {
		entity_render(entities[i], 0.0);
	}
}
							
							
// move to json_parser.c
char* read_file(char* filename)
{
	FILE* file = fopen(filename,"r");
	if(file == NULL)
		return NULL;
	
	fseek(file, 0, SEEK_END);
	long int size = ftell(file);
	rewind(file);
	
	char* content = calloc(size + 1, 1);
	
	fread(content,1,size,file);
	
	return content;
}