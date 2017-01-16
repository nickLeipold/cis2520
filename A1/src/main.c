/* Nickolas Leipold
** 0930626
** Cis 2520 Assignment 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <math.h>
#include "carbon.h"
#include "newton.h"
#include "ackermann.h"


int main(int argc, char * argv[])
{
  if(argc != 5) //checks for the correct number of command line arguments
  {
    printf("incorrect number of arguments\n");
    return 1;
  }
  
  //*******************************carbon scrambler***************
  char string[] = "carbon";/* cant use *string because that points to the litteral which can 
  not be altered, this creates a char array that is filled with the literal,
   so it is open for manipulation*/
   
  scramble(string, (strlen(string)-1), 0);//the string, last index and first index
  
  //***************************** ackermann***************************
  int m = atoi(argv[1]);//inputs of the ackermann function
  int n = atoi(argv[2]);
  
  printf("Ackermann function using %d,%d is %d\n",m,n,ackermann(m,n)); //prints what was inputed and the answer
  
  
  
  //********************************** newton ****************
  double x = atof(argv[3]); //the number to be square rooted
  double tollerance = atof(argv[4]); //accuracy of the root
  double v1; // value for iterative
  double v2; // value for recursive
  double dif;//difference in times
  
  struct timeb start, finish;
  ftime(&start);
  for(int i = 0; i<100000; i++)
  {
    v1 = newtonI(x,tollerance);
  }
  printf("%lf is your newton output from iteration\n", v1); //prints the value after all the iterations
  ftime(&finish);//gets the time after the loop finishes
  
  printf("time for iterative %lf millisecond(s) for 100000 runs\n", (double) (finish.millitm - start.millitm));//prints the time
  dif = (double)(finish.millitm - start.millitm);
  
  ftime(&start);
  
  for(int i = 0; i<100000; i++)//loops through the iteration to gather enough time
  {
    v2 = newtonR(x/2,x,tollerance);
  }
  
  printf("%lf is your newton output from recursion\n", v2);//output 
  
  ftime(&finish);
  
  printf("time for recursive %lf millisecond(s) for 100000 runs\n", (double)(finish.millitm - start.millitm));//time elapsed
  
  printf("recursion is %lf millisecond(s) faster than iteration\n", (dif - (double)(finish.millitm - start.millitm) ));
  
  
  
  return 0;
}
