//
//  common.h
//  Pong
//
//  Created by Steven Gleed on 04/08/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#ifndef COMMON_H
#define COMMON_H

#ifdef _WIN32
#ifdef _DEBUG
#define SPRITE_BACKGROUND "bmp\\background.bmp"
#define SPRITE_BALL "bmp\\ball.bmp"
#define SPRITE_PADDLE "bmp\\paddle.bmp"
#define SPRITE_WALL "bmp\\wall.bmp"
#else
#define SPRITE_BACKGROUND "./bmp/background.bmp"
#define SPRITE_BALL "./bmp/ball.bmp"
#define SPRITE_PADDLE "./bmp/paddle.bmp"
#define SPRITE_WALL "./bmp/wall.bmp"
#endif
#else
#define SPRITE_BACKGROUND "/Users/steven/Documents/code/PongClone/Pong/bmp/background.bmp"
#define SPRITE_BALL "/Users/steven/Documents/code/PongClone/Pong/bmp/ball.bmp"
#define SPRITE_PADDLE "/Users/steven/Documents/code/PongClone/Pong/bmp/paddle.bmp"
#define SPRITE_WALL "/Users/steven/Documents/code/PongClone/Pong/bmp/wall.bmp"
#endif

#include <stdbool.h>
#include <stdint.h>

/*
typedef int bool;
#define false 0
#define true  1
*/
#endif
