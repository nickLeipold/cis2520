#ifndef __NLEIPOLD_Q1_H__
#define __NLEIPOLD_Q1_H__
/* nickolas leipold
 * 0930626
 * assignment 3 2520
 * Due nov.7
**/
struct Node
{
  char value[10];
  struct Node *left;
  struct Node *right;
};
typedef struct Node Node;

/*
returns an array of character arrays(strings)
while taking in a character array that needs to be parsed
seperates the equation into parts
*/
Node * parseEqn(char * str);

/**
  *will call the menu() function, and call the proper functions based on user input
  */
void menuOptions(Node * root);

/*
 *prints out the menu
 **/
void menu();

//prints the tree visualy, space is accounting for formatting
void printTree(Node * root,int space);

//prints the tree in preorder
void printPre(Node * root);

//prints the tree in inorder
void printIn(Node * root);

//prints the tree in postorder
void printPost(Node * root);

//updates specified variable to a value
void update(Node * root);

//replaces the field specified
void replace(Node * root,char var[10],char val[10]);

//calculates value of the equation
float calc(Node * root);

//frees the malloced tree
void killTree(Node * root);






#endif
