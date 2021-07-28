#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int  swap(int x, int y);
int swap_pointer(int *x, int *y);

int main (void){
	
	int x = 1;
	int y = 2;

	swap(x, y);
	swap_pointer(&x, &y); //memory address 

	printf("%d\n", x);
	printf("%d\n", y);

	int *myPointer;
	int myNumber = 10;

	printf("myNumber : %d\n", myNumber);

	myPointer = &myNumber;
	printf("myPointer :%d\n", *myPointer); 
	
	printf("-------------- pointer memory error ---------------\n");
	
		char *str1 = "hello world"; //readonly
		
		printf("*str1 : %s \n", str1);
		
		printf("*str1 new data : [scanf(percent s, str1);] : error");
		//scanf("%s", str1); //error
		
		printf("\nnew *str1 : %s \n", str1);	
		
	printf("-------------- pointer memory ---------------\n");	
	
	char *str2 = malloc(sizeof(char) * 10);
	char *inputStr2 = malloc(sizeof(char) * 10);
	
	str2 = "memory test";
	
	printf("org *str2 String : %s \n", str2);
	
	printf("Input *str2 String : ");
	scanf("%s", inputStr2);
	
	int cmp = strcmp(str2, inputStr2);
	
	if(cmp > 0)
	{
		str2 = malloc(sizeof(char) * 10);
		str2 = inputStr2;
	}
		
	//printf("%d\n", cmp);
				
	printf("new *str2 String : %s\n", str2);
	
	return 0;
}

int  swap(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int swap_pointer(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
