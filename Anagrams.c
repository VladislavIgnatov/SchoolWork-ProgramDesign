/*
Program assignment name: Anagrams

Author: Vladislav Ignatov 2/18/15
*/

#include <stdio.h>
#include <ctype.h>

int main(void){
	
	int x = 0;
	int y = 0;
	char ch;
	int count[26];

	// populate's the array with zeros
	x = 0;
	for(x =  0; x < 26; ++x){
		count[x] = 0;
	}

	printf("Enter first word:\n");
	while ((ch = getchar()) != '\n'){
		
		if(isalpha(ch)){
			ch = toupper(ch);
			++count[ch - 'A'];
		}

	}

	printf("Enter second word:\n");
	while ((ch = getchar()) != '\n'){
		
		if(isalpha(ch)){
			ch = toupper(ch);
			--count[ch - 'A'];
		}

	}

	for(x=0; x < 26; ++x){

		if(count[x] != 0){
			++y;
			printf("The words are not anagrams\n");
			break;
		}
	}

	if(y == 0){
		printf("The words are anagrams\n");
	}

	return 0;
}
