#!/bin/bash
if test  $# -eq 0
then 
	echo "Must provide an argument"
	exit 1
fi

if test "$1" = "-c"
then 
#	ls | wc -l
#	ls | wc -c
	echo "The number of files"
	echo "How many bytes"
fi

if test "$1" = "-l"
then
#	ls -a
	echo "List all the files"
fi

if test "$1" = "--help"
then
	echo "How to run this script"
#	echo "The test.sh shell script supports only one command line argument, "-c", "-l", or "--help""
fi

if test ! -e backup
then 
	mkdir backup
	mv backup ~/
fi

echo "The number of files and directories in the current path is: "
ls | wc -l
echo "The amount of bytes these files and directories consume is: "
ls | wc -c
