#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct NODE {    // 연결 리스트의 노드 구조체
    struct NODE* next;    // 다음 노드의 주소를 저장할 포인터
    char name[1000];
} NODE;

void addFirst(struct NODE* target, char name_s[1000])    // 기준 노드 뒤에 노드를 추가하는 함수
{
    //struct NODE* newNode = malloc(sizeof(char) * (signed)strlen(name_s) + 1);    // 새 노드 생성
    NODE* newNode;
    
    newNode = malloc(sizeof(struct NODE));//newNode malloc
    
    newNode->next = target->next;    // 새 노드의 다음 노드에 기준 노드의 다음 노드를 지정
    
    strcpy(newNode->name, name_s);            // 데이터 저장
    target->next = newNode;    // 기준 노드의 다음 노드에 새 노드를 지정
}

int main(void)
{
    NODE* head = malloc(sizeof(struct NODE));    // 머리 노드 생성 //머리 노드는 데이터를 저장 X
                                                       
    head->next = NULL;
    
    char name[1000];
    int userNum = 0;
    

    printf("Number of people : ");
    scanf("%d", &userNum);
        
    for (int i = 0; i < userNum; i++) {
        
        printf("Input Name : ");
        scanf("%s", name);
        addFirst(head, name);
    }

    struct NODE* curr = head->next;    // 연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
    
    while (curr != NULL)               // 포인터가 NULL이 아닐 때 계속 반복
    {
        printf("%s \n", curr->name);    // 현재 노드의 데이터 출력
        curr = curr->next;             // 포인터에 다음 노드의 주소 저장
    }

    curr = head->next;      // 연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
    while (curr != NULL)    // 포인터가 NULL이 아닐 때 계속 반복
    {
        struct NODE* next = curr->next;    // 현재 노드의 다음 노드 주소를 임시로 저장
        free(curr);                        // 현재 노드 메모리 해제
        curr = next;                       // 포인터에 다음 노드의 주소 저장
    }

    free(head);    // 머리 노드 메모리 해제
    
    return 0;
}
