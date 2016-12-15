#include <stdio.h>
#include <conio.h>
#include <math.h>
void main ()
{
 clrscr();
 float a,b,c,desc;
 float x1,x2,x,real;
 printf("Enter coefitients of the eguation (a,b,c) " );
 scanf("%f %f %f",&a,&b,&c);
 desc=b*b-4*a*c;
	if (desc>=0)
	  {
	   desc=sqrt(desc);
	   x1=(-b+desc)/(2*a);
	   x2=(-b-desc)/(2*a);
	   printf("The roots are : %3.2f and %3.2f",x1,x2);
	  }
	  else
	  {
	   desc=sqrt(abs(desc));
	   real=(-b)/(2*a);
	   x=desc/(2*a);
	   printf("The equation has a complex roots : "
		 "(%3.2f+%3.2fi) and (%3.2f-%3.2fi)",real,x,real,x);
	  }

   getch();
}