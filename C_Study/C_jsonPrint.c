#include <stdio.h>
#include <jansson.h>
#include <string.h> 

typedef struct JSONDATA //Key, Value를 담을 구조체 선언
{
	char mKey[1024];
	char mValue[1024];
}JSONDATA;

int main (void)
{
	JSONDATA *pJsonData;
	 
	json_t *jsonFile, *value, *objValue;
	json_error_t error;	
	int size, i = 0;
	const char *key, *objKey;
	
	jsonFile = json_load_file("ipInfo.json", 0, &error);
				
	json_object_foreach(jsonFile, objKey, objValue){
		
		printf("%s : \n", objKey);
		
		size = json_object_size(objValue);	
		
		pJsonData = (JSONDATA *)malloc(sizeof(JSONDATA) * size); // json파일에 대한 size만큼 메모리 할당
		
		if(!pJsonData)
			exit(1);
							
		json_object_foreach(objValue, key, value){
				
			strcpy((pJsonData+i)->mKey, key); //key값 저장
			strcpy((pJsonData+i)->mValue, json_string_value(value)); //value값 저장
			
			i++;			
		}	
	}
	
	//printf("size : %d\n", size);	
			
	for(int j = 0; j < size; j++)
	{
		printf("%s : %s\n", (pJsonData+j)->mKey, (pJsonData+j)->mValue); //출력
	}
	
	json_decref(jsonFile);
		
	free(pJsonData); //메모리 해제
	
	pJsonData = NULL; //초기화
	
			
    return 0;
}
