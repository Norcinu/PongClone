//
//  entity.h
//  Pong
//
//  Created by Steven Gleed on 06/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#ifndef ENTITY_H
#define ENTITY_H

#define HAS_COLLIDED	1
#define NOT_COLLIDED	0
#define MAX_ENTITIES	5

struct vector2;

struct entity {
	int gid;
	int active;
	struct vector2 *position;
	struct vector2 *prev_position;
	struct vector2 *dimension;
	char name[20];
};

struct entity* entity_init();
void entity_update(struct entity *ent, const double dt);
int  entity_check_collision(struct entity *one, struct entity *two);
void entity_set_position(struct entity *ent, int x, int y);
void entity_render(struct entity *ent, double dt);
void entity_free(struct entity *ent);

#endif
