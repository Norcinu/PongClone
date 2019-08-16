//
//  math.c
//  Pong
//
//  Created by Steven Gleed on 06/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#include <stdio.h>
#include "seg_math.h"

void set_vector2(struct vector2 *v, const int x, const int y) {
	v->x = x;
	v->y = y;
}

//Vector operations
float dot_product(const struct vector2 *v1, const struct vector2 *v2)
{
	return 1.0f;
}

void cross_product(const struct vector2 *v1, const struct vector2 *v2, struct vector2 *cross)
{

}

float vector2_normalise(struct vector2 *v)
{
	return 1.0f;
}

