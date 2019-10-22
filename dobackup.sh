#!/bin/bash
# This is a shell script that allows the user to input a specified directory 
# to backup 
# Dana Curca; dcurca; 250976773 

directories=`ls -d */ | tr [/] [" "]`
j=1
#outputs a list of directories while also storing the number of directories
#and outputting that number as "j"
for i in $directories; do 
	echo "$j) $i"
	((j++))
done 
read -p "Choose a directory to backup: " reply

while [ $reply != "0" ]; do  
	j=1
	#runs through all directories until it finds the one specified
	for i in $directories; do 
		if [ $reply == $j ]; then
			# when directory specified is found output backup file name
			directory=$i 
			echo "$directory-backup-`date +%d`-`date +%m`-`date +%Y`.tar"  		
		fi 
		#increment unless 0 is inputted
		((j++))
	done 
	read -p "Choose a directory to backup: " reply
done 

# if 0 is inputted then print and stop the shell script 
if [ $reply == "0" ]; then 
	echo "Goobye"
	exit 1
fi 
