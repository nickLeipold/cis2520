/*Nickolas Leipold
nleipold@mail.uoguelph.ca
0930626
Assignment 1
cis*2520
*/
/*******Compilation*****************

go to root A1 folder in assignment
type "make" to compile the program

"./a.out 'arg1' 'arg2' 'arg3' 'arg4'" to run the program

arg1 = m
arg2 = n 
ackermann(m,n)

arg3 = x (number to be rooted)
arg4 = tollerance (the accuracy of the root)

all arguments must be integers to work

"make clean" removes a.out

*******Usage*************************

through the given command line inputs the program will scramble the word "carbon" to all possible options, 
convey the Ackermann function using your first two command line arguments,
will find the square root of the third command line argument to the accuracy of the 4th command line argument

**********Testing********************

after testing the ackermann function creates a segfault on cases where 4 or higher is used as the first variable

carbon.c output is 720 different combos
ex
  carbon
  carbno
  carobn
  caronb
  carnob
  carnbo
  cabron
  cabrno
  caborn
  cabonr
  cabnor
  cabnro
  caobrn
  caobnr
  caorbn
  caornb
  caonrb
  ...
  
ackermann.c output ex 2,4 is 11

newton.c output ex 891 0.0001 the newton method result(root) is 29.849623


*************Known Limitations**************

the same limitations specified in the assignment discription and ackermann 4 2 and up segfaults
5 1 and up segfaults but 5 0 works and all lower values specified in assignment



*************References*****************************

Lectures
man pages
labs
http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

****************************************************
All work handed in is completed by yours truely and if it is not it is referenced
*/
