#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int get_seed(void);
// Prompt for and input an integer to be used with srand
// The seed must be between 1 and 30, inclusive, and input
// verifcation should be done (including level0 verification)

int roll_dice(void);
// Generates two random integers between 1 and 6,
// Computes the sum, prints "You rolled " + the sum,
// then returns the sum

int play_game(void);
// Plays a single game of Craps:
// After initial roll, if the result is known immediately either
// announces win and returns 1 or announces loss and returns 0
// If it result is not immediate, sets the "point" and rolls 
// the dice until either 7 or the point is rolled, and then
// announces the result and returns either 0 or 1

int main()
{
  int games_won = 0, games_lost = 0;
  char response = 'y';

  printf("\nWelcome to the Computer Game of Craps\n\n");

  srand(get_seed());

  do {
    if (play_game())
      {
	games_won++;
      }
    else
      {
	games_lost++;
      }

    printf("Play again?\n\n");
    // get one character
    scanf(" %c",&response);
    // clear the input buffer
    while(getchar() != '\n');

    while(tolower(response) != 'y' && tolower(response) != 'n')
      {
	printf("Invalid entry, must be y or n\n");
	printf("Play again?\n\n");
	scanf(" %c",&response);
	while(getchar() != '\n');
      }

  } while (tolower(response) == 'y');

  printf("\nWins: %d   Losses: %d\n\n",games_won,games_lost);
  return 0;
}

int get_seed(void)
{
  int i = 0;
  char ch;
  do{
    i = 0;
    printf("Please enter an integer between 1 and 30:\n");

    if(scanf("%d", &i) != 1){ // Checks if there is an input 
      while((ch = getchar()) != '\n'); 
      printf("Your entry must start with a digit; try again\n\n");
      continue;
    }

    while((ch = getchar()) != '\n'); 

    if(i < 1){
      printf("Value must be at least one; try again\n\n");
      continue; 
    }

    if(i > 30){
      printf("Value must be at most 30; try again\n\n");
      continue;
    }

    }while((i < 1) || (i > 30)); 
  return i;
}


int roll_dice(void)
{
  int sum = 0;
  sum = ((rand() % 6 ) + 1) + ((rand() % 6 ) + 1);
  printf("You rolled %d\n", sum); 
  return sum;
}


int play_game(void)
{
  int data = 0;
  int datanew = 0;

  data = roll_dice();

  if((data == 2) || (data == 12)){
    printf("You lose!\n\n");
    return 0;
  }

  if((data == 7) || (data == 11)){
    printf("You win!\n\n");
    return 1;
  }else{
    //printf("Your point is %d\n", data);
    while(datanew != 7){
      datanew = roll_dice();
      if(data == datanew){
        printf("You win!\n\n");
        return 1;
      }
    }
    printf("You lose!\n\n");
    return 0;
  }
}



