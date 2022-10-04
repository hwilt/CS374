#!/bin/bash

# this script will find all files in the current directory and all subdirectories and calculate the MD5 checksum for each file 
# and store the results in a file called md5dict.txt with the format of <filename><space><md5checksum>\n

# The for loop is used to iterate through the md5sums.txt file 
find . -type f -exec md5sum {} \; > md5sums.txt

while read -r line
do
    #echo $line
    HASH=`echo $line | cut -f1 -d ' '`
    FILE=`echo $line | cut -f2 -d ' '`
    #echo $HASH
    #echo $FILE
    #Put the md5sum and the file name into the dictionary in the format of "file md5sum"
    echo "${FILE} ${HASH}" >> md5dict.txt 
    
done < md5sums.txt

#echo test,tube | cut -f2 -d','