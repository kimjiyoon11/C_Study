#!/bin/sh
echo "user name : " $USER
echo "home directory : " $HOME
echo "user name : " : `whoami`
echo "host name : " `hostname -i`
echo "ip address : " `ifconfig enp0s8 | grep '\<inet\>'`

echo " file name : "
read fname

if [ -f $fname ] && [ -s $fname ] ; then
	head -5 $fname
else
	echo " No file"
fi


num1=100
num2=$num1+200
echo $num2
num3=`expr $num1 + 200`
echo $num3
num4=`expr \( $num1 + 200 \) / 10 \* 2`
echo $num4

WhileSum=0
i=1

while [ $i -le 10 ]
do
	WhileSum=`expr $WhileSum + $i`
	i=`expr $i + 1`

done
echo " 1 ~ 10 : " $WhileSum



UntilSum=0
j=0

until [ $j -gt 10 ]
do
	UntilSum=`expr $UntilSum + $j`
	j=`expr $j + 1`
done
echo "1 ~ 10 Until : " $UntilSum



echo "------------------------------------"
echo "------------------------------------"

echo ""
echo "loop start"

while [ 1 ] ; do
	read input
	case $input in
		b | B )
			break;;
		c | C )
			echo "continue!!"
			continue ;;
		e | E )
			echo "program exit"
			exit 1;;

		esac;

	done
	echo "break : while close"
       	

	myFunction (){
		echo "in Function"
		return
	}

myFunction

stringEval="./script.sh"

echo $stringEval
eval $stringEval


exit 0


