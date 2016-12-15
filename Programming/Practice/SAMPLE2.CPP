#include <stdio.h>
#include <conio.h>
void main ()
{
 clrscr();
 int flag=0,j,k,counter=0;
 puts("The numbers are :" );
 for (int i=1; i<=200; i++)
  {
   flag=1;
   j=1;
   k=1;
   while (k&&j<(i-1))
    {
     k=i%++j;
     if(k)
     flag=1;
     else
     flag=0;
    }

    if(flag)
      {
       printf("%d\t",i);
       counter++;
      }
  }
  printf("At all are : %d numbers",counter);
  getch();
}