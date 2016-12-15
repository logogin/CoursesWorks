#include <conio.h>
#include <stdio.h>
#include <math.h>
int matrix[9][18];
void main ()

{
 int n;
 int num;
 int j;
 clrscr();
 printf("Enter number of lines : ");
 scanf("%d",&n);
 num=n;
  for (int i=0; i<=n; i++ )
  {
   for (j=(num*2-1); j>=1; j--)
	 {
		matrix[i][(num*2-1)-j]=abs(j-num)+1;
	 }
	num--;
	}
  num=0;

for (i=n-1; i>=0; i--)
   {
	for (int k=0; k<=i; k++)
	   printf(" ");
	 for (j=0; j<=num; j++)
	 {

	  printf("%d",matrix[i][j]);
	 }
	puts("");
	num+=2;
	}
puts("");
for (i=0; i<n; i++)
 {
 for (j=0; j<n*2; j++)
	printf("%d",matrix[i][j]);
  puts("");
  }
	getch();
}