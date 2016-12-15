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