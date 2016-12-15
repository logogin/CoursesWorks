#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void main ()
 {
  float sum=0;
  int n,n1;
  float *p;
  clrscr();
  printf("Enter the level : ");
  scanf("%d",&n);
  printf("Enter number of elements : ");
  scanf("%d",&n1);
  p=(float *)malloc(sizeof(float)*n);
  for (int i=0; i<n1; i++)
   {
    printf("Enter the %d element : ",i+1);
    scanf("%f",(p+i));
   }
  puts("\n");
  puts("New row is : ");
  for (i=0; i<n1; i++)
   {
    if (sum+*(p+i)>15)
     {
      sum=0;
      printf("0   ");
     }
    sum+=*(p+i);
    printf("%.2f   ",*(p+i));
   }
  getch();
 }