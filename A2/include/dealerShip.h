#ifndef __DEALERSHIP_H__
#define __DEALERSHIP_H__
void carTransactions(FILE * file);
void menu();
int menuChoice();
void loadLists(Car * availableList,Car * repairList,Car * rentedList,FILE * file);
void printCost(int oldMileage,int newMileage, float *profit);
#endif
