#ifndef __NLEIPOLD_Q2_H__
#define __NLEIPOLD_Q2_H__
/* nickolas leipold
 * 0930626
 * assignment 3 2520
 * Due nov.7 
**/

void storeFile(FILE * filestream);

/*
 * takes in a tree in an array, then using downheap converts it into a heap
 */
void downHeap(int array[21][11]);

/*
 * takes in two arrays of ints, then swaps the values of each
 */
void swap(int array[11], int array2[11]);

/*
 *prints 2d array of ints, as specified in the assignment
 */
void printArr(int a[21][11]);

#endif
