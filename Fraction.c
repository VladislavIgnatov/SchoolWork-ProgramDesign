#include <stdio.h>
#include <limits.h>
#include <stdlib.h> 
#include "Fraction.h"

int gcd(int a, int b)
{
   if (a == 0 && b == 0) {
      printf("Illegal args to gcd: %d, %d\n",a,b);
      exit(1);
   }
   int aa = abs(a);
   int bb = abs(b);
   if (aa == 0)
      return bb;
   if (bb == 0)
      return aa;
   return gcd(bb,aa%bb);
}

Fraction string_to_fraction(const char *S)
{
Fraction result = {0,1};
/* Place your code here to initialize the Fraction result
as specified in the string S (using sscanf)
*/
sscanf(S, "%d/%d", &result.numer, &result.denom);
reduce_fraction(&result);
return result;
}

void fraction_to_string(Fraction R,char repr[])
{
repr[0] = 0;
/* Place your code here to place the string representation
of the Fraction R in the character array repr using
sprintf.
*/
reduce_fraction(&R);
if(R.denom != 1){
   sprintf(repr,"%d/%d", R.numer, R.denom);
}else{
   sprintf(repr,"%d", R.numer);
}

}


int compare_fractions(Fraction L, Fraction R)
{
/* Place your code here to return 1 if L and R
have the same value as Fractions, 0 if not
*/
   reduce_fraction(&L);
   reduce_fraction(&R);

   if((L.numer == R.numer) && (L.denom == R.denom)){
      return 0;
   }else if(((double)L.numer / L.denom) > ((double)R.numer / R.denom)){
      return 1;
   }else{
      return -1;
   } 
}


void reduce_fraction(Fraction *R)
{
/* Place your code here to modify the Fraction being passed
in by reference so that it is reduced according to the
specifications in Instructions.pdf
*/
int data;

data = gcd(R->numer, R->denom);

if(R->denom < 0){
   R->numer /= data;
   R->denom /= data;
   R->numer *= -1;
   R->denom *= -1;
}else{
   R->numer /= data;
   R->denom /= data;
} 
   
}

Fraction add_fractions(Fraction L, Fraction R)
{
Fraction result = {0,1};
/* Place your code here to make result a reduced
Fraction representing the sum of the Fractions L and R
*/
   int f1, f2;
   f1 = R.denom;
   f2 = L.denom;

   result.numer = f1 * L.numer + f2 * R.numer;
   result.denom = f1 * f2; 
   reduce_fraction(&result);

return result;
}


