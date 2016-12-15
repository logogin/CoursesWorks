#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

 float data[50];
 int n;

void sorting(void)
 {
  float p;
  for (int i=0; i<n/2-1; i++)
   for (int j=i+1; j<n/2; j++)
    if (data[j]>data[i])
     {
      p=data[i];
      data[i]=data[j];
      data[j]=p;
     }

  for (n%2==0 ? i=n/2 : i=n/2+1; i<n-1; i++)
   for (int j=i+1; j<n; j++)
    if (data[j]<data[i])
     {
      p=data[i];
      data[i]=data[j];
      data[j]=p;
     }
 }

void main ()
 {
   clrscr();
   printf("Enter the number of elements : ");
   scanf("%d",&n);
   puts("");
   for (int i=0; i<n; i++)
    {
     printf("Enter the %d element : ",i+1);
     scanf("%f",&data[i]);
    }
   sorting();
   puts("");
   for (i=0; i<n; i++)
    printf("%.3f ",data[i]);
   getch();
 }
