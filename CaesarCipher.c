/* Caesar Cipher Project
   Input a message and a shift amount
   then prints out the encrypted message

   Programmer: Vladislav Ignatov
   Date: 10/29/14
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char encrypt(char in, int key){
    if(isalpha(in)){
        if(islower(in)){
            in = ((in -'a') + key) % 26 + 'a';
        }
        if(isupper(in)){
            in = ((in - 'A') + key) % 26 + 'A';
        }
    }
    return in;
}

int main(){

    int key = 0;
    char data;

    printf("Enter shift amount (1-25): ");
    scanf("%d ", &key);

    printf("Enter message to be encrypted: \n");

    printf("Encrypted Message: ");

    while ((data = getchar()) != '\n'){
          putchar(encrypt(data, key));
    }
    
    putchar('\n');
    
    return 0;
}
