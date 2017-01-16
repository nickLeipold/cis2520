/*TA office hours, tues 12:00-2pm, fridays 1-3pm, advisory room of reynolds, second floor somewhere*/

/* Nickolas Leipold
** 0930626
** Cis 2520 Assignment 1
*/

#include <stdio.h>
#include <string.h>
#include "carbon.h"


int scramble( char *str, int finish , int start)
{
  
  if(finish == start)//when the indesies are equal print the word
  {
    printf("%s\n",str);
    return 0;
  }
  for(int i=start; i<= finish; i++)
  {
    replace(&str[start], &str[i]);//swaps the two letters
    scramble(str, finish, start+1);//moves up to the next index
    replace(&str[start], &str[i]);
  }
  
  return 0;
  
}

void replace(char *a, char *b)
{
  char temp;//temp char to store the variables being switched around
  temp = *a;
  *a=*b;
  *b=temp;
  
}
