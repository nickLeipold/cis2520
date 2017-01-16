#include <stdio.h>
#include <stdlib.h>

//not used in this program, utuilizing for future programs
void getFile(char * filePath)
{
  printf("enter file location: /n");
  fscanf(stdin,"%s", filePath);
  return;
}


FILE * openStream(char * path)
{
  FILE * streamPtr;
  streamPtr = fopen(path,"w+");
  if(streamPtr != NULL)
  {
    return streamPtr;
  }
	printf("file %s does not exist, or can not becreated in the specified path\n", path);
  return NULL;

}



void closeStream(FILE * streamPtr)
{
  if( streamPtr != NULL)
  {
    fclose(streamPtr);
    //print out to std error -figure out how to impliment
    return;
  }
  perror("file stream does not exist");

}
