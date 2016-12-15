#include <stdio.h>
#include <conio.h>
void romb(int n)
 {
  for (int i=0; i<(n-1)*3; i++ )
   printf(" ");
  printf("1\n");
  for (i=1; i<n; i++)
   {
    for (int j=0; j<3*(n-i-1); j++)
     printf(" ");
    printf("%d",i+1);
    for (j=1; j<6*i; j++)
     printf(" ");
    printf("%d\n",i+1);
   }
  for (i=(n-1); i>1; i--)
   {
    for (int j=0; j<3*(n-i); j++)
     printf(" ");
    printf("%d",i);
    for (j=1; j<6*(i-1); j++)
     printf(" ");
    printf("%d\n",i);
   }
  for (i=0; i<(n-1)*3; i++ )
   printf(" ");
  printf("1\n");
 }
void main()
 {
  int n;
  clrscr();
  printf("Enter a number : ");
  scanf("%d",&n);
  puts("");
  romb(n-1);
  getch();
 }

