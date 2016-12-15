#include <stdio.h>
#include <conio.h>
int data[10];
void main()
{
 clrscr();
 for (int i=0; i<10; i++)
  {
   printf("Enter the %d number : ",i+1);
   scanf("%d",&data[i]);
  }
 for (i=0; i<9; i++)
  for (int j=i+1; j<10; j++)
   if (data[i]>data[j])
    {
     data[i]+=data[j];
     data[j]=data[i]-data[j];
     data[i]-=data[j];
    }

}
