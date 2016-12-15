#include <stdio.h>
#include <conio.h>
void main()
{
 float x,sum,row=1,element;
 int n=0;
 clrscr();
 printf("Enter x and sum : ");
 scanf("%f%f",&x,&sum);
 element=1;
 while (row<sum)
  {
   element=-element*(x/++n);
   row+=element;
  }

 printf("The number of elements is %d ",n+1);
 getch();
}