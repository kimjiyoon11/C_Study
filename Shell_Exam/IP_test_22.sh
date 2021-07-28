#!/bin/bash

printf "\n"

echo "user name : " $USER
echo "home directory : " $HOME
echo "user  name (whoami) : " `whoami`
echo "host name : "  `hostname -i`
echo "ip address : " 

ifconfig

printf "\n"

while :
do
	echo "-------------------------------------"

	printf "\n"

	echo "interface name : " $1
	
#	read stringname

#	echo "Input Value : " $stringname

	stringIP="ifconfig $1 | grep '\<inet\>'"

	printf "\n" 

	if [ "$1" == "q" ];
	then
		echo "stop"
		break
	else
		eval $stringIP		
		echo "${stringIP}" > IP.txt

		if [ $? -eq 0 ];then
       			 echo "succes!"
		else
        		echo "fail!"
		fi
	fi

done

exit 0
