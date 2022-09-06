#!/bin/bash
TODAY = 'date + %F'
SUCCESSMESSAGE = "I have successfully back up the directory!"
tar cvjpf ~/myhomedirectory-${TODAY}.tar.bz2 ${HOME}
echo ${SUCCESSMESSAGE}
