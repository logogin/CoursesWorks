#include <stdio.h>
#include <conio.h>
void main()
{
 int min=32767,max=-32768,n,i=1;
 clrscr();
 while (n!=0)
  {
   printf("Enter the %d number (0-exit) : ",i++);
   scanf("%d",&n);
   if (max<n)
    max=n;
   if (min>n)
    min=n;
  }
 printf("\nThe maxinum number is %d\n",max);
 printf("The minimum number is %d",min);
 getch();
}