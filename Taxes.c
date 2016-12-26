/* In-Class Programming Assignment - Taxes */
/* Author: Vladislav Ignatov Jan 30, 2015   */

#include <stdio.h>

int main(void)
{
	double gross = 0.0, taxable = 0.0, tax = 0.0, effective = 0.0;
	
	printf("Enter gross salary: ");
	scanf("%lf", &gross);
	
	taxable = gross * 0.8;
	if(taxable < 15000){
		tax = taxable * 0.10;
	}
	
	if(taxable >= 15000){
		taxable -= 15000;
		tax = 15000 * 0.10;
			if(taxable < 20000){
				tax = tax + taxable * 0.20;
			}
		if(taxable >= 20000){
			taxable -= 20000;
			tax = tax + (20000 * 0.20);
			tax = tax + (taxable * 0.25);
		}
	}
	
	effective = (tax / gross) * 100;
	
	printf("Amount of tax: %.0f\n", tax);
	printf("Effective tax rate: %.1f%%\n", effective);
	
	return 0;
}
