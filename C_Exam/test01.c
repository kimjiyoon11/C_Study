#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<sys/wait.h>

#define	SH_PATH	"/home/jiyoon/Desktop/Git/study1/Shell_Exam/IP_test.sh"
// enp0s3"

int main(void)
{
	int rtn = 0;
	char cmd[256] = {0,};
	char InterName[256] = {0,};
	
	int PathLen = 0;
	
	scanf("%s", InterName);
	
	
	PathLen = strlen(SH_PATH) + strlen(InterName);

	printf("SH_PATH : %ld\n", strlen(SH_PATH));
	printf("InterName : %ld\n", strlen(InterName));	
	printf("PathLen : %d\n", PathLen);
	
	
	memcpy(cmd, SH_PATH, sizeof(cmd));
	strcat(cmd, " ");
	
	strcat(cmd, InterName);
		
	printf("%s\n", cmd);
	
	system(cmd);
	// input (file or keyboard)
	
	// combine string 
	// memcpy [         ] | [ ] //


	
	//strcpy(cmd, SH_PATH); // 	SH_PATH : path + interface
	//strncpy(cmd, SH_PATH, x);
//	printf("%s\n", cmd);	

	//system(cmd);
	
//	printf("rtn = %d : system call \n", rtn);
	
	#if 0
	

	
	
	
	rtn = system("sh /home/jiyoon/Desktop/Git/study1/Shell_Exam/IP_test.sh");
	//system("sh /home/jiyoon/Desktop/Git/study1/Shell_Exam/IP_test.sh");
	
	printf("\nresult = %d\n", rtn);
	//printf("result = %d\n", WEIXTSTATUS(rtn));

	printf("Shell Script!!! \n");
	
	#endif
	return 0;

}
