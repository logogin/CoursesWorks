#include <stdio.h>
#include <conio.h>
void main()
{
 float data[20],max,averange=0,element;
 int n,position;
 clrscr();
 printf("Enter the number of elements : ");
 scanf("%d",&n);
 printf("\nEnter %d real numbers : \n",n);
 for (int i=0; i<n; i++ )
  {
   printf("Enter the %d number ",i+1);
   scanf("%f",&data[i]);
  }
 max=(data[0]+data[1]+data[2])/3;
 element=data[1];
 position=2;
 for (i=2; i<(n-1); i++)
  {
   averange=(data[i]+data[i-1]+data[i+1])/3;
   if (averange>max)
    {
     max=averange;
     position=i+1;
     element=data[i];
    }
  }
 printf("\nThe maximal averange is %0.3f\n",max);
 printf("of the element %.3f in %d position ",element,position);
 getch();
}