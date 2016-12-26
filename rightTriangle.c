/* This program inputs three positive integers a, b, and c and 
   determines is there is a right triangle with side lengths 
   a, b and c.  This will be true if and only if the square of one
   of the numbers is the sum of the squares of the other two
*/

/* 
	Author Vladislav Ignatov
	COP 3514.001
*/

#include <stdio.h>
#include <math.h>

int main(void){
	int a = 0;
	int b = 0;
	int c = 0;
	
	printf("Enter positive integers for a,b,c :");
	scanf("%d %d %d", &a, &b, &c);

	if((pow(b,2)==(pow(a,2)+pow(c,2)))||(pow(c,2)==(pow(a,2)+pow(b,2)))||(pow(a,2)==(pow(b,2)+pow(c,2)))){
		printf("The numbers are the side lengths of the right triangle.\n");
	}else{
		printf("The numbers are not the side lengths of a right triangle.\n");
	}
	return 0;
}
