#!/bin/bash


# this will find all the changes in the files by creating new md5sums and comparing them to the old md5sums

# check if the md5dict.txt file exists
if [ -f md5dict.txt ]
then
    echo "md5dict.txt does exist"
    exit 0
else
    echo "md5dict.txt does not exist"
    exit 1
fi
