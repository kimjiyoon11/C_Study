#include<stdio.h>
#include<stdlib.h>

#define rowSize 8
#define colSize 6

void printNumber(int** pptr);

int main (void)
{
printf("test");
	int i, x, y;
	int** pptr = (int**)malloc(sizeof(int*) * rowSize);//row 

	for(i = 0; i < colSize; i++)
	{
		*(pptr + i) = (int *)malloc(sizeof(int) * colSize); //col
	}
	
	
	for(int row = 0; row < rowSize; row++) //format
	{
		for(int col = 0; col < colSize; col++)
		{
			*(*(pptr + row) + col) = colSize * col + row;
		}
	}

	//printNumber(pptr);

	return 0;
}

void printNumber(int** pptr)
{
	for(int y = 0; y < rowSize; y++)
	{
		for(int x = 0; x < colSize; x++)
		{
			printf("03%d", *(*(pptr + y) + x));
		}
		printf("\n");
	}

	
}
