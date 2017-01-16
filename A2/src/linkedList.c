#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"


Car * createRecord(char * plate, int mileage, int returnDate)
{
  if(strlen(plate)>= 50 || mileage <=0 )
  {
  	return NULL;
  }
  Car * ptr;
  ptr = malloc(sizeof(Car));
  
  if(ptr == NULL)
  {
    printf("couldn't malloc for memory\n");
    return NULL;
  }
  
  ptr->plate=malloc(sizeof(char) * strlen(plate));
  strcpy(ptr->plate,plate);
  ptr->mileage= mileage;
  ptr->returnDate = returnDate;
  ptr->next = NULL;
  
  return ptr;
}

char * printRecord(Car * toPrint)
{
  if(toPrint == NULL)
  {
    //empty list
    return NULL;
  }
  char * str;
  str = malloc(sizeof(char)*105);
  if(str == NULL)
  {
    printf("couldn't malloc for memory\n");
    return NULL;
  }
    
  sprintf(str, "plate: %s mileage: %d return date: %d",toPrint->plate,toPrint->mileage, toPrint->returnDate);

  return str;
}

void destroyRecord(Car * toDie)
{
  if(toDie != NULL)
  {
    free(toDie->plate);
    free(toDie);
  }

}

Car * addToFront(Car * theList, Car * toBeAdded)
{
  if(theList == NULL)//if the list is empty the toBeAdded is the new list
  {
    if(toBeAdded != NULL)
    {
      return toBeAdded;
    }
    return NULL;
  }
  
  toBeAdded->next = theList;//adds the list to the end of toBeAdded, making the new list
  return toBeAdded;

}

Car * addToBack(Car * theList, Car * toBeAdded)
{
  if(theList == NULL)//if the list is empty the toBeAdded is the new list
  {
    return toBeAdded;
  }
  Car * tempPtr;
  tempPtr = theList;
  
  while(tempPtr->next != NULL)//finds the last index in the list
  {
    tempPtr = tempPtr->next;
  }
  
  tempPtr->next = toBeAdded;
  return theList;


}

Car * addLowestIntFirst(Car * theList, Car * toBeAdded)
{
  //toBeAdded->next = NULL;
  if(theList == NULL)//if the list is empty the toBeAdded is the new list
  {
    return toBeAdded;
  }
  Car * tempPtr = NULL;
  Car * prev = NULL;
  tempPtr = theList;
  
  
  if(toBeAdded->returnDate == 0)
  {
    if(toBeAdded->mileage <= tempPtr->mileage)//this section works
    {
      toBeAdded->next = tempPtr;
      return toBeAdded;
    }
    while(tempPtr !=NULL && tempPtr->mileage < toBeAdded->mileage)//checks the current list and to be added , adds the smaller mileage first in the list
    {
      prev = tempPtr;
      tempPtr = tempPtr->next;
    }
    toBeAdded->next = tempPtr;
    prev->next = toBeAdded;
    
  }  
  else
  {
    if(toBeAdded->returnDate <= tempPtr->returnDate)
    {
      toBeAdded->next = tempPtr;
      return toBeAdded;
    }
    while(tempPtr !=NULL && tempPtr->returnDate < toBeAdded->returnDate)//checks the current list and to be added , adds the smaller mileage first in the list
    {
      prev = tempPtr;
      tempPtr = tempPtr->next;
    }
    toBeAdded->next = tempPtr;
    prev->next = toBeAdded;
  }
  
  return theList;


}

Car * removeFromFront(Car * theList)
{
  
  if( theList == NULL)
  {
    return NULL;
  }
  if(theList != NULL)
  {
    
    theList = theList->next;
    
    
  }

  return theList;
}

//*****************************************************************************************************
Car * removeFromBack(Car * theList)
{
  if( theList == NULL)
  {
    return NULL;
  }
  Car * temp;
  temp = theList;
  
  while(temp->next->next != NULL)
  {
    temp = temp->next;
  }
  
  temp->next =NULL;
  return theList;
}

Car * removeSpecified(Car * theList, char * plate)
{
  if( theList == NULL)
  {
    return NULL;
  }
  Car * tempPtr=NULL;
  Car * prev =NULL;
  tempPtr = theList;
  
  if(strcmp(tempPtr->plate,plate) == 0)
    {
      
      return theList->next;
    }
  
  while(tempPtr !=NULL && strcmp(tempPtr->plate,plate) != 0)//checks the current list and to be added , adds the smaller mileage first in the list
    {
      prev = tempPtr;
      tempPtr = tempPtr->next;
    }
    
    prev->next = tempPtr;

  return theList;
}

Car * getSpecified(Car * theList, char * plate)
{
  if(strcmp(theList->plate, plate)==0)
    {
      theList->next = NULL;
      theList->returnDate = 0;
      return theList;
      
    }
  while(theList ->next !=NULL)
  {
    if(strcmp(theList->plate, plate)==0)
    {
      theList->next = NULL;
      theList->returnDate = 0;
      return theList;
      
    }
    theList = theList->next;
  }
  return NULL;

}

Car * getLastItem(Car * theList)
{
  if( theList == NULL)
  {
    return NULL;
  }
  while(theList->next != NULL)
  {
    theList = theList->next;
  }
  return theList;//actually the last item

}

Car * getFirstItem(Car * theList)
{
  if(theList == NULL)
  {
    return NULL;//the list is empty
  }
  if(theList->plate != NULL)
  {
    return theList; //the head is the first item
  }
  return NULL;
  
}

int isEmpty(Car * theList)
{
  if(theList != NULL && theList->plate != NULL )
  {
    return 0;
  }
  
  return 1; //list is empty
}


void printList(Car * theList)
{
  
  while(theList != NULL && theList->plate != NULL  )//loops through the list
  {
    
      char * str;
      str = printRecord(theList);
      printf("%s\n",str);//prints the items of the list
      theList = theList->next;
      free(str);
    
  }
  
  return; 
}
void printToFile(Car * theList, FILE * f)
{
  
  while(theList != NULL && theList->plate != NULL  )//loops through the list
  {
    
      char * str;
      fprintf(f, "%s,%d,%d\n",theList->plate,theList->mileage, theList->returnDate);
      //str = printRecord(theList);
      //fprintf(f,"%s\n",str);//prints the items of the list
      theList = theList->next;
      free(str);
    
  }
  fprintf(f,"-\n");
  
  return; 
}


void destroyList(Car * theList)
{
  while(theList != NULL)
  {
    Car * tempPtr;
    tempPtr = theList;
    theList = theList->next;
    
    destroyRecord(tempPtr);
    
  }

}





