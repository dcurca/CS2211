#!/bin/bash 
# this shell script decrypts or encrypts a given file based on a key
# Dana Curca; dcurca; 250976773 

mode=$1
key=$2
output=$3 
# checks to make sure there are only 4 or 3 arguments in total 
if [[ $# != "4" && $# != "3" ]]; then 
	echo "Error: there must be 3 or 4 arguments given"
	exit 1
fi 
# checks to make sure the only mode arguments given are -e or -d
if [[ "$mode" != '-e' && "$mode" != '-d' ]]; then 
	echo "Error: the mode argument must be -e or -d"
	exit 2
fi
# checks to see whether number of arguments is 3
if [ $# -eq "3" ]; then 
	# if number arguments is 3 takes information from standard input
	target=$(</dev/stdin)
	# returns standard input to tempOut
	echo "$target" > tempOut
else 
	target=$4 
	if [ ! -e $target ]; then 
		echo "Error: the target file does not exist"
		exit 3
	fi 
fi  

if [ $mode == "-d" ]; then
	# changes all lowercase letters to capital from $4 and sends it to $3
	tr '[:lower:]' '[:upper:]' < $4 > $3
	# decodes file from $3 and sends to tempOut
	tr $key A-Z < $3 > tempOut 
	# redirects tempOut into $3 
	cat tempOut > $3 
else 
	tr '[:lower:]' '[:upper:]' < tempOut > $3
	# encodes file from $3 and sends to tempOut
	tr A-Z "$key" < $3 > tempOut
	# redirects tempOut into $3
	cat tempOut > $3   
fi  
