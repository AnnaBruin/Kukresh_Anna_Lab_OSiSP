#!/bin/bash
if [ ! -d $4 ]; then  #Proverka na katalog
echo "Error opening" 1>&2   #(potoki) from stdout to stderr    
else
find="find $4 -type f"
$find -size +$1c -size -$2c -printf "%h, %f, %s\n" 1>$3
echo "Number of files:"
$find | wc -l
fi
exit
