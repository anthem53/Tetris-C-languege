#include<stdio.h>
#include<stdlib.h>
#include "start.h"
#include "ranking.h"
#include "game.h"

int main() {

	srand((unsigned)time(NULL));
	while (1) {

		int select = StartDisplay();

		if (1 == select) {
			
			/* game start part*/
			gameStart();
		}
		else if (2 == select) {
			/* ranking show part*/
			rankerPrint();
			;
		}
		else {
			printf("게임을 종료합니다. \n");
			break;
		}
		
	
	}


	return 0;
}