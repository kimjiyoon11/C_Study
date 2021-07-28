#!/bin/bash

IPstring=`ifconfig enp0s3 | grep '\<inet\>'`
echo "${IPstring}" > terss.txt
#echo $IPstring

#$IPstring > text.txt
#eval `$IPstring` > text.txt
#ifconfig > test.txt
