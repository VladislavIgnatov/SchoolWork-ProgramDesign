/*
Program assignment name: Octal

Author: Vladislav Ignatov
Date: 1/22/14
*/

#include <stdio.h>

int main(void){

	int inputNum = 0;
	int holdNum = 0;
	int outputNum = 0;
	
	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &inputNum);
	
	while((inputNum < 0)||(inputNum > 32767)){
		printf("Enter a number between 0 and 32767: ");
		scanf("%d", &inputNum);
	}
	
	outputNum = inputNum % 8;
	inputNum /= 8;
	holdNum = inputNum % 8;
	outputNum = outputNum + (holdNum * 10);
	inputNum /= 8;
	holdNum = inputNum % 8;
	outputNum = outputNum + (holdNum * 100);
	inputNum /= 8;
	holdNum = inputNum % 8;
	outputNum = outputNum + (holdNum * 1000);
	inputNum /= 8;
	holdNum = inputNum % 8;
	outputNum = outputNum + (holdNum * 10000);
	
	printf("In octal, your number is: %05d", outputNum);
	return 0;
}
