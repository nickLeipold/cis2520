#ifndef __NLEIPOLD_Q1_H__
#define __NLEIPOLD_Q1_H__
/* nickolas leipold
 * 0930626
 * assignment 4 2520
 * Due nov.28
**/
struct Node
{
  char value[20];
  int freq;
  struct Node *left;
  struct Node *right;
};
typedef struct Node Node;

/*prints a greeting at the start of the program
*/
void greeting();

/*
takes in a fileStream pointer, reads the file peice by peice, then returns
a node pointer, takes in size of the intiail tree
*/
Node * parseFile(FILE * fileStream, int * size);

/*
  takes in a new node that is to be added, the root that is being searched, and the number of items
 */
Node * addAVL(Node * node,Node * root,int * count);
  
/**
  *will call the menu() function, and call the proper functions based on user input
  */
void menuOptions(Node * root);

/*
 *prints out the menu
 **/
void menu();



//updates specified variable to a value
void find(Node * root);

//replaces the field specified
void search(Node * root,char val[10]);

//updates specified variable to a value
void findFreq(Node * root);

//replaces the field specified
void searchFreq(Node * root,int val);

//calls the nodeheight function and culculates the balance factor
int balanceFactor(Node * node);

//calculates the height of the specified node
int nodeHeight(Node * node);

//calls for the node to be deleted,count of nodes
void deleteNode(Node * root,int * size);

//finds and deletes the node specified
Node * searchDestroy(Node * root, char * str);

//frees the malloced tree
void killTree(Node * root);






#endif
