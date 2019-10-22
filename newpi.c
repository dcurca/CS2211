#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
/* This code takes a number as input and approximates the constant pi */
/* Author: Dana Curca, 250976773 */

double estimate_pi(long long n) {
	long long int i, points = 0; 
	double ratio, a, b;

	for(i = 1; i <= n; i ++) {
		/* generating a random number for both a and b 
		a = (double)rand() / (double)RAND_MAX;
		b = (double)rand() / (double)RAND_MAX;
	
	/* if equation is smaller or equal to 1 then the coordinate lies inside
	the quadrant */
	if (((a*a)+(b*b)) <= 1) {
		points = points + 1;
 		} 
	}

	/* calculates ratio of points located inside the circle to total number 
	of generated points */
	ratio = ((double)points / (double)n);
	return 4*ratio; 
}

int main() { 
	srand(time(0)); 
	long long int N; 
	printf("Enter value for N: "); 
	scanf("%lld", &N); 
	int j; 
	double pi_values[10], sum = 0;
	
	printf("Estimated Pi Value: "); 
	for(j = 0; j < 10; j++) {
		/* recalculates the value of pi using estimate_pi */ 
		pi_values[j] = estimate_pi(N); 
		printf("%d\t\t\t%.10f\n", (j+1), pi_values[j]);
		sum = sum + pi_values[j]; 
	}
	/* calculating the mean */
	double mean = sum/10; 
	double diff = 0; 
	for(j = 0; j < 10; j++) { 
		diff  = diff + pow((pi_values[j] - mean), 2); 
	} 
	/* calculating the standard deviation */
	diff = diff /10; 
	double std = sqrt(diff); 
	printf("Estimated mean = %.10f\n", mean); 
	printf("Standard Deviation = %.10f\n", std);
}
