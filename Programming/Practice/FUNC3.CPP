#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

 int data1[100],data2[100],data3[200];
 int l1,l2;

void sorting(void)
 {
  int p;
  for (int i=0; i<l1; i++)
   data3[i]=data1[i];
  for (i=0; i<l2; i++)
   data3[i+l1]=data2[i];
  for (i=0; i<(l1+l2-1); i++)
   for (int j=i+1; j<l1+l2; j++)
    if (data3[j]>data3[i])
     {
      p=data3[i];
      data3[i]=data3[j];
      data3[j]=p;
     }
 }

void main ()
 {

   clrscr();
   randomize();
   printf("Enter the first lenght : ");
   scanf("%d",&l1);
   printf("Enter the second lenght : ");
   scanf("%d",&l2);
   puts("Data in first array :");
   for (int i=0; i<l1; i++)
    {
     data1[i]=random(1000);
     printf("%d ",data1[i]);
    }
   getch();
   puts("");
   puts("");
   puts("Data in second array :");
   for (i=0; i<l2; i++)
    {
     data2[i]=random(1000);
     printf("%d ",data2[i]);
    }
   getch();
   sorting();
   puts("");
   puts("");
   puts("Data in both arraies :");
   for (i=0; i<l1+l2; i++)
    printf("%d ",data3[i]);
   getch();
 }
