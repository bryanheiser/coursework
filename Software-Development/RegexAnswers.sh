#!/bin/bash
#Bryan Heiser --- Lab 3
if [ $# -eq 0 ]
	then
	echo "Usage: RegExAnswers.sh filename"
	exit 1 
fi

#finds all lines that end in a number
egrep '[0-9]$' $1 | wc -l 
#finds all lines that do not start with a vowel
egrep '^[^aeiouAEIOU]' $1 | wc -l
#finds all lines that are only 12 letters long (resctricted to alphabet)
egrep '^[A-Za-z]{12}$' $1 | wc -l
#finds all lines that are in phone number format
egrep '^[0-9]{3}-[0-9]{3}-[0-9]{4}$' $1 | wc -l
#finds all lines that are in phone number format but start with 303
egrep '^303-[0-9]{3}-[0-9]{4}$' $1 | wc -l
#finds all lines that start with a vowel and end with a number
egrep '^[aeiouAEIOU].*[0-9]$' $1 | wc -l
#finds all lines that end with geocities.com
egrep '.*geocities.com$' $1 | wc -l
#finds all email addresses that are in the incorrect format
#argument -v returns opposite of what is in the quotes ''
egrep '@' $1 | egrep -v '[A-Za-z0-9]{.*}@' | egrep -v '\.' | wc -l
