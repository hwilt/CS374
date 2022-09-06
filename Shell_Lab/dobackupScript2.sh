#!/bin/bash
TODAY = 'date + %F'
BACKUPLOCATION = 'DOCUMENTS'
SUCCESSMESSAGE = "I have successfully back up the directory!"
tar cvjpf ~/myhomedirectory-${TODAY}.tar.bz2 ${BACKUPLOCATION}
echo ${SUCCESSMESSAGE}
