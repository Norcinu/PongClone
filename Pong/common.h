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
#define SPRITE_BACKGROUND "../../../Pong/bmp/background.bmp"
#define SPRITE_BALL "../../../Pong/bmp/ball.bmp"
#define SPRITE_PADDLE "../../../Pong/bmp/paddle.bmp"
#define SPRITE_WALL "../../../Pong/bmp/wall.bmp"
#else
#define SPRITE_BACKGROUND "./bmp/background.bmp"
#define SPRITE_BALL "./bmp/ball.bmp"
#define SPRITE_PADDLE "./bmp/paddle.bmp"
#define SPRITE_WALL "./bmp/wall.bmp"
#endif
#else
#define SPRITE_BACKGROUND "/Users/steven/Documents/code/Pong/Pong/bmp/background.bmp"
#define SPRITE_BALL "/Users/steven/Documents/code/Pong/Pong/bmp/ball.bmp"
#define SPRITE_PADDLE "/Users/steven/Documents/code/Pong/Pong/bmp/paddle.bmp"
#define SPRITE_WALL "/Users/steven/Documents/code/Pong/Pong/bmp/wall.bmp"
#endif

typedef int sbool;

#define sfalse 0
#define strue  1

#endif
