#include "block.h"


int block[7][16] = {
	{
		0, 0, 0, 0  ,
		0, 1, 1, 0,
		0, 1, 1, 0 ,
		0, 0, 0, 0
	},
	{
		0, 1, 0, 0  ,
		0, 1, 0, 0 ,
		0, 1, 1, 0 ,
		0, 0, 0, 0
	},
	{
		0, 0, 1, 0  ,
		0, 0, 1, 0 ,
		0, 1, 1, 0 ,
		0, 0, 0, 0
	},
	{
		0, 1, 0, 0  ,
		0, 1, 1, 0 ,
		0, 0, 1, 0 ,
		0, 0, 0, 0
	},
	{
		0, 0, 1, 0  ,
		0, 1, 1, 0 ,
		0, 1, 0, 0 ,
		0, 0, 0, 0
	},
	{
		0, 0, 1, 0  ,
		0, 1, 1, 0 ,
		0, 0, 1, 0,
		0, 0, 0, 0
	} ,
	{
		0, 1, 0, 0  ,
		0, 1, 0, 0 ,
		0, 1, 0, 0 ,
		0, 1, 0, 0
	}
	 
};


int * returnBlock(int blockNum) {
	
	int * forReturn= (int*)malloc(sizeof(int) * 16);


	for (int i = 0; i < 16; i++) {
		forReturn[i] = block[blockNum][i];
	}

	return forReturn;

}
