
// Problem 3.
// Use the Monte Carlo method to find the square root of 3 to three decimal places.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void main ()
{
 clrscr();
 float error,root,x_star;
 randomize();
 puts("Finding square root of 3 ...");
 do
  {
   x_star=(float)random(1000)/1000;
   root=1+2*x_star;
   error=fabs(root*root-3)/root;
  }
 while (error>=0.001);
 printf("The root is about %1.3f",root);
 getch();
}