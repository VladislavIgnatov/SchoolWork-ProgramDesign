/* magic_square.c
   input a rearrangement of the numbers from 1 to 16,
   display them as a 4x4 matrix with right-aligned columns,
   calculate and print the row, column, diagonal and
   counter-diagonal sums, then print a message stating
   that the matrix is or is not a magic square

programmer: vladislav ignatov
*/

#include <stdio.h>

int main(void){

	int i = 0;
	int j = 0;
	int arr[4][4];
	int final[10];

	printf("Enter the numbers from 1 to 16 in any order, separated by spaces:\n\n");

	for(i = 0; i < 4; ++i){
		for(j = 0; j < 4; ++j){
			scanf("%d", &arr[i][j]);
		}
	}
	
	for(i = 0; i < 4; ++i){
		for(j = 0; j < 4; ++j){

			if(arr[i][j] > 9){
				printf(" %d", arr[i][j]);
			}else{
				printf("  %d", arr[i][j]);
			}

			if(j == 3){
				printf("\n");
			}
		}
	}

	printf("\n");

	// The final array is used to store the data of each sum for comparison later.
	final[0] = arr[0][0] + arr[0][1] + arr[0][2] + arr[0][3];
	final[1] = arr[1][0] + arr[1][1] + arr[1][2] + arr[1][3];
	final[2] = arr[2][0] + arr[2][1] + arr[2][2] + arr[2][3];
	final[3] = arr[3][0] + arr[3][1] + arr[3][2] + arr[3][3];
	final[4] = arr[0][0] + arr[1][0] + arr[2][0] + arr[3][0];
	final[5] = arr[0][1] + arr[1][1] + arr[2][1] + arr[3][1];
	final[6] = arr[0][2] + arr[1][2] + arr[2][2] + arr[3][2];
	final[7] = arr[0][3] + arr[1][3] + arr[2][3] + arr[3][3];
	final[8] = arr[0][0] + arr[1][1] + arr[2][2] + arr[3][3];
	final[9] = arr[0][3] + arr[1][2] + arr[2][1] + arr[3][0];


	printf("Row sums: %d %d %d %d\n", final[0], final[1], final[2], final[3]);
	printf("Column sums: %d %d %d %d\n", final[4], final[5], final[6], final[7]);
	printf("Diagonal sums: %d %d\n", final[8], final[9]);

	printf("\n");
	
	// checks to see if the square is magical!
	if((final[0] == final[1]) && (final[1] == final[2]) && (final[2] == final[3]) && (final[3] == final[4]) && (final[4] == final[5]) && (final[5] == final[6]) && (final[6] == final[7]) && (final[7] == final[8]) && (final[8] == final[9])){
		printf("The matrix is a magic square\n");
	}else{
		printf("The matrix is not a magic square\n");
	}

	return 0;
}
