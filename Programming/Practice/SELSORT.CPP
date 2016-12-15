#include <stdio.h>
#include <conio.h>
void main ()
 {
  int data[20];
  int n,min,flag,index;
  clrscr();
  printf("Enter the number of elements : ");
  scanf("%d",&n);
  for (int i=0; i<n; i++)
   {
    printf("Enter the %d element : ",i+1);
    scanf("%d",&data[i]);
   }
  for (i=0; i<n-2; i++)
   {
    min=data[i];
    flag=0;
    for (int j=i+1; j<n; j++)
     if (data[j]<min)
      {
       flag=1;
       min=data[j];
       index=j;
      }
    if (flag)
     {
      data[index]=data[i];
      data[i]=min;
     }
   }
  for (i=0; i<n; i++)
   printf("%d\n",data[i]);
  getch();
 }