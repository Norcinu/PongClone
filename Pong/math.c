//
//  math.c
//  Pong
//
//  Created by Steven Gleed on 06/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#include <stdio.h>
#include "math.h"

void set_vector2(struct vector2 *v, const int x, const int y) {
	v->x = x;
	v->y = y;
}