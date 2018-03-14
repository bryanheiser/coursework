#!/bin/bash
#Bryan Heiser
if [$# -eq 0]
	then
	echo "Usage: Grades.sh filename"
	exit 1
fi

while IFS=' ' read ID Fname Lname x y z || [[ -n $Lname ]]; do
	var=$((x+y+z))
	avg=$((var/3))
	printf "%s [%s] %s, %s \n" $avg $ID $Lname $Fname;
done < "$1" | sort -k 3,3 -k 4,4 
