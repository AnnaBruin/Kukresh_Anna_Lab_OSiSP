#!/bin/bash
if [ ! -d "$1" ]; then
	echo "Error with finding" 1>&2
elif [ ! "$2" ]; then
        echo "Enter where you want to save the result"
elif  [ ! "$3" ]; then
        echo "Enter the file extension"
else
	(find "$1" -type f -name "*.$3")   >$2
fi
