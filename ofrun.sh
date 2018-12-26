#!/bin/bash
make -j4 -s 2>&1 || exit 1
DIR="${PWD##*/}"
if [ $? == 0 ]
then 
	cd bin
        ./$DIR
else
	echo " Errors detected, exiting"
fi
