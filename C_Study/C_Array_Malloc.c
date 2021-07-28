#include<stdio.h>
#include<stdlib.h>

#define rowSize 8
#define colSize 6

void printNumber(int** pptr);

int main (void)
{
printf("test");
	int i, x, y;
	int** pptr = (int**)malloc(sizeof(int*) * rowSize);//row 동적 메모리 할당

	for(i = 0; i < colSize; i++)
	{
		*(pptr + i) = (int *)malloc(sizeof(int) * colSize); //col 동적 메모리 할당
	}
	
	
	for(int row = 0; row < rowSize; row++) //row, col 초기화
	{
		for(int col = 0; col < colSize; col++)
		{
			*(*(pptr + row) + col) = colSize * col + row;
		}
	}

	//printNumber(pptr);

	return 0;
}

void printNumber(int** pptr) //출력 함수
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
