#!/bin/bash

find . -type 'f' -exec md5sum {} \; 2>/dev/null >> md5dict.txt

#echo test,tube | cut -f2 -d','