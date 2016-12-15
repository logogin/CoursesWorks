#include <stdio.h>
#include <conio.h>
void main()
 {
  clrscr();
  int a,sum=0,digit;
  puts("The Armstrong`s numbers are :");
  for (int i=1; i<=500; i++)
   {
    a=i;
    while (a)
     {
      digit=a%10;
      sum=sum+digit*digit*digit;
      a=a/10;
     }
    if (sum==i)
      printf("%d\n",i);
    sum=0;
   }
  getch();

 }