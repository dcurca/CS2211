/* This is a c program that takes in a phone number and changes it according
to the option specified by the user */
/* Author: Dana Curca, 250976773 */
#include <stdio.h>

int main() { 
	
	int x,y,z,num;

	printf("Please input your 10 digit phone number: ");
	num = scanf("%3d%3d%4d", &x, &y, &z);
	/* checks to make sure that 3 individual numbers are inputted with 
	number of digits 3,3,4 number 1,2,3 exclusively */ 
	if(num != 3) { 
		printf("Error: Bad input!\n");
		return 1; } 
	/* checks to make sure the first number is not less than 100 or 
	greater than 999, if so terminates */
	else if(x < 100 || x > 999) { 
		printf("Error: Bad area code!\n");
		return 2; }
	/* checks to make sure the second number is not less than 100 or 
	greater than 999, if so terminates */
	else if(y < 100 || y > 999) { 
		printf("Error: Bad central office code!\n");
		return 3; }
	/* checks to make sure the third number is not less than 1000 or
	greater than 9999, if so terminates */
	else if(z < 1000 || z > 9999) { 
		printf("Error: Bad line number!\n");
		return 4; }

	printf("Options:\n A)Local\n B)Domestic\n C)International\n D)Odd\n");
 	/* takes in a user defined option */
	printf("Please input your option: ");
	char letter; 
	scanf("\n%c", &letter);
	/* by specification of user this code checks to make sure the option 
	is valid and outputs the apporpriate formatted number for that option */
	switch(letter) { 
		case 'a':
		case 'A': printf("%3d-%4d\n", y, z);
			  break;
		case 'b':
		case 'B': printf("(%3d) %3d-%4d\n", x, y, z);
			  break;
		case 'c':
		case 'C': printf("+1-%3d-%3d-%4d\n", x, y, z);
			  break;
		case 'd': 
		case 'D': printf("%6.4d%6.4d%6.4d\n", x, y, z);
			  break;
		default: printf("Error: Illegal option!\n");
			return 5; 
		} 
	return 0;
}
