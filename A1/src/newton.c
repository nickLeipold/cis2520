/* Nickolas Leipold
** 0930626
** Cis 2520 Assignment 1
** Mon sept 26th 2016
*/
 
#include <stdlib.h>
#include <stdio.h>
#include "newton.h"
#include <sys/timeb.h>
#include <math.h>



double newtonI ( double x, double t)//iterative newton method
{
  double a = 0;
  a = x/2;
  while( (fabs(a*a - x)) >= t  )
  {
    a = (a+x/a)/2;
    
    
  }
  return a;
  
}

double newtonR ( double a, double x, double t)//recursive newton method
{
  if(fabs(a*a -x) <= t)
  {
    
    return a;
  }
    
  a=(a+x/a)/2;
  return newtonR(a,x,t);
  
}
