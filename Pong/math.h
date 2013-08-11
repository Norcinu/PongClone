//
//  math.h
//  Pong
//
//  Created by Steven Gleed on 03/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#ifndef MATH_H
#define MATH_H

struct vector2 {
	int x;
	int y;
};

struct vector3 {
	int x;
	int y;
	int z;
};

struct colour {
	int r;
	int g;
	int b;
	int a;
};

void set_vector2(struct vector2 *v, const int x, const int y);

#endif
