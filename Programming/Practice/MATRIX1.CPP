#include <stdio.h>
#include <conio.h>
void main()
{
 float data[10],max,averange=0;
 clrscr();
 puts("Enter 10 real numbers : ");
 for (int i=0; i<10; i++ )
  {
   printf("Enter the %d number ",i+1);
   scanf("%f",&data[i]);
  }
 max=data[0];
 for (i=0; i<10; i++)
  {
   averange+=data[i];
   if (data[i]>max) max=data[i];
  }
 averange/=10;
 printf("\nThe averange is %0.3f\n",averange);
 printf("The maximal deviation is %0.3f",max-averange);
 getch();
}