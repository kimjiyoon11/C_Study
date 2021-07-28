#include<stdio.h>
#include<string.h>

typedef int a;
typedef char b[1000];
typedef float c;

typedef struct Person 
{
	b name1;
	a age1;
	a height1;
	c weight1;
} Person1;

Person1 personFunc(Person1 A_param)
{
	Person1 newPerson;
	
	strcpy(newPerson.name1, A_param.name1);
	newPerson.age1 = A_param.age1;
	newPerson.height1 = A_param.height1;
	newPerson.weight1 = A_param.weight1; 
	
	return newPerson;
}

int main (void)
{
	Person1 A = {"jiyoon", 20, 150, 50.6};
	
	Person1 result;
		
	result = personFunc(A);
	
	printf("%s\n%d\n%d\n%.1f\n", result.name1, result.age1, result.height1, result.weight1 );	
}
