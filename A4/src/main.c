/* nickolas leipold
 * 0930626
 * assignment 4 2520
 * Due nov.28
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "openFile.c"

int main ( int argc, char * argv[])
{
  greeting();
  Node * root;
  root = (Node *) malloc(sizeof(Node));
  strcpy(root->value, "NULL");
  
  printf("\n");
  menuOptions(root);
  
}

void greeting()
{
  printf("Welcome to AVL tree maker\nBy:Nickolas Leipold\n0930626\n");
}

Node * parseFile(FILE * fileStream, int * size)
{
  Node * root;
  root = NULL;
  
  char string[800];
  int i =0;
  while(fgets(string,800, fileStream) != NULL)
  {
    char  * token;
    token = strtok(string,"[( )\n\t]+");
    while(token!=NULL)
    {
    	
      Node * node;
      node = (Node *) malloc(sizeof(Node));
      node->left = NULL;
      node->right = NULL;
      strcpy(node->value,token);
      //printf("%s ",token);
      root = addAVL(node,root,size);
      token = strtok(NULL,"[( )\n\t]+");
      
      i++;
    }
     
  }
  
    
  return root;
}



Node * addAVL(Node * node,Node * root,int * count)
{
  
  if(root == NULL)
  {
    
    node->freq = 1;
    (*count)++;
    return node;
    balanceFactor(node); 
    
  }
  
  if(strcmp(root->value,node->value) < 0)
  {
    //printf("string is less than node value, need to go to the left branch\n");
    root->right = addAVL(node,root->right,count);
    
  }
  if(strcmp(root->value,node->value) > 0)
  {
    //printf("string is bigger than node value, need to go to right branch\n");
    root->left = addAVL(node,root->left,count);
    
  }
  if(strcmp(root->value,node->value) ==0)
  {
    //printf("same values, duplicates\n");
    //if(node != NULL)
      //free(node);
    root->freq ++;
    
  }
  
  if( balanceFactor(root) >= 2 )//rotating right
  {
  	if(root->left != NULL && balanceFactor(root->left) <= -1)//rotating left right
  	{
  		//printf("left right balance\n");
  		Node * temp;
  		Node * tempChild;
  		temp = root->left;
  		tempChild = root->left->right->left;
  		root->left = root->left->right;
  		temp->right = tempChild;
  		root->left->left = temp;
  		
  	}
  	if(root->left != NULL && balanceFactor(root->left) >= 1)//rotating right
  	{
  		//printf("right balance\n");
  		Node * temp;
  		Node * tempChild;
  		temp = root;
  		tempChild = root->left->right;
  		root = root->left;
  		root->right = temp;
  		temp->left = tempChild;
  		return root;
  	}
  	
  	
  }
  if( balanceFactor(root) <= -2 )
  {
  	if(root->right != NULL && balanceFactor(root->right) >= 1)//rotating right left
  	{
  		//printf("right left balance\n");
  		Node * temp;
  		Node * tempChild;
  		temp = root->right;
  		tempChild = root->right->left->right;
  		root->right = root->right->left;
  		temp->left = tempChild;
  		root->right->right = temp;
  		
  	}
  	
  	if(root->right != NULL && balanceFactor(root->right) <= -1)//rotating left
  	{
  		//printf("left balance\n");
  		Node * temp;
  		Node * tempChild;
  		temp = root;
  		tempChild = root->right->left;
  		root = root->right;
  		root->left = temp;
  		temp->right = tempChild;
  		return root;
  	}
  	
  	
  }
  
  return root;

}

void menuOptions(Node * root)
{
  int exit = 0;
  int size=0;
  
  do
  {
    char lineIn[20] = "";
    menu();
    scanf("%s", lineIn);
    
    
    if(strcmp(lineIn,"1") ==0) //calls the appropriate function based on what the user typed in
    {
      if(root->value == NULL)
      {
        killTree(root);
      }
      
      char file[120];
      FILE * fp;
      getFile(file);
      fp = openStream(file);
      root = parseFile(fp,&size);
      //printf("root value %s\n",root->value);
      
    }
    else if(strcmp(lineIn,"2")==0)  //find node
    {
      find(root);
    }
    else if(strcmp(lineIn,"3")==0)  //insert new node
    {
      int i;
      printf("enter node to be added: ");
      Node * node;
      node = (Node *) malloc(sizeof(Node));
      node->left = NULL;
      node->right = NULL;
      fscanf(stdin,"%s", node->value);
      addAVL(node,root,&i);
      search(root,node->value);
      size++;
    }
    else if(strcmp(lineIn,"4")==0)//deletion
    {
      deleteNode(root,&size);
      //printTree(root,0);
    }
    else if(strcmp(lineIn,"5")==0)//print the height of the tree
    {
      	printf("height: %d, size: %d",nodeHeight(root),size);
      
    }
    else if(strcmp(lineIn,"6")==0)  //find all nodes above a frequency
    {
      findFreq(root);
    }
    else if(strcmp(lineIn,"7")==0)  //exit
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
  printf("\n1. Initialize\n");
  printf("2. Find\n");
  printf("3. Insert\n");
  printf("4. Remove\n");
  printf("5. Check Height and Size\n");
  printf("6. Find All (above a given frequency)\n");
  printf("7. Exit\n");
  printf("avl/> ");
}


void deleteNode(Node * node,int * size)
{
  printf("remove key: ");
  char temp[20];
  fscanf(stdin,"%s", temp);
  Node * holder;
  holder = (Node*)malloc(sizeof(Node));
  holder = node;
  node = searchDestroy(holder,temp);
  if(strcmp(temp,"no")==0)
  {
    printf("no_such_key\n");
  }
  if(strcmp(temp,"dead")==0)
  {
    //printf( "dead");
    (*size)--;
  }
  
  

}

Node * searchDestroy(Node * root,char * str)//***************************************************************************************************************8
{
  if(root == NULL)
  {
    strcpy(str,"no");
    return NULL;
  }
  if(strcmp(root->value,str) < 0)
  {
    
    root->right = searchDestroy(root->right,str);
    
  }
  else if(strcmp(root->value,str) > 0)
  {
    
    root->left = searchDestroy(root->left,str);
    
  }
  else if(strcmp(root->value,str)== 0)
  {
    if(root->freq == 1 && root->left !=NULL)
    {
      
      Node * nodeLeft;
      Node * remove;
      Node * leftCut;
      leftCut = root->right->left;
      remove = root;
      nodeLeft = root->left;
      root->left = NULL;
      root->right->left = nodeLeft;
      while(nodeLeft->right !=NULL )
      {
        nodeLeft=nodeLeft->right;
        
      }
      nodeLeft->right = leftCut;
      printf("key: %s, frequency: %d\n",remove->value,remove->freq);
      remove->freq = 0;
      strcpy(str,"dead");
      free(remove);
      return  nodeLeft->right;
    }
    else if(root->freq == 1 && root->left == NULL)//removes leaf node
    {
      free(root);
      return NULL;
    }
    else
    {
      
      
      root->freq --;  //reduce frequency
      return root;
    }
    
  }
  
  
  
  //balance code, ran into an error making it a function so i went with what works
  if( balanceFactor(root) >= 2 )//rotating right
  {
  	if(root->left != NULL && balanceFactor(root->left) <= -1)//rotating left right
  	{
  		//printf("left right balance\n");
  		Node * temp;
  		Node * tempChild;
  		temp = root->left;
  		tempChild = root->left->right->left;
  		root->left = root->left->right;
  		temp->right = tempChild;
  		root->left->left = temp;
  		
  	}
  	if(root->left != NULL && balanceFactor(root->left) >= 1)//rotating right
  	{
  		//printf("right balance\n");
  		Node * temp;
  		Node * tempChild;
  		temp = root;
  		tempChild = root->left->right;
  		root = root->left;
  		root->right = temp;
  		temp->left = tempChild;
  		return root;
  	}
  	
  	
  }
  if( balanceFactor(root) <= -2 )
  {
  	if(root->right != NULL && balanceFactor(root->right) >= 1)//rotating right left
  	{
  		//printf("right left balance\n");
  		Node * temp;
  		Node * tempChild;
  		temp = root->right;
  		tempChild = root->right->left->right;
  		root->right = root->right->left;
  		temp->left = tempChild;
  		root->right->right = temp;
  		
  	}
  	
  	if(root->right != NULL && balanceFactor(root->right) <= -1)//rotating left
  	{
  		//printf("left balance\n");
  		Node * temp;
  		Node * tempChild;
  		temp = root;
  		tempChild = root->right->left;
  		root = root->right;
  		root->left = temp;
  		temp->right = tempChild;
  		return root;
  	}
  	
  	
  }
  
  return root;
  
  
  
  
}


void find(Node * root)
{
  char val[10] ="";
  printf("please enter the node you wish to find\n");
  scanf("%s",val);
  search(root,val);
  if(strcmp(val,"no") == 0)
  {
    printf("no_such_key\n");
  }

}

void search(Node * root,char val[10])
{
  
  if(root == NULL)
  {
    strcpy(val,"no");
    return;
  }
  if(strcmp(root->value,val) == 0)
  {
    printf("key: %s, frequency: %d\n",val,root->freq);
    //printf("balanceFactor: %d\n",balanceFactor(root));
    
  }
  if(strcmp(root->value,val)<0)
  {
    search(root->right,val);
  }
  if(strcmp(root->value,val)>0)
  {
    
    search(root->left,val);
  }

}

void findFreq(Node * root)
{
  int val;
  char temp[8];
  printf("please enter the frequency you wish to find\n");
  scanf("%s",temp);
  val=atoi(temp);
  searchFreq(root,val);

}

void searchFreq(Node * root,int val)
{
  
  if(root == NULL)
    return;
  if(root->freq >= val)//traverses the tree and finds
  {
    printf("key: %s, frequency: %d\n",root->value,root->freq);
    //printf("balanceFactor: %d",balanceFactor(root));
    
  }
  
  searchFreq(root->left,val);
  searchFreq(root->right,val);

}

int balanceFactor(Node * node)
{
	return nodeHeight(node->left) - nodeHeight(node->right);

}

int nodeHeight(Node * node)//recursively goes through the tree to find the height
{
  int big=0;
  

	if(node == NULL)
	{
		return 0;
	}
	if(node->freq == 0)
  {
    big--;
  }
	if(node->left == NULL && node->right ==NULL)
	{
		return 1;
	}
	
	if(node->right != NULL)
	{
		big += nodeHeight(node->right)+1;
	}
	if(node->left != NULL)
	{
		if((nodeHeight(node->left) +1)>big)
		big = nodeHeight(node->left)+1;
	}
	return big;
	
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







 
