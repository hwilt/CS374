#!/bin/bash


# this will find all the changes in the files by creating new md5sums and comparing them to the old md5sums

# check if the md5dict.txt file exists
if [ -f md5dict.txt ]; then
    while read -r line; do  
        # split the line into the file name and the md5sum
        file=$(echo $line | cut -d ' ' -f1)
        md5sum=$(echo $line | cut -d ' ' -f2)
        # check if the file exists
        #echo $file
        if [ -f "$file" ]; then
            # get the new md5sum of the file with find command
            new_md5=$(find $file -type f -exec md5sum {} \; | awk '{print $1}')
            # check if the md5sums are different
            if [ "$md5sum" != "$new_md5" ]; then
                echo "$file has been changed"
              
            #else
                #echo "$file has not been changed"
            fi
        else
            echo "$file does not exist anymore"
        fi
    done < md5dict.txt
    # create a new md5dict.txt file
    find . -print0 | while IFS= read -r -d '' file; do 
        # Your code here, which can use the ${line} variable
        # if the file is not in the md5dict.txt file, add it to the md5dict.txt file
        if ! grep -q "$line" md5dict.txt; then
            echo "$file has been created"
            find $file -type f -exec md5sum {} \; | awk '{print $2 " " $1}' > md5dict.txt
        fi
    done
else
    echo "md5dict.txt does not exist"
    # create the md5dict.txt file
    find . -type f -exec md5sum {} \; | awk '{print $2 " " $1}' > md5dict.txt
fi

