/* *********Change project*************/
/* Program creator: Vladislav Ignatov */
/* Date: 10/2/2014                    */

#include <stdio.h>

int main(void){
	int dollarAmount = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int q = 0;

	printf("Enter a dollar amount: ");
	scanf("%d", &dollarAmount);

	i = dollarAmount/20;
	dollarAmount = dollarAmount % 20;
	
	j = dollarAmount/10;
	dollarAmount = dollarAmount % 10;
	
	k = dollarAmount/5;
	dollarAmount = dollarAmount % 5;
	
	q = dollarAmount/1;
	
	printf("$20 bills: %d\n", i);
	printf("$10 bills: %d\n", j);
	printf("$5 bills: %d\n", k);
	printf("$1 bills: %d\n", q);
	
	return 0;
}
