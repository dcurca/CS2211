#!/bin/bash 
# This shell script takes in two arguments and outputs a picture of a 
# specified animal with either a random generated string or an inputted string
# from the user 
# Dana Curca; dcurca; 250976773

echo 
animal=$1
# if $2 is inputted then ignore $@ (standard input) otherwise ignore $2 and 
# use standard input 
text="${@:2}"
# checks to make sure number of arguments is valid 
if [ $# == 0 ]; then 
	echo "Error: Need at least one argument indicating type of animal"
	exit 1
fi 
# checks to see if user inputted standard input or not
if [ $# -eq 1 ]; then
	file=`shuf -n 1 /cs2211/a2/fortunes.txt`
	# when standard input is not inputted go through cases
	case $animal in 
		"duck")
		echo "$file" | tr [a-zA-Z' '.] -
		echo "< $file >" 
		echo "$file" | tr [a-zA-Z' '.] _
		echo "`cat /cs2211/a2/duck.txt`"
		 ;;
		"dog")
		echo "$file" | tr [a-zA-Z' '.] -
		echo "< $file >"
		echo "$file" | tr [a-zA-Z' '.] _
		echo "`cat /cs2211/a2/dog.txt`" 
		;;
		"cat")
		echo "$file" | tr [a-zA-Z' '.] -
		echo "< $file >"
		echo "$file" | tr [a-zA-Z' '.] _ 
		echo "`cat /cs2211/a2/cat.txt`" 
		;;
		"frog")
		echo "$file" | tr [a-zA-Z' '.] -
		echo "< $file >"
		echo "$file" | tr [a-zA-Z' '.] _
		echo "`cat /cs2211/a2/frog.txt`" 
		;;
		"cow")
		echo "$file" | tr [a-zA-Z' '.] - 
		echo "< $file >"
		echo "$file" | tr [a-zA-Z' '.] _ 
		echo "`cat /cs2211/a2/cow.txt`" 
		;; 
		*) 
		echo "Error: This is not an option, choose either cat, dog, frog, cow, or duck." 
		exit 2
		;;
	esac
else
	# when standard input is inputted go through cases 
	case $animal in 
		"duck")
		echo "$text" | tr [a-zA-Z' '.] - 
		echo "< $text >" 
		echo "$text" | tr [a-zA-Z' '.] _
		echo "`cat /cs2211/a2/duck.txt`" 
		;;
		"cow") 
		echo "$text" | tr [a-zA-Z' '.] -
		echo "< $text >"
		echo "$text" | tr [a-zA-Z' '.] _
		echo "`cat /cs2211/a2/cow.txt`" 
		;;
		"dog") 
		echo "$text" | tr [a-zA-Z' '.] -
		echo "< $text >"
		echo "$text" | tr [a-zA-Z' '.] _
		echo "`cat /cs2211/a2/dog.txt`" 
		;; 
		"cat")
		echo "$text" | tr [a-zA-Z' '.] -
		echo "< $text >"
		echo "$text" | tr [a-zA-Z' '.] _
		echo "`cat /cs2211/a2/cat.txt`" 
		;; 
		"frog")
		echo "$text" | tr [a-zA-Z' '.] -
		echo "< $text >"
		echo "$text" | tr [a-zA-Z' '.] _
		echo "`cat /cs2211/a2/frog.txt`" 
		;; 
		*) 
		# checks to make sure $1 is an option that is accounted for in case
		echo "Error: This is not an option, choose either cat, dog, frog, cow or duck." 
		exit 2
		;; 
	esac
fi 
