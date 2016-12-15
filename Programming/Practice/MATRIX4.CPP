#include <stdio.h>
#include <conio.h>
int data1[10][10],data2[100];
void main()
{
 int n,m,p,c=0;
 clrscr();
 printf("Enter the size of matrix : ");
 scanf("%d%d",&n,&m);
 for (int i=0; i<n; i++ )
  for (int j=0; j<m; j++)
  {
   printf("Enter the %d number of %d line ",j+1,i+1);
   scanf("%d",&data1[i][j]);
   data2[c++]=data1[i][j];
  }
 for (i=0; i<n*m-1; i++)
  for (int j=i+1; j<n*m; j++)
   if (data2[i]>data2[j])
    {
     p=data2[j];
     data2[j]=data2[i];
     data2[i]=p;
    }
 c=0;
 for(i=0; i<n; i++)
  {
   for (int j=0; j<m;j++)
    {
     data1[i][j]=data2[c++];
     printf("%4d",data1[i][j]);
    }
   printf("\n");
  }


 getch();
}