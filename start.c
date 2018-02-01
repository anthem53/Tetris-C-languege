#include "start.h"

int StartDisplay() {
	int select = -1;

	while (1){
		printStartDisplay();
		scanf("%d", &select);

		if (select != 1 && select != 2 && select != 3)
			printf("Wrong Input, input the correct number again\n");
		else
			return select;
	} 
	
	

}

void printStartDisplay() {


	printf(" =========================================\n");
	printf(" =========================================\n");
	printf(" =========================================\n");
	printf(" =============    테트리스    ============\n");
	printf(" =========================================\n");
	printf(" =========================================\n");
	printf(" =========================================\n");
	printf(" 1. 게임 시작\n");
	printf(" 2. 랭킹스코어\n");
	printf(" 3. 종료\n");
	printf(" >> ");


}