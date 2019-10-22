#!/bin/bash
# This shell script gets an infinite number of inputs, it checks for various 
# cases and in the end computes the calculations including distance, max 
# distance, and total distance 
# Dana Curca; dcurca; 250976773

x1=$1
y1=$2
x2=$3
y2=$4

# makes a variable equal to whether or not the number of arguments is even or odd
even=$(( $# % 2 )) 
if [ $# -lt 4 ]; then 
	echo "Error: need at least 4 arguments"
	exit 1
fi
 
# checks to make sure number of arguments is even 
if [ ! $even -eq 0 ]; then 
	echo "Error: need an even number of arguments"
	exit 2 
fi

# checks to make sure that arguments are only integers 
if ! [[ $x1 =~ ^[0-9]+$ && $x2 =~ ^[0-9]+$ &&  $y1 =~ ^[0-9]+$ && $y2 =~ ^[0-9]+$ ]]; then 
	echo "Error: integers only"
	exit 3
fi 

#variable initialization 
total=0
longestD=0
count=0
firstX=$x1
firstY=$y1
# checks to make sure number of arguments supports base case 
while [ $# -gt "2" ]; do
	#compute calculations
	pair1=`echo "scale=2; ($x1-$x2)^2" | bc` 
	pair2=`echo "scale=2; ($y1-$y2)^2" | bc`
	distance=`echo "scale=2; sqrt($pair1 + $pair2)" | bc`
	total=`echo "scale=2; $total + $distance" | bc`
	let "count++"
	if (( $(echo "$distance > $longestD" | bc -l))); then
		longestD=$distance
	fi 
	SecondX=$x2
	SecondY=$y2
 	
	# shift to get next (x,y) pair 
	shift
	shift

	x1=$1
	x2=$3
	y1=$2
	y2=$4
done 
# echos the total, longest distance and average distance
echo "Total path length: "$total""
echo "Longest distance between two points: "$longestD""
average=`echo "scale=2; $total / $count" | bc` 
echo "Average distance between two points: "$average"" 

# checks to see if last (x,y) pair is equal to first (x,y) pair 
if [[ $firstX -eq $SecondX && $firstY -eq $SecondY ]]; then 
	echo "Path leads to start."
else 
	# if they do not equal then calculate and echo distance between first and last (x,y) pair
	pair1=`echo "scale=2; ($firstX - $SecondX)^2" | bc`
	pair2=`echo "scale=2; ($firstY - $SecondY)^2" | bc`
	Distance=`echo "scale=2; sqrt($pair1 + $pair2)" | bc`
	echo "Path leads "$Distance" distance from start."
fi 
 
