// LABORATORY 3, NOVEMBER 26,2000
// Problem 1.
// Extend the program to find the values of each of the functions
// given for the input value t=PI.

#include <stdio.h>
#include <conio.h>
#include <math.h>
void main ()
{
  float t=3.14159;
  clrscr();
  printf("Cosine is %20.2f",cos(t));
  printf("\nSine is %22.2f",sin(t));
  printf("\nTangent is %19.10f",tan(t));
  printf("\nLogarihm is %18.2f",log(t));
  printf("\nExpotential function is %7.2f",exp(t));
  printf("\nSquare root is %15.2f",sqrt(t));
  getch();
}

// Problem 2.
// Add statement like "Hello,I am your friendly computer" to the beginning
// of this program.

#include <stdio.h>
#include <conio.h>
#include <math.h>
void main ()
{
  float t=3.14159;
  clrscr();
  puts("Hello,I am your friendly computer\n");
  printf("Cosine is %20.2f",cos(t));
  printf("\nSine is %22.2f",sin(t));
  printf("\nTangent is %19.10f",tan(t));
  printf("\nLogarihm is %18.2f",log(t));
  printf("\nExpotential function is %7.2f",exp(t));
  printf("\nSquare root is %15.2f",sqrt(t));
  getch();
}

// Problem 3.
// Write a program for finding the function f(x)=x/sin(x) and using it,
// show that the limit of f(x) as x tends to 0 is one.

#include <stdio.h>
#include <conio.h>
#include <math.h>
void main ()
{
 double x=1,y;
 clrscr();
 puts("The Function is f(x)=x/sin(x)");
 for (int i=0;i<10;i++)
   {
    x/=100;
    y=x/sin(x);
    printf("\nIf x=%e then F(x)=%.17f",x,y);
   }
 getch();
}

// Problem 4.
// Write a program for finding f(x)=5.6/t for given t.

#include <stdio.h>
#include <conio.h>
#include <math.h>
void main ()
{
 float t;
 clrscr();
 puts("The Function is f(x)=5.6/t");
 printf("Enter t : ");
 scanf("%f",&t);
 printf("F(x)=%.5f",5.6/t);
 getch();
}