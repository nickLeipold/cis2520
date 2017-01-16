/* nickolsa leipold
 * 0930626
 * assignment 3 2520
 * Due nov.3rd 
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "q1.h"

int main ( int argc, char * argv[])
{
  char * args[40];
  //printf("%s\n",argv[1]); //prints the equation after input
  parseEqn(argv[1], args);
  
}

void parseEqn(char * str, char ** args)
{
    
  int brackets= 0;
  int holder = 1;
  for(int i = 0; i < strlen(str); i++)
  {
    if(str[i]== '(')
    {
      brackets++;
    }
    
    if(i != strlen(str)  && str[i] == '(' && str[i+1] != '(' )
    {
      char item[10] ="";
      while(str[i] != ')')
      {
        char temp[10] ="";
        sprintf(temp,"%c",str[i]); // make the char into a string
        //printf("%s\n",temp); //prints the current character in the string
        
        //sprintf(args[holder], "%s%s",args[holder],temp);
        strcat(item,temp);
        i++;
      }
      
      i++;
      strcat(item,")");
      //printf("out of loop");
      args[holder] = item;
      printf("%s\n",args[holder]);
      holder++;
      brackets--;
      parseEqn(args[holder],args);
      
      //printf("%c\n\n",str[i]);
      
    }
    if (str[i] != '(' && str[i] != ')' && brackets == 1 && (str[i] == '+' || str[i] == '-' || str[i] == '*'|| str[i] == '/'))
    {
      char temp[10] ="";
      char item[10] ="";
      sprintf(temp,"%c",str[i]);
      args[holder] = temp;
      printf("root%s\n",args[holder]);
      
      if(str[i+1] != '(')
      {
        i++;
        sprintf(temp,"%c",str[i]);
        strcat(item,temp);
        args[holder] = item;
        printf("in holder%s\n",args[holder]);
        break;
      }
      
        
    }
    if ( brackets != 1 && (str[i] == '+' || str[i] == '-' || str[i] == '*'|| str[i] == '/'))
    {
      char temp[10] ="";
      sprintf(temp,"%c",str[i]);
      args[holder] = temp;
      printf("%s\n",args[holder]); //*******************************need to get the last number after the root into the holder
      
    }
    if(str[i] == ')')
    {
      brackets--;
    }
    
  }
  

}
 
