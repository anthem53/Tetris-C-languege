#include "game.h"

static int ** board;
static boardInfo * thisBoardInfo;
FILE* file;
void convertBoardPrint(int input);
void boardPrint();
void GamePlay(boardInfo * thisBoardInfo);
int createNewblock();
int DropBlock() ;
int canDrop();
int MoveLeftBlock();
int MoveRightBlock();
int canLeftMove();
int canRightMove();
int turnBlock(int blockNum);
void removeLine(int h);
int ClearLine();

char getKey();

void gameSetting(boardInfo * thisBoardInfo) {

	board = (int**)malloc(sizeof(int*) * 26);
	for (int i = 0; i < 26; i++)
		board[i] = (int*)malloc(sizeof(int) * 12);
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 12; j++)
			board[i][j] = 0;

	}

	for (int i = 0; i < 26; i++) {
		board[i][0] = 3;
		board[i][11] = 3;
	}
	for (int i = 0; i < 12; i++)
		board[25][i] = 3;
	thisBoardInfo->score = 0;
	thisBoardInfo->stage = 1;
}

int gameStart() {
	file= fopen("debugging.txt", "w");
	thisBoardInfo = (boardInfo*)malloc(sizeof(boardInfo));
	gameSetting(thisBoardInfo);
	
	GamePlay(thisBoardInfo);

	int result = thisBoardInfo->score;
	free(thisBoardInfo);
	free(board);
	return result;
}
void GamePlay(boardInfo * thisBoardInfo) {

	
	boardPrint();
	
	Sleep(300);
	
	int blockNum = 0;;
	int Quit = 0;
	while ((blockNum = createNewblock()) > -1) {
		boardPrint();
		clock_t  initialTime = clock();

		while (1) {
			char inputKey = 'a';

			if (inputKey = getKey()) {
				
				if (inputKey == 75)
					MoveLeftBlock();

				else if (inputKey == 77)
					MoveRightBlock();
				else if (inputKey == 72)
					turnBlock(blockNum);
				else if (inputKey == 'R' || inputKey == 'r') {
					Quit = 1;
					break;
				}
				else if (inputKey == 'K' || inputKey == 'k') {
					break;
				}
			
			}
			
			clock_t  currentTime = clock();
			
			if ((double)(currentTime - initialTime) / CLOCKS_PER_SEC == 0.001) {
				boardPrint();
			}
			if ((double)(currentTime - initialTime) / CLOCKS_PER_SEC == 0.1) {
				initialTime = clock();

				int succeed = DropBlock();
				if (succeed == 0) {
					int getScore = ClearLine();
					thisBoardInfo->score += getScore;
					break;
				}
			}
		}
		if (Quit == 1)
			break;
	}
	system("cls");
}

int DropBlock() {

	if (canDrop()) {
		for (int i = 0; i < 12; i++) {
			for (int j = 25; j >= 0; j--) {
				if (board[j][i] == 1) {

						board[j + 1][i] = board[j][i];
						board[j][i] = 0;
					
				}
			}
		}

		return 1;
	}
	else {
		for (int i = 0; i < 12; i++) {
			for (int j = 25; j >= 0; j--) {
				if (board[j][i] == 1)
					board[j][i] = 2;
			}
		}
		
		return 0;
	}

}
int canDrop() {
	int previousState = 3;
	for (int i = 0; i < 12; i++) {
		for (int j = 25; j >= 0; j--) {

			int currentState = board[j][i];
			if (currentState == 1 && (previousState == 3 || previousState == 2)) {
				/*stop the block*/
				return 0;
			}

			previousState = board[j][i];
		}

	}
	return 1; 
}

void convertBoardPrint(int input) {
	/*1 is that the dropping block*/
	if (input == 1) {
		printf("□");
	} 
	/* 2 is that the stacked block*/
	else if (input == 2) {
		printf("▦");
	}
	/* 3 is the edge of board */
	else if (input == 3) {
		printf("■");
	}
	/*0 is vacume area*/
	else if (input == 0) {
		printf("  ");
	}
	return;
}
void boardPrint() {

	system("cls");
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 12; j++)
			//printf("%d", board[i][j]);
			convertBoardPrint(board[i][j]);
		printf("\n");
		
	}
	putchar('\n');
	printf(" ■■■ Score : %d ■■■", thisBoardInfo->score);
}
int createNewblock() {
	//int newBlockNumber = rand() % 7;
	
	/*debugging*/
	int newBlockNumber = 6;

	int * newBlock = returnBlock(newBlockNumber);
	
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (newBlock[i*4 + j] == 1) {
			
				if (board[i][j + 4] != 0) {
					
					return -1;
				}
				
				board[i][j + 4] = newBlock[i * 4 + j];
			} 
		}
	}
	free(newBlock);
	return newBlockNumber;
}



