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

// Problem 4.
// Write a computer program simulating the toss of a fair die with
// outcomes 1,2,3,4,5,6.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main ()
{
 clrscr();
 randomize();
 printf("Simulating the toss of fair... %d",random(6)+1);
 getch();
}
