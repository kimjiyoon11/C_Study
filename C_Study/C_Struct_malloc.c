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
	scanf("%d", &nNum); //입력할 데이터 수
	printf("\n");

	pUser = (user *)malloc(nNum * sizeof(user)); //pUser 포인터에 (USER 구조체 크기 * 입력할 데이터 수) 만큼의 메모리 할당
	//pUser = (user *)malloc(size * sizeof(user));
	
	if(pUser == NULL) //pUser 포인터에 메모리 할당 실패 시 종료
	{
		printf("malloc fail");
		exit(1);
	}		
	
	for(int i = 0; i < nNum; i++) //데이터 입력 for문
	{
		printf("============ %d : input data ============\n", i);
		
		(pUser + i)->index = i;
		
		printf("name : ");
		scanf("%s",(pUser + i)->name); 
		
		printf("age : ");
		scanf("%d", &(pUser + i)->age);
	}
	
	printUser(pUser, nNum); //출력함수
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
