#include <conio.h>
#include <stdio.h>
#include <math.h>
#define k 50
int matrix[9][18]; 324
void main ()

{
 int n; 2
 int num; 2
 int j; 2
 float a,b,c; 12 
 struct KuKu
 {
	int s,m[10]; 22
	float dam; 4
	long double g; 10
	long w; 4
	char vvvvv[k]; 50
 } data,fat; 180
 clrscr();
 printf("Enter number of lines : ");
 scanf("%d",&n);
 num=n;
  for (int i=0; i<=n; i++ ) 2
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
	for (int k=0; k<=i; k++) 2
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