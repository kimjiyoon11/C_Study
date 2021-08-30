#include <stdio.h>
#include <jansson.h>
#include <string.h> 

typedef struct JSONDATA
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
		
		pJsonData = (JSONDATA *)malloc(sizeof(JSONDATA) * size);
		
		if(!pJsonData)
			exit(1);
							
		json_object_foreach(objValue, key, value){
				
			strcpy((pJsonData+i)->mKey, key);
			strcpy((pJsonData+i)->mValue, json_string_value(value));
			
			i++;			
		}	
	}
	
	//printf("size : %d\n", size);	
			
	for(int j = 0; j < size; j++)
	{
		printf("%s : %s\n", (pJsonData+j)->mKey, (pJsonData+j)->mValue);
	}
	
	json_decref(jsonFile);
		
	free(pJsonData);
	
	pJsonData = NULL;
	
			
    return 0;
}
