#include <stdio.h>
#include <conio.h>
int data1[10][10],data2[10][10];
void main()
{
 int n;
 clrscr();
 printf("Enter the size of matrix : ");
 scanf("%d",&n);
 for (int i=0; i<n; i++ )
  for (int j=0; j<n; j++)
  {
   printf("Enter the %d number of %d line ",j+1,i+1);
   scanf("%d",&data1[i][j]);
  }

 printf("\n\n");

 for (i=0; i<n; i++)
  for (int j=0; j<n; j++)
   data2[j][i]=data1[i][j];


 for(i=0; i<n; i++)
  {
   for (int j=0; j<n;j++)
     printf("%4d",data1[i][j]);
   printf("\n");
  }
 printf("\n\n");
  for(i=0; i<n; i++)
  {
   for (int j=0; j<n;j++)
     printf("%4d",data2[i][j]);
   printf("\n");
  }

 getch();
}