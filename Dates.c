/* dates.c  - implementation of functions in dates.h */
/*                                                   */
/* Programmer:  vladislav ignatov */
/*****************************************************/
#include "date.h"
#include <stdio.h>



/* FILL IN THE MISSING CODE BELOW */


int compare_dates(date d1, date d2)
{
    date dateCo_strct;
    if ((d2.year > d1.year) || (d2.month > d1.month) || (d2.day > d1.day)){
        return -1;
    }
    else if ((d1.year > d2.year) || (d1.month > d2.month) || (d1.day > d2.day)){
        return 1;
    }else if (d1.year == d2.year){
        if (d1.day == d2.day && (d1.month == d2.month))
        return 0;
    }
 
    return 0;
}
      

int is_leap_year(int the_year)
{
    //date year_strct ;
    if ((the_year % 4 == 0) && (the_year % 100 == 0 )){
        
        return 1;
    }
    else{
    
        return 0;
        
    }

    
}

int day_of_year(date d)
{
    //date d;
    int mnth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (d.month == 1){
         d.day = d.day;
    }
    
    if (d.year % 4 != 0 ){
            for(int i=0; i < d.month-1; i++){
                d.day += mnth[i];
            }
           d.day += d.day;
        d.day = d.day/2;
    }
    
        else{
            mnth[2] = 28+1;
            for(int i=0; i < d.month-1; i++){
                d.day += mnth[i];
            }
            d.day += d.day;
            d.day = d.day/2;
        }
            
    return d.day;
    
}

int get_age(date birthdate, date today)
{
    int age;
    
    if ((today.day == birthdate.day) && (today.month == birthdate.month)){
        age = today.year - birthdate.year;
    }
    else if (today.month > birthdate.month){
        age = today.year - (birthdate.year)+1;
    }
    else {
        age = today.year - (birthdate.year)-1;
    }
    
    return age;
    
}

int is_birthday(date birthdate, date today)
{
    int birth;
    
    if ((today.day == birthdate.day) && (today.month == birthdate.month)){
        return 1;
    }
    else if (today.month != birthdate.month){
        return 0;
    }
    
    return 0;
}


/* DO NOT MODIFY THE CODE BELOW */
void input_date(date *dp)
{
  scanf("%d/%d/%d",&(dp->month),&(dp->day),&(dp->year));
}

void print_date(date d)
{
  printf("%d/%d/%d",d.month,d.day,d.year);
}

void check_age_and_birthday(date birthdate, date today)
{
   printf("You are %d years old and this is ", get_age(birthdate,today));
   if (!is_birthday(birthdate,today)) {
     printf("not ");
   }
   printf("your birthday\n");
}

void print_submit_status(date start, date end, date submit)
{
  if (compare_dates(submit,start) == -1) {
    print_date(submit);
    printf("\n");
    print_date(start);
    printf("Submission not accepted - too early\n");
  }
  else if (compare_dates(submit,end) == 1) {
    printf("Submission not accepted - too late\n");
  }
  else {
    printf("Submission accepted\n");
  }
}
   
int days_in_month(int month, int leap_year)
{
  int retval= 0;
  switch(month) {
  case 1: case 3:case 5:case 7:case 8:case 10:case 12:
    retval = 31;
          break;
  case 4:case 6:case 9:case 11:
    retval = 30;
          break;
  case 2:
    if (leap_year)
      retval =  29;
    else
      retval = 28;
          break;
  }
    
  return retval;
}
