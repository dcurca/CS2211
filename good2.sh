#!/bin/bash 
#this shell reads the current time on your computer and computes a welcoming 
#statement depending on whether it is morning, afternoon or evening
# Dana Curca; dcurca; 250976773

echo 
hour=`date +%H`
# changed the code to a while with two inner if statements 
while [ $hour -lt 18 ]; do 
	if [ $hour -lt 12 ]; then 
		echo "GOOD MORNING"	
	fi 
	if [ $hour -lt 18 ]; then 
		echo "GOOD AFTERNOON"	
	fi 
done 

if [ $hour -gt 18 ]; then 
	echo "GOOD EVENING"
fi 

day=`date +%A`
# checks to see what the variable day was given and outputs the 
# correct message
case $day in 
	"Friday")
		echo "Thank Goodness It's Friday"
	;;
	"Wednesday")
		echo "It's Wednesday My Dudes"
	;;
	"Saturday"|"Sunday")
		echo "Have a Nice Weekend"
	;;
	*)
		echo " "
	;; 
esac 
