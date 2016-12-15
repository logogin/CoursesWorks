
// Problem 2.
// Generate random integers among the values 1,2,3,4 with the "probabilities"
// 0.1,0.3,0.4,0.2 respectively. Print out 20 numbers.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void main ()
{
 float r;
 clrscr();
 randomize();
 puts("Printing 20 random numbers");
 for(int i=0;i<20;i++)
  {
   r=(float)random(101)/100;
   if (r<=0.1)
    puts("1");
   if (r>0.1&&r<=0.4)
    puts("2");
   if (r>0.4&&r<=0.8)
    puts("3");
   if (r>0.8&&r<=1)
    puts ("4");
  }
 getch();
}