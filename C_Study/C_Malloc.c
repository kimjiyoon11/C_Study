#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

int main (void){
	
	int *score;
	//int i;
	//int size = 100 * sizeof(int);
	score = (int *)malloc(100 * sizeof(int));
	
	if(score == NULL)
	{
		printf("Memory NULL");
		exit(1);
	}


	for(int i = 0; i < 100; i++)
	{
		//score[i] = i;
		*(score+i) = i;
		printf("%p : %d\n",&score[i], score[i]);
	}
	
	free(score);
	
	char *pc = NULL;
	int i = 0;
	pc = (char *)malloc(100*sizeof(char)); // 
	
	//printf("%ld\n", malloc_usable_size(pc));
	
	//printf("%ld\n", sizeof(pc));
	
	//printf("%ld\n", sizeof(char) * 100);
			
	if(pc == NULL)
	{
		printf("fail");
		exit(1);
	}
	
	for(i = 0; i < 26; i++)
	{
		*(pc + i) = 'a' + i;
	}
		
	*(pc + i) = 0;
	
	printf("%s\n", pc);
	
	size_t num_size = malloc_usable_size(pc);
	
	printf("pc memory size : %ld\n", num_size);
		
	free(pc);
	
	return 0;
}
