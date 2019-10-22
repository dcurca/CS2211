#include <stdio.h>
/* This program determines the smallest number of 20,10,5,2, and 1 bills/coins
necessary to pay a user specified dollar amount */
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *loonies);
/* Author: Dana Curca, 250976773 */
int main(void) { 
	
	int dollars;
	int twenties, tens, fives, toonies, loonies; 

	printf("Enter your dollar amount: "); 

	/* input buffer that clears when encountering an invalid input */	
	if(scanf("%d", &dollars) == 0) {
		while(getchar() != '\n');
		printf("Error: the dollar amount is not a number"); 
		return 1;
	}
	/* checks to make sure that the user specified dollar amount is not negative */
	if(dollars < 0) { 
		printf("Error: please enter a valid amount");
		return 2;
	}

	pay_amount(dollars,&twenties,&tens,&fives,&toonies,&loonies);
	printf("The dollar amount can be made using: %d twenties, %d tens, %d fives, %d toonies, %d loonies", twenties, tens, fives, toonies, loonies);
	return 0;
}
/* calculates the amount of each change needed for the particular specified dollar amount */
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *loonies) {
*twenties = dollars/20;
*tens = (dollars - (*twenties)*20)/10;
*fives = (dollars - (*twenties)*20 - (*tens)*10)/5;
*toonies = (dollars - (*twenties)*20 - (*tens)*10 - (*fives)*5)/2;
*loonies = (dollars - (*twenties)*20 - (*tens)*10 - (*fives)*5 - (*toonies)*2); 
}
	
