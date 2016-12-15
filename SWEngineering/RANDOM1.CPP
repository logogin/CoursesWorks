
// Homework for Laboratory (December 10,2000)
//
// Problem 1.
// Generate uniformly random integers among the values 1,2,3,4.
// Print out 20 numbers.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void main ()
{
 clrscr();

 randomize();
 puts("Printing 20 random numbers");
 for(int i=0;i<20;i++)
   printf("\n%d",random(4)+1);
 getch();
}