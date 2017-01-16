/* Nickolas Leipold
** 0930626
** Cis 2520 Assignment 1
*/

#include <stdio.h>
#include <stdlib.h>
#include "ackermann.h"


int ackermann(int m, int n)
{
  if(m == 0 && n>= 0)
  {
    return n+1;
  }
  if ( m > 0 && n ==0 )
  {
    return ackermann(m-1,1);
  }
  if ( m > 0 && n >0)
  {
    return (ackermann(m-1,ackermann(m,n-1)));
  }
  return -1;

}
