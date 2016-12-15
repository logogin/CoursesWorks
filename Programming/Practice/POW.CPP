#include <stdio.h>
#include <conio.h>
void main()
{
 int y;
 float x,x_y=1;
 clrscr();
 printf("Enter two numbers x and y :");
 scanf("%f%d",&x,&y);
 for (int i=1; i<=y; i++)
  x_y*=x;
 printf("The result is  %.4f ",x_y);
 getch(); 

}