#include <stdio.h>
#include <conio.h>
void main()
{
 int data[10][10],d1=0,d2=0;
 int n,position;
 clrscr();
 printf("Enter the size of matrix : ");
 scanf("%d",&n);
 for (int i=0; i<n; i++ )
  for (int j=0; j<n; j++)
  {
   printf("Enter the %d number of %d line ",j+1,i+1);
   scanf("%d",&data[i][j]);
  }
 for (i=0; i<n; i++)
  {
   d1+=data[i][i];
   d2+=data[i][(n-1)-i];
  }
 printf("\nThe sum of elements in diagonal 1x1-%dx%d is %d \n",n,n,d1);
 printf("The sum of elements in diagonal 1x%d-%dx1 is %d \n",n,n,d2);
 if (d1>d2)
  printf("The maximal sum is in diagonal 1x1-%dx%d ",n,n);
 else
  if (d2>d1)
   printf("\nThe maximal sum is in diagonal 1x%d-%dx1 ",n,n);
  else
   printf("\nThe sums in both diagonals are egual ");
 getch();
}