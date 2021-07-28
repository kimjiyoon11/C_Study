#include<stdio.h>
#include<string.h>

struct person
{
	char name[1000];
	int age;	
	int height;
	float weight;
};

int main(void){

	printf("======= person A =======\n");
	
	struct person A;
	
	strcpy(A.name, "jiyoon");
	A.age = 20;
	A.height = 180;
	A.weight = 80;
		
	printf("name : %s\nage : %d\nheight : %d\nweight : %f\n", A.name, A.age, A.height, A.weight);
		
	printf("======= person B =======\n");
	
	struct person A;
	
	B = A;
	
	printf("name : %s\nage : %d\nheight : %d\nweight : %f\n", B.name, B.age, B.height, B.weight);
	
	printf("======= person C =======\n");
	
	struct person C = {"B_jiyoon", 25, 180, 70};
	
	printf("name : %s\nage : %d\nheight : %d\nweight : %f\n", C.name, C.age, C.height, C.weight);
	
	
	printf("======= operation & IF =======\n");

	int ageSum = 0;
		
	ageSum = A.age + B.age + C.age; 
	
	printf("%d\n", ageSum);
	
	if(A.age == C.age)
		printf("if\n");

	else
		printf("else\n");
}
