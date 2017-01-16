/* nickolas leipold
 * 0930626
 * assignment 3 2520
 * Due nov.7th 
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "openFile.h"
#include "q2.h"

int main (int argc, char * argv[])
{
  FILE * fileStream;
  fileStream = openStream("assets/f.dat");
  storeFile(fileStream);
  closeStream(fileStream);

}

void storeFile(FILE * fileStream)
{
  char string[100];
  int num1 = 1;
  int array[21][11];//one extra to store the key value and the start empty node
  while(fgets(string,100, fileStream) != NULL)
  {
    char * temp;
    
    int num2 = 0;
    temp = strtok(string," \0\n");
    while( temp != NULL &&strcmp(temp, "\n") && num2 <10)
    {
      
      array[num1][num2] = atoi(temp);
      temp = strtok(NULL," ");
      num2++;
    
    }
    array[num1][10] = array[num1][0] +array[num1][1]+array[num1][2]; //adds the key to the back of the array
    
    num1++;
    
  
  }
  printf("\n");
  downHeap(array);
  
  
  
}

void downHeap(int array[21][11])
{
  int maxPar = 21/2;
  for(int j=maxPar; j>0; j--)
  {
    for(int i =maxPar; i >0 ; i--)
    {
      if(i < 10 && array[i][10] < array[i*2+1][10])
      {
        swap(array[i],array[i*2+1]);
      }
      else if(array[i][10] < array[i*2][10])
      {
        swap(array[i],array[i*2]);
      }
    }
  }
  
  printArr(array);
  
}

void swap(int array[11], int array2[11])
{
  int temp[11];
  for(int i = 0; i < 11;i++)
  {
    temp[i] = array[i];
    array[i] = array2[i];
    array2[i] = temp[i];
  }
  
}

void printArr(int a[21][11])
{
  for (int i=1; i<21; i++)
  {
    for (int j=0; j<10; j++)
    {
      printf("%02d ",a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}





