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
	printf(" =============    ��Ʈ����    ============\n");
	printf(" =========================================\n");
	printf(" =========================================\n");
	printf(" =========================================\n");
	printf(" 1. ���� ����\n");
	printf(" 2. ��ŷ���ھ�\n");
	printf(" 3. ����\n");
	printf(" >> ");


}