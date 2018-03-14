#!/bin/bash
#Bryan Heiser
if [ $# -eq 0 ]
	then
	echo "Usage: GradesAwk.sh filename"
	exit 1
fi

while IFS=' ' read ID Fname Lname x y z || [[ -n $Lname ]]; do
	awk '{a=($4+$5+$6)/3} {print a=sprintf("%.0f",a), "[" $1 "]", $3 ",", $2}'
done < "$1" | sort -k 3,3 -k 4,4
