#include <stdio.h>
#include <conio.h>
void main ()
{
 clrscr();
 float a,b,c;
 printf("Enter three real numbers : ");
 scanf("%f%f%f",&a,&b,&c);
 if (a<=b)
   {
   a+=b; b=a-b; a-=b;
   }
 if (a<=c)
   {
   a+=c; c=a-c; a-=c;
   }
 if (b<=c)
   {
   b+=c; c=b-c; b-=c;
   }
  printf("After sorting ... %3.2f  %3.2f  %3.2f ",a,b,c);
  getch();
}