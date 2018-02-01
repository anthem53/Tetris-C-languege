#ifndef __GAME_H__

#define  __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>
#include <time.h>
#include "block.h"

typedef struct {
	int stage;
	int score;
}boardInfo;

void gameSetting(boardInfo * thisBoardInfo);
int gameStart();
#endif