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
#include <jansson.h>
#include "json_parser.h"

struct entity *entities[MAX_ENTITIES];

char* read_file(const char* filename);

#ifdef _WIN32
	const char *file_name = "../../../Pong/data/config.json";
#else
	const char *file_name = "/Users/steven/Documents/code/PongClone/Pong/data/config.json";
#endif


void world_init()
{
	size_t i = 0;
	char *text;
	json_t *root, *ar;
	json_error_t error;


	text = read_file(file_name);
	if (!text)
		return;
	
	for (i = 0; i < MAX_ENTITIES; i++) {
		entities[i] = entity_init();
	}
	
	root = json_loads(text, 0, &error);
	if (!root)
		fprintf(stderr,"error on line %d, %s\n",error.line,error.text);

    free(text);
	
	ar = json_object_get(root, "entities");
	if (!json_is_array(ar)) {
		fprintf(stderr, "error: root is not an array\n");
		json_decref(root);
		return;
	}
    
    for (i = 0; i < json_array_size(ar); i++) {
		json_t *entity;
		json_t *name, *x, *y, *gid, *height, *width;
		int h, w;
		
		entity = json_array_get(ar, i);
		if (!json_is_object(entity)) {
			fprintf(stderr, "error: not object\n");
			return;
		} else {
			//entities[i]->gid = i;
			entities[i]->active = 1;
		}
            
        name = json_object_get(entity, "name");
        if (!json_is_string(name)) {
            json_decref(name);
            return;
        }
		
        gid = json_object_get(entity, "gid");
        entities[i]->gid = (int)json_integer_value(gid);
		
        height = json_object_get(entity, "height");
        width = json_object_get(entity, "width");
        h = (int)json_integer_value(height);
        w = (int)json_integer_value(width);
        set_vector2(entities[i]->dimension, w, h);
        
        x = json_object_get(entity, "x");
        entities[i]->position->x = (int)json_integer_value(x);
        y = json_object_get(entity, "y");
        entities[i]->position->y = (int)json_integer_value(y);
	}
}

void world_update()
{
	int i = 0;
	for (; i < MAX_ENTITIES; i++) {
		entity_update(entities[i], 0.0);
	}
}

void world_render()
{
	int i = 0;
    graphics_begin_scene();
	for (; i < MAX_ENTITIES; i++) {
		entity_render(entities[i], 0.0);
	}
    graphics_end_scene();
}

void world_shutdown()
{
	
}
							
// move to json_parser.c
//#if 0
char* read_file(char* filename)
{
	long int size;
	char* content;

	FILE* file = fopen(filename,"r");
	if(file == NULL)
		return NULL;
	
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	
	content = (char *)calloc(size + 1, 1);
	
	fread(content,1,size,file);
	
	return content;
}
//#endif