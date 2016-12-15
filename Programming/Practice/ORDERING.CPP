#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
void main ()
{
 int a=0,b=0,c=0;
 clrscr();
 randomize();
 a=random(20)+50;
 b=random(20)+50;
 c=random(20)+50;
 printf("The numbers are %d %d %d ",a,b,c);
 if (a>=b)
   {
   a+=b;
   b=a-b;
   a-=b;
   }
 if (a>=c)
   {
   a+=c;
   c=a-c;
   a-=c;
   }
 if (b>=c)
   {
   b+=c;
   c=b-c;
   b-=c;
   }
 printf("\nAfter.... %d %d %d ",a,b,c);
 getch();

}
