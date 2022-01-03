#include <sys/ioctl.h> 
#include <net/if.h>  
#include <string.h> 
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <ifaddrs.h>

#include <unistd.h>

#define MAC_ADDR_LEN 24

char macAddr[MAC_ADDR_LEN + 1];

int main(void){

	int fd;
	struct ifreq ifr;
	struct ifreq ifr1;

	unsigned char *mac0 = NULL;
	unsigned char *mac1 = NULL;
	
	fd = socket(AF_INET, SOCK_DGRAM, 0);

	ifr.ifr_addr.sa_family = AF_INET;
	ifr1.ifr_addr.sa_family = AF_INET;

#ifdef OS_1 //makefile -Dflag
	strncpy(ifr.ifr_name , "wlan0" , IFNAMSIZ-1); //wlan0
	strncpy(ifr1.ifr_name , "wlan1" , IFNAMSIZ-1); //wlan1
#else
	strncpy(ifr.ifr_name , "eno1" , IFNAMSIZ-1); //wlan0
	strncpy(ifr1.ifr_name , "eno2" , IFNAMSIZ-1); //wlan1
#endif

	ioctl(fd, SIOCGIFHWADDR, &ifr);
	mac0 = (unsigned char *)ifr.ifr_hwaddr.sa_data;
	
	ioctl(fd, SIOCGIFHWADDR, &ifr1);	
	mac1 = (unsigned char *)ifr1.ifr_hwaddr.sa_data;
	
	sprintf(macAddr, "%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%", 
						mac0[0], mac0[1], mac0[2], mac0[3], mac0[4], mac0[5], mac1[0], mac1[1], mac1[2], mac1[3], mac1[4], mac1[5]);

	close(fd);

	return TRUE;
}
