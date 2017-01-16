/* nickolas leipold
 * 0930626
 * assignment 3 2520
 * Due nov.7
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q1.h"

int main ( int argc, char * argv[])
{
  Node * root;
  printf("\n");
  root = parseEqn(argv[1]);
  menuOptions(root);
  
}

Node * parseEqn(char * str)
{
  Node *node;
  node = (Node *) malloc(sizeof(Node));
  int brackets= 0;
  int holder = 0;
  int root = 0;
  for(int i = 0; i < strlen(str); i++)
  {
    if(str[i]== '(') //counts up for ever bracket
    {
      brackets +=1;
      
    }
    if(brackets == 1 && root == 0 && (str[i] == '+' ||str[i] == '-' ||str[i] == '*' ||str[i] == '/'))//finds the root node, and makes sure its an operator
    {
      
      sprintf(node->value,"%c", str[i]);
      root = 1;
      holder = i;
      
    }
    
    if(str[i] == ')') //reduces one for every bracket
    {
      brackets -=1;
    }
    
  }
  
  char item[100] ="";
  for(int i = 1; i<holder; i++) //generates the string before the root
  {
    char temp[10] ="";
    sprintf(temp,"%c",str[i]); // make the char into a string
    
    strcat(item,temp);
    
  }
  char item2[100] = "";
  for(int i = holder+1; i<strlen(str)-1; i++)//generates the string after the root
  {
    char temp[10] ="";
    sprintf(temp,"%c",str[i]); // make the char into a string
    
    strcat(item2,temp);
    
  }
  
  
  if(root == 1 ) //if root was found, recursivly call its children
  {
    node->left = parseEqn(item);
    node->right = parseEqn(item2);
    
  }
  else if(root == 0 && strcmp(str,item) != 0 && strcmp(str,item2) != 0 ) //leaf node value
  {
    sprintf(node->value ,"%s",str);
    node->left = NULL;
    node->right = NULL;
  }
  else
  {
    node->left = NULL;
    node->right = NULL;
  
  }
  
  return node;
  
}


void menuOptions(Node * root)
{
  int exit = 0;
  
  do
  {
    char lineIn[20] = "";
    menu();
    scanf("%s", lineIn);
    
    
    if(strcmp(lineIn,"1") ==0) //calls the appropriate function based on what the user typed in
    {
      printTree(root,0);
    }
    else if(strcmp(lineIn,"2")==0)
    {
      printPre(root);
    }
    else if(strcmp(lineIn,"3")==0)
    {
      printIn(root);
    }
    else if(strcmp(lineIn,"4")==0)
    {
      printPost(root);
    }
    else if(strcmp(lineIn,"5")==0)
    {
      update(root);
    }
    else if(strcmp(lineIn,"6")==0)
    {
      printf("%.2f\n",calc(root));
    }
    else if(strcmp(lineIn,"7")==0)
    {
      killTree(root);
      printf("Exiting\n");
      exit = 1;
    }
    else
    {
      printf("invalid input\n");
    }
    
  }while(exit ==0);

}

void menu()
{
  printf("\n1. Display\n");
  printf("2. Preorder\n");
  printf("3. Inorder\n");
  printf("4. Postorder\n");
  printf("5. Update\n");
  printf("6. Calculate\n");
  printf("7. Exit\n");
}

void printTree(Node * root,int space) //visually prints the tree sideways
{
  if(root ==NULL )
  {
    return;
  }
  printTree(root->right,space+3);
  for(int i =0;i<space;i++)
  {
    printf(" ");
  }
  if(!(strcmp(root->value,"")==0) && root->left != NULL && root->right !=NULL)
  {
    printf("%s~~|",root->value);
  }
  else
  {
    printf("%s",root->value);
  }
  
  printf("\n");
  printTree(root->left,space+3);
  
  
  
  
  
}

void printPre(Node * root)//prints the equation in preorder
{
  if(root ==NULL )
  {
    return;
  }
  if(!(strcmp(root->value,"")==0))
    printf("%s ",root->value);

  printPre(root->left);
  printPre(root->right);
  
}

void printIn(Node * root)//prints the equation in order
{
  if(root ==NULL )
  {
    return;
  }
  if(root->left != NULL && root->right !=NULL)
    printf("(");
  printIn(root->left);
  if(!(strcmp(root->value,"")==0))
    printf("%s ",root->value);
  printIn(root->right);
  if(root->left != NULL && root->right !=NULL)//if it is a leaf node dont print the bracket
    printf(")");
  
}

void printPost(Node * root)//prints the equation in postorder
{
  if(root ==NULL )
  {
    return;
  }
  printPost(root->left);
  printPost(root->right);
  
  if(!(strcmp(root->value,"")==0))
    printf("%s ",root->value);

}

void update(Node * root)
{
  char val[10] ="";
  char var[10] ="";
  printf("\nplease enter the variable name you wish to set a value to\n");
  scanf("%s", var);
  printf("please enter the new value you wish to set the variable to\n");
  scanf("%s",val);
  replace(root,var,val);

}

void replace(Node * root,char var[10],char val[10])
{
  if(root == NULL)
    return;
  if(strcmp(root->value,var) == 0)//traverses the tree and finds
  {
    strcpy(root->value,val);
  }
  replace(root->left,var,val);
  replace(root->right,var,val);

}

float calc(Node * root)
{
  if(root ==NULL )
  {
    return -1;
  }
  if(root->left == NULL && root->right ==NULL) //find the values (if a value is not a number, zero is returned)
    return atof(root->value);
  if(strcmp(root->value,"+") == 0) //switches the string operand to the mathematical operator and performs the recursive step
  {
    return( calc(root->left) + calc(root->right));
  }
  if(strcmp(root->value,"-") == 0)
  {
    return( calc(root->left) - calc(root->right));
  }
  if(strcmp(root->value,"/") == 0)
  {
    return( calc(root->left) / calc(root->right));
  }
  if(strcmp(root->value,"*") == 0)
  {
    return( calc(root->left) * calc(root->right));
  }
  
  return -1;
}


void killTree(Node * root)
{
  if(root ==NULL )
  {
    return;
  }
  
  killTree(root->left);
  killTree(root->right);
  if(root->left == NULL && root->right == NULL)//loops through to the bottom nodes then frees on the way back up
  {
    free(root);
  }
  
  

}







 
