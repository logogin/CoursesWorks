#include <stdio.h>
#include <conio.h>
long factorial(int n)
 {
  long f;
  f=factorial(n-1)*n;
  if (n==1)
   f=1;
  n--;
  return f;
 }
void main()
 {
  unsigned int f=0;
//  long factorial=1;
  clrscr();
//  do
   {
   printf("Enter the number from 1 to 8 : ");
   scanf("%d",&f);
   }
//  while (f<1||f>8);
//  for (long i=1; i<=f; i++)
//   factorial*=i;
  printf("The factorial of %d is %ld ",f,factorial(f));
  getch();
 }