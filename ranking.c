#include"ranking.h"

int rankerNum = 0;
ranker* rankerTop = NULL;
ranker* rankerBottom = NULL;

void rankerListPush(ranker* newRankers);
ranker * rankerListPop();

void newRanker(int score) {

	if (rankerNum == 10 && rankerBottom->score > score) 
		return;

	ranker * newRankers = (ranker*)malloc(sizeof(ranker));

	scanf("%s", newRankers->name);
	newRankers->score = score;

	rankerListPush(newRankers);
	if (rankerNum  == 11) {
		rankerListPop();
	}

	return;

}
void rankerPrint() {

	ranker * rankerList = rankerTop; 
	printf("=================상위 10명==================\n");
	for (int i = 0; i < rankerNum; i ++) {
		printf("%2d 위 : %s , %d 점\n",i+1, rankerList->name, rankerList->score );
		rankerList = rankerList->next;
	}

}

void rankerListPush(ranker* newRankers) {

	for (ranker* temp = rankerTop; temp != NULL; temp = temp->next) {
		if (temp->score < newRankers->score) {

			newRankers->next = temp;
			temp->prev = newRankers;

			if (temp == rankerTop) {
				rankerTop = newRankers;
			}
			rankerNum++;
			return;
		}
	}

	/*the last part, input*/
	rankerBottom->next = newRankers;
	newRankers->prev = rankerBottom;
	rankerBottom = newRankers;
	rankerNum++;
	return;

}

ranker * rankerListPop() {
 /* the last part pop*/
	ranker* poped = rankerBottom;

	rankerBottom = poped->prev;
	rankerBottom->next = NULL;
	
	return poped;
}
