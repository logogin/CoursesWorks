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