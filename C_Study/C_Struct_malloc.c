#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define Size 5;

typedef struct USER{
	int index;
	char name[100];
	int age;
}user;

void printUser(user *userFunc, int n);

int main (void){

	int nAge = 0;
	int nNum = 0;
	
	user *pUser;
	
	printf("Number of data to input : ");
	scanf("%d", &nNum);
	printf("\n");

	pUser = (user *)malloc(nNum * sizeof(user));
	//pUser = (user *)malloc(size * sizeof(user));
	
	if(pUser == NULL)
	{
		printf("malloc fail");
		exit(1);
	}		
	
	for(int i = 0; i < nNum; i++)
	{
		printf("============ %d : input data ============\n", i);
		
		(pUser + i)->index = i;
		
		printf("name : ");
		scanf("%s",(pUser + i)->name);
		
		printf("age : ");
		scanf("%d", &(pUser + i)->age);
	}
	
	printUser(pUser, nNum);
	free(pUser);
	return 0;
}

void printUser(user *userFunc, int n)
{
	int i = 0;
	printf("\n\n");
	for(i = 0; i < n; i++)
	{
		printf("=========== output index : %d ================\n", (userFunc + i)->index);
		printf("name : %s\n", (userFunc + i)->name);
		printf("age : %d\n", (userFunc + i)->age);
	}
}
