/* -------- mileage.c -------------

Compute mileage for several tankfuls of gas, and then the overall mileage
for all tankfuls.

Programmer: Vladislav Ignatov

Date: 2/10/15

*/
 #include<stdio.h>
 
int main(void)
{
	double usedGas = 0;
	double milesDriven = 0;
	double totalusedGas = 0;
	double totalmilesDriven = 0;
	double final = 0;
	
	printf("Enter the gallons used (-1 to end):\n");
	scanf("%lf", &usedGas);
	
	while(usedGas != -1){
		totalusedGas = totalusedGas + usedGas;
		
		printf("Enter the miles driven:\n");
		scanf("%lf", &milesDriven);
		totalmilesDriven = totalmilesDriven + milesDriven;
		
		printf("The miles/gallon for this tank was %f\n\n", milesDriven / usedGas );
		
		printf("Enter the gallons used (-1 to end):\n");
		scanf("%lf", &usedGas);
	}
	
	final = totalmilesDriven / totalusedGas;
	printf("\nThe overall miles/gallon was %f\n", final );
	
	return 0;
}
