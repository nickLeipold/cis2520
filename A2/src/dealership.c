#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "linkedList.h"
#include "openFile.h"
#include "dealerShip.h"

int main(int argc, char * argv[])
{
  
  FILE * fileStream;
  fileStream = openStream("assets/list.csv");
  carTransactions(fileStream);
  closeStream(fileStream);
  

  return 0;  
}

void carTransactions (FILE * file)
{
  Car * availableList = NULL; //ordered by milage, lowest at the front
  Car * repairList= NULL; //no order specified
  Car * rentedList= NULL; //ordered by expected return date, earliest return first
  Car * holder= NULL;
  int choice = 0;
  int exitCheck = 0;
  char temp[20];
  int mileage=0;
  int date= 0;
  float profit = 0;
  
  loadLists(availableList,repairList,rentedList,file);
  
  
  do
  {
    menu();
    choice = menuChoice();//checks what the user chose as an option
    
    switch(choice)
    {
      case 1://add a new car
        
        printf("Enter plate: ");
        fscanf(stdin,"%s", temp);
        getchar();
        printf("mileage: ");
        fscanf(stdin,"%d", &mileage);
        getchar();
        
        
        holder = createRecord(temp,mileage,0);
        availableList = addLowestIntFirst(availableList, holder);
        printf("added new car\n");
        break;
        
      case 2://returning working car
        printf("Enter plate: ");
        fscanf(stdin,"%s", temp);
        getchar();
        printf("mileage: ");
        fscanf(stdin,"%d", &mileage);
        getchar();
        holder = getSpecified(rentedList,temp);//gets the specified plate
        if (holder == NULL)
        {
          printf("invalid plate \n");
          break;
        }
        printf("%d\n", isEmpty(holder));
        rentedList = removeSpecified(rentedList,temp);//removes from the list
        availableList = addLowestIntFirst(availableList,holder);//adds to the new list
        printf("%d\n",holder->mileage);
        
        printCost(holder->mileage,mileage,&profit);
        holder->mileage += mileage;
        
        break;
        
      case 3:
        printf("Enter plate: ");
        fscanf(stdin,"%s", temp);
        getchar();
        printf("mileage: ");
        fscanf(stdin,"%d", &mileage);
        getchar();
        holder = getSpecified(rentedList,temp);//gets the specified plate
        printf("%d\n", isEmpty(holder));
        rentedList = removeSpecified(rentedList,temp);//removes from the list
        repairList = addLowestIntFirst(repairList,holder);//adds to the new list
        printf("%d\n",holder->mileage);
        
        printCost(holder->mileage,mileage,&profit);
        holder->mileage += mileage;
        
        break;
        
      case 4:
        printf("Enter plate: ");
        fscanf(stdin,"%s", temp);
        getchar();
        holder = getSpecified(repairList,temp);//gets the specified plate
        repairList = removeSpecified(repairList,temp);//removes from the list
        availableList = addLowestIntFirst(availableList,holder);//adds to the new list
        
        break;
        
      case 5://rent car
        holder =NULL;
        printf("Date to be returned: ");
        fscanf(stdin,"%d", &date);
        getchar();
        holder = availableList;
        availableList=removeFromFront(availableList);
        holder->next =NULL;
        holder->returnDate = date;
        rentedList = addLowestIntFirst(rentedList,holder);
        printf("rented car with plate of: %s, and mileage of %d\n",holder->plate,holder->mileage);
        
        
        break;
        
      case 6:
        printf("cars available\n");
        printList(availableList);
        printf("cars rented\n");
        printList(rentedList);
        printf("cars in for repair\n");
        printList(repairList);
        break;
        
      case 7:
        printf("a total profit of $%f was made\n exiting program\n", profit);
        //fprintf(file,"a\n");//available
        printToFile(availableList,file);
        //fprintf(file,"o");//out for rent
        printToFile(rentedList,file);
        //fprintf(file,"r");//repair
        printToFile(repairList,file);
        
        exitCheck =1;
        
        break;
        
      default:
        /*printf("fatal error, exiting program");
        exit(1);*/
          break;
    
       
    }
    
    holder =NULL;
  }
  while(exitCheck != 1);

  destroyList(availableList);
  destroyList(rentedList);
  destroyList(repairList);

}


void printCost(int oldMileage,int newMileage, float *profit)
{
  float temp = 0;
  temp = newMileage-oldMileage;
  if(temp <= 100)
  {
    *profit += 40.00;
    printf("charge is $40\n");
  }
  else
  {
    temp -= 100.00;
    temp = temp * 15.00;
    *profit = *profit + temp/100.00 + 40.00;
    printf("charge is $%.2f\n",temp/100.00 + 40.00);
  }
  


}

void loadLists(Car * availableList,Car * repairList,Car * rentedList,FILE * file)//almost working*********************************
{
  char line[256];
  Car * holder;
  int j=0;
  
  while(fgets(line,256, file) != NULL)
  {
    int movingStart;
    char temp[50][3];
    movingStart = 0;
    memset(temp, '\0',50*3);

    for(int i=0 ; i<= strlen(line); i++)
    {
      if(line[i] == ',' || line[i] =='\n')
      {
        //clear the temp file
        
        strncpy(temp[j], line+movingStart, i-movingStart);
        j++;
        i++;
        movingStart = i;//holds the location of where they are in the line
      }
    }
    holder = createRecord(temp[0],atoi(temp[1]),atoi(temp[2]));
    availableList = addLowestIntFirst(availableList, holder);

  }
}



void menu()
{
  printf("1. add a new car to the available-for-rent list\n");
  printf("2. add a returned car to the available-for-rent list\n");
  printf("3. add a returned car to the repair list\n");
  printf("4. transfer a car from the repair list to available-for-rent list\n");
  printf("5. rent the first available car\n");
  printf("6. print all the lists\n");
  printf("7. quit\n");


}

int menuChoice()
{
  char lineIn[20] = "";
  scanf("%s", lineIn);
  //getchar();
  
  if(strcmp(lineIn,"1") ==0)
  {
    return 1;
  }
  else if(strcmp(lineIn,"2")==0)
  {
    return 2;
  }
  else if(strcmp(lineIn,"3")==0)
  {
    return 3;
  }
  else if(strcmp(lineIn,"4")==0)
  {
    return 4;
  }
  else if(strcmp(lineIn,"5")==0)
  {
    return 5;
  }
  else if(strcmp(lineIn,"6")==0)
  {
    return 6;
  }
  else if(strcmp(lineIn,"7")==0)
  {
    return 7;
  }
  else
  {
    printf("invalid input\n");
  }
  


}


