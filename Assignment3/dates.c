#include <stdio.h>
#include <stdlib.h>
/* program that takes in multiple dates and outputs the one closest to the 
current date */
/* Author: Dana Curca, 250976773 */
int main(void) { 

	int month, day, year;
	int latestMonth = 0, latestDay = 0, latestYear = 0;

	while(1) {
		printf("Please enter a date: "); 

		/* input buffer that is cleared when given invalid input */
		if (scanf("%d/%d/%d", &month, &day, &year) != 3) { 
			while(getchar() != '\n');
			printf("Error: Invalid format!\n");
			continue;
		}
		/* checks to see if month is 0/0/0 if so breaks */
		if (month == 0 && day == 0 && year == 0) {  
			if (latestMonth == 0 && latestDay == 0 && latestYear == 0) {
				printf("Error: At least one date must be inputted"); 
				return 1;
			}
			break;	
		}	
		/* checks to see if the month inputted is valid */
		else if(month < 1 || month > 12) {
			printf("Error: Invalid month\n");
			if(month > 1 || month < 12) {     
				printf("Please enter a date: ");
				scanf("%d/%d/%d", &month, &day, &year); }
			else {   
				return 2; } 
		}
		/* checks to see if the day inputted is valid */
		else if(day < 1 || day > 31) {
			printf("Error: Invalid day\n");
			if(day > 1 || day < 31) {  
				printf("Please enter a date: ");
				scanf("%d/%d/%d", &month, &day, &year); }
			else {  
				return 3;}  
		}
		/* checks to see if the year inputted is valid */
		else if(year < 0 || year > 99) { 
			printf("Error: Invalid year\n");
			if(year > 0 || year < 99) {  
				printf("Please enter a date: ");
				scanf("%d/%d/%d", &month, &day, &year); }
			else { 
				return 4; }  
		}
		
		else {
			/* checks for greatest year */
			if(year > latestYear) {
				latestYear = year; 
				latestDay = day; 
				latestMonth = month;
			}
			/* checks for greatest month */
			else if(year == latestYear) {
				if(month > latestMonth) {
					latestYear = year; 
					latestMonth = month;
					latestDay = day;
				}
				/* checks for greatest day */
				else if(month == latestMonth) {
					if(day > latestDay) {
						latestYear = year;
						latestMonth = month; 
						latestDay = day;
					}
				}
			}
		}
	}
	printf("The latest date is: %.2d/%.2d/%.2d", latestMonth, latestDay, latestYear);
	return 0;
}
