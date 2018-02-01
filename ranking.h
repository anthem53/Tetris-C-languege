#ifndef __RANKING_H__ 

#define __RANKING_H__

#include<stdio.h>

struct ranker {
	char name[30];
	int score;
	struct ranker * next;
	struct ranker * prev;
};

typedef struct ranker ranker;



void newRanker(int score);
void rankerPrint();



#endif