int MoveLeftBlock() {
	if (canLeftMove() == 1) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 26; j++) {
				if (board[j][i] == 1) {
					board[j][i - 1] = board[j][i];
					board[j][i] = 0;
				}

			}
		}

		return 1;
	}
	else {

		return 0;
	}

	
}

int canLeftMove() {
	int previousBlock = 3;
	
	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < 12; i++) {
			int currentBlock = board[j][i];
			

			if (currentBlock == 1 && (previousBlock >= 2)) {
				static int chekcingNum = 1;
				
				return 0;
			}

			previousBlock = board[j][i];
			
		}
	}
	return 1;
}

int MoveRightBlock() {

	if (canRightMove() == 1) {
		for (int i = 0; i < 26; i++) {
			for (int j = 10; j > 0; j--) {
				if (board[i][j] == 1) {
					board[i][j + 1] = board[i][j];
					board[i][j] = 0;
				}

			}
		}
	
	}
	else {

		return 0;
	}
	return 1;
}

int canRightMove() {
	int previousBlock = 3;
	for (int i = 0; i < 26; i++) {
		for (int j = 12; j >= 0; j--) {
			int currentBlock = board[i][j];

			if ((previousBlock == 3 || previousBlock == 2) && currentBlock == 1) {
				static int chekcingNum = 1;
				
				return 0;
			}
			previousBlock = board[i][j];
		}
	}
	return 1;
}

int turnBlock(int blockNum) {

	/*square shape*/
	if (blockNum == 0) {
		return 1;
	}
	/* stick shape */
	else if(blockNum == 6) {

		int i, j, type = -1;
		for ( i = 25; i >= 0; i--) {
			for ( j = 0; j < 12; j++) {
				if (board[i][j] == 1) {
					/* horizon*/
					if (board[i][j + 1] == 1)
						type = 1;
					/* vertical*/
					else
						type = 0;
					break;
				}
			
			}
			if (type >= 0)
				break;
		}

		if (type == 0) {

			for (int k = 0; k < 4; k++) {
				if (board[i][j - 1 + k] >= 2)
					return 0;
			}
			
			for (int k = 0; k < 4; k++) {
				board[i - k][j] = 0;
			}
			for (int k = 0; k < 4 ; k++) {
				board[i][j - 1 + k] = 1;
			}

		}
		else {

			for (int k = 0; k < 4; k++) {
				if (board[i + k - 3][j + 1] >= 2)
					return 0;
			}

			for (int k = 0; k < 4; k++) {

				board[i][j + k] = 0;
			}
			for (int k = 0; k < 4; k++) {
				board[i + k - 3][j + 1] = 1;
			}
		
		}
		return 1;
	
	}
	else if (blockNum >= 1 && blockNum <=5) {

		/* 최좌하점 찾기*/
		int i, j, completed = 0;
		for (i = 25; i >= 0; i--) {
			for (j = 0; j < 12; j++) {
				if (board[i][j] == 1) {
					completed = 1;
					break;
				}

			}
			if (completed == 1)
				break;
		}

		/*미리 바뀌는 모양 기록*/
		int temp[5][3] = { 0 };
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 5; b++) {
				if(board[i - a][j - 2 + b] == 1)
					temp[4 - b][2 - a] = board[i - a][j - 2 + b];

			}
		}

		/*해당 모양이 돌아갈 때 충돌이 발 생하는가?*/
		for (int a = 0; a < 5; a++) {
			for (int b = 0; b < 3; b++) {
				if (board[i - 2 + a][j - 1 + b] >= 2 && temp[a][b] == 1)
					return 0;
			}
		}
		/* 충돌 발생하지 않을 시 기존의 1을 지우고*/
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 5; b++) {
				if (board[i - a][j - 2 + b] == 1)
					board[i - a][j - 2 + b] = 0;
			}
		}

		/*충돌이 돌아가는 1을 만든다.*/
		for (int a = 0; a < 5; a++) {
			for (int b = 0; b < 3; b++) {
				if(temp[a][b] == 1)
					board[i - 2 + a][j - 1 + b] = 1;
					
			}
		}


		return 1;
	}
	else {
		return 0;
	}

}

int ClearLine() {

	int clearNum = 0;
	for (int i = 24; i >= 0; i--) {
		int isClear = 1;
		for (int j = 1; j < 11; j++) {
			if (board[i][j] == 0) {
				isClear = 0;
				break;
			}
		}
		if (isClear == 1) {
			removeLine(i);
			clearNum++;
			i++;
		}
	}

	return clearNum;
}
void removeLine(int h) {
	
	for (int i = h; i >= 1 ; i--) {
		for (int j = 1; j < 11; j++) {
			board[i][j] = board[i - 1][j];
		}
	}
	return;
}

char getKey() {

	char result; 
	if (_kbhit()) {
		result = _getch();
	}
	else
		result = '\0';

	return result;

}