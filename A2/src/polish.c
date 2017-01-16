/*
  *Nickolas Leipold
  *cis 2520
  *Oct 17 2016
  *assignment 2
  *0930626
  *nleipold@mail.uoguelph.ca
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct Stack
{
  float data[128];
  int topIndex;

};

typedef struct Stack Stack;

int main(int argc, char * argv[])
{

  if(argc != 2)//checks for the correct number of command line arguments
  {
    printf("incorrect number of arguments\n");
    return 1;
  }
  char * temp = argv[1];
  float final;
  Stack stack;
  stack.topIndex =0;
  
  for (int i=0; i<strlen(temp);i++)
  {
    if(temp[i] == '1' || temp[i] == '2' ||temp[i] == '3' ||temp[i] == '4' ||temp[i] == '5' ||temp[i] == '6' ||temp[i] == '7' ||temp[i] == '8' ||temp[i] == '9') 
    {
      
      
      float num1;
      num1 =(float)(temp[i] -48);//converts char to int
      stack.data[stack.topIndex] = num1;
      stack.topIndex += 1;
      
    }
    if(temp[i] == '+')
    {
      float num1;
      float num2;
      stack.topIndex --;//decrements index from getting the opperand
      num2 =stack.data[stack.topIndex];
      stack.topIndex --;
      num1 =stack.data[stack.topIndex];
      
      stack.data[stack.topIndex] = num1 + num2;
      //printf("output: %.2f\n",stack.data[stack.topIndex]);
      final = stack.data[stack.topIndex];
      stack.topIndex ++; //moves up one for the next number
    
    }
    if(temp[i] == '-')
    {
      float num1;
      float num2;
      stack.topIndex --;
      num2 =stack.data[stack.topIndex];
      stack.topIndex --;
      num1 =stack.data[stack.topIndex];
      
      stack.data[stack.topIndex] = num1 - num2;
      //printf("output: %.2f\n",stack.data[stack.topIndex]);
      final = stack.data[stack.topIndex];
      stack.topIndex ++;
    }
    if(temp[i] == '*')
    {
      float num1;
      float num2;
      stack.topIndex --;
      num2 =stack.data[stack.topIndex];
      stack.topIndex --;
      num1 =stack.data[stack.topIndex];
      
      stack.data[stack.topIndex] = num1 * num2;
      //printf("output: %.2f\n",stack.data[stack.topIndex]);
      final = stack.data[stack.topIndex];
      stack.topIndex ++;
    }
    if(temp[i] == '/')
    {
      float num1;
      float num2;
      stack.topIndex --;
      num2 =stack.data[stack.topIndex];
      stack.topIndex --;
      num1 =stack.data[stack.topIndex];
      
      stack.data[stack.topIndex] = num1 / num2;
      //printf("output: %.2f\n",stack.data[stack.topIndex]);
      final = stack.data[stack.topIndex];
      stack.topIndex ++;
    }
    
    
  
  }
  
  printf("output: %.2f\n",final);


}
