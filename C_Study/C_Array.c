#include<stdio.h>
#include<string.h>

int main(void){

	int ArrayLen = 0;
	
	printf("array length : ");
	scanf("%d", &ArrayLen);
	
	printf("data : %d\n", ArrayLen);
	
	char input[ArrayLen];
	
	printf("\nWrite stringData : ");	
	scanf("%s", input);
	
	for(int i = 0; i < strlen(input); i++){
		printf("index : %d %c \n", i, input[i]);
	}
	
	printf("string data : %s\n", input);
	printf("string length(strlen) : %ld\n", strlen(input));
	
	
	printf("\n\n----pointer type array----\n");
	
	char *str = "test string";
	
	for(int i = 0; i < strlen(str); i++){
		printf("index : %d %c \n", i, str[i]);
	}
	
	printf("%s \n", str);
	return 0;
	
}
